#include "Camera.h"
#include <random>
#include "gtx/rotate_vector.hpp"
#include "gtx\vector_angle.hpp"
#include "gtx\fast_trigonometry.hpp"
# define M_PI           3.14159265358979323846  /* pi */

//switch eye func
void Camera::switchEye() {
	pos1 = !pos1;
	getEye();
}
//choose eye point
void Camera::getEye() {
	if (pos1) { eye = eye1; }
	else { eye = eye2; }
}

void Camera::createPixels() {
	//skapa pixel 
	for (int j = 0; j < SIZE; j++) { //vertical
		for (int i = 0; i < SIZE; i++) { //horizontell
			pixels[i][j] = glm::vec3(0, 0, 0);
		}
	}
}
void createCoordinateSystem(const glm::vec3& N, glm::vec3& Nt, glm::vec3& Nb)
{
	if (std::fabs(N.x) > std::fabs(N.y))
		Nt = glm::vec3(N.z, 0, -N.x) / sqrtf(N.x * N.x + N.z * N.z);
	else
		Nt = glm::vec3(0, -N.z, N.y) / sqrtf(N.y * N.y + N.z * N.z);
	Nb = glm::cross(N, Nt);
}

glm::vec3 uniformSampleHemisphere(const float& r1, const float& r2)
{
	// cos(theta) = u1 = y
	// cos^2(theta) + sin^2(theta) = 1 -> sin(theta) = srtf(1 - cos^2(theta))
	float sinTheta = sqrtf(1 - r1 * r1);
	float phi = 2 * M_PI * r2;
	float x = sinTheta * cosf(phi);
	float z = sinTheta * sinf(phi);
	return glm::vec3(x, r1, z);
}
//Render
//Lanch a ray from each pixle radiance lec 4 &5
void Camera::render(Scene* s) {
	glm::vec3 rcolor(0, 0, 0);
	int numSamples = 1; // samples per pixel
	std::cout << "Render: " << std::endl;

	for (int j = 0; j < SIZE; j++) { //vertical
		for (int i = 0; i < SIZE; i++) { //horizontell

			glm::vec3 color(0, 0, 0);

			for (int k = 0; k < numSamples; k++) {
				//create a ray
				Ray* ray = new Ray(eye, glm::vec4(0, i * delta - 0.99875, j * delta - 0.99875, 1), rcolor);
				color += castRay(ray, s, 1);
				delete ray;

			}
			color = color / (float)pow(numSamples, 1);
			//Cast a ray
			//castRay(ray, s);
			//ray->color = ColorDbl(color.x, color.y, color.z);
			//s->intersection(ray);
			//add ray to pixel;

			pixels[i][j] = color;
		}
		std::cout << j << std::endl;
	}
};

//get normal depending on type
void getNormal(Ray* ray, glm::vec3& normal, int& sType) {
	if (ray->T) {
		normal = ray->T->getNormal();
		sType = ray->T->getSurfaceType();
	}
	else if (ray->S) {
		normal = ray->S->calcNormal(ray->intersectionpoint);
		sType = ray->S->getSurfaceType();
	}
}
std::random_device gen;
std::uniform_real_distribution<> distribution(0, 1);//uniform distribution between 0 and 1

glm::vec3 Camera::indirectLight(Ray *ray, Scene *s, glm::vec3 normal, int bounce) {

	glm::vec3 indirectlight = glm::vec3(0.0, 0.0, 0.0);

	/// INDIRECT LIGHt not working
	/*
	glm::vec3 Nt, Nb;
	createCoordinateSystem(normal, Nt, Nb);
	float pdf = 1 / (2 * M_PI);

	double r1 = distribution(gen);
	double r2 = distribution(gen);

	glm::vec3 sample = uniformSampleHemisphere(r1, r2);
	glm::vec3 sampleWorld(
		sample.x * Nb.x + sample.y * normal.x + sample.z * Nt.x,
		sample.x * Nb.y + sample.y * normal.y + sample.z * Nt.y,
		sample.x * Nb.z + sample.y * normal.z + sample.z * Nt.z);
	// don't forget to divide by PDF and multiply by cos(theta)
	Ray* out = new Ray(ray->intersectionpoint + sampleWorld, sampleWorld, ray->color);

	indirectlight += (float)r1 * castRay(out, s, bounce + 1) / pdf;

	delete out;
	*/
	std::uniform_real_distribution<> angle(0, M_PI);//uniform distribution between 0 and 1


	double ioffset = glm::orientedAngle(glm::normalize(glm::vec2(normal.x, normal.z)),
		glm::normalize(glm::vec2(0.0, 1.0)));
	double aoffset = glm::orientedAngle(glm::normalize(glm::vec2(normal.x, normal.y)),
		glm::normalize(glm::vec2(0.0, 1.0)));
	
	double r1 = distribution(gen);
	double r2 = distribution(gen);
	double inc = acos(sqrt(r1));
	double azi = 2.0f*M_PI*r2;

	glm::vec3 rDirection = glm::vec3(glm::fastCos(azi + aoffset),
		glm::fastSin(azi + aoffset),
		glm::fastCos(inc + ioffset));
	
	Ray* out = new Ray(ray->intersectionpoint, ray->intersectionpoint + rDirection, glm::vec3(0.0,0.0,0.0));

	indirectlight += (float)r1 * castRay(out, s, bounce + 1);

	delete out;

	return indirectlight;
}
glm::vec3 Camera::directLight(Ray *ray, Scene *s, glm::vec3 normal) {
	glm::vec3 directlight = glm::vec3(0.0, 0.0, 0.0);

	/// DIRECT LIGHt
	glm::vec3 lightDirection = s->getPointOnLightSource() - ray->intersectionpoint;
	float ldist = glm::length(lightDirection);
	lightDirection /= ldist;
	ldist = sqrt(ldist);
	//float ldist = sqrt(lightDirection.x*lightDirection.x+ lightDirection.y * lightDirection.y+ lightDirection.z * lightDirection.z);
	//lightDirection.x /= ldist, lightDirection.y /= ldist, lightDirection.z /= ldist;
	float NdotL = std::max(0.0f, glm::dot(lightDirection, normal));
	glm::vec3 intensity = glm::vec3(1.0, 1.0, 1.0)*NdotL;

	s->shadowRay(ray);

	directlight = ray->color * intensity / ldist;
	return directlight;
}


glm::vec3 Camera::castRay(Ray* ray, Scene* s, int bounce) {
	if (bounce > 3)return glm::vec3(0, 0, 0);
	int sType = 0;

	glm::vec3 normal;
	glm::vec3 iDirection = ray->getDirection();
	glm::vec3 rDirection;

	//get intersectionpoint
	s->intersection(ray);

	//get normal depending on objectType
	getNormal(ray, normal, sType);

	//choose the reflectans by the surfucetype.
	//calc light depending on surfacetype
	switch (sType) {
	case 1: { // Lambertian
		glm::vec3 light = glm::vec3(0.0, 0.0, 0.0);

		light += indirectLight(ray, s, normal, bounce);
		light += directLight(ray, s, normal);

		//std::cout << directlight.r << " " << directlight.g << " " << directlight.b  << std::endl;
		//return (directlight + indirectlight) / (float)M_PI;
		return (light) / (float)M_PI;

		break;
	}
	case 2: { // lightsource
		return glm::vec3(1.0, 1.0, 1.0);
		break;
	}
	case 3: { // Specular
		//send a shadow Ray
		s->shadowRay(ray);
		//Create a new ray 
		rDirection = iDirection - 2.0f * glm::dot(iDirection, normal) * normal;
		Ray* rRay = new Ray(glm::vec4(ray->intersectionpoint, 1), glm::vec4((ray->intersectionpoint + rDirection), 1), ray->color);
		//Cast the ray untill x bounces
		return castRay(rRay, s, bounce + 1);
		break;
		//if x bounces retrun color = color first.
	}
	default: break;
	}

	return glm::vec3(0, 0, 0);

}

void Camera::toImg() {
	double imax = findImax();
	cout << "this is imax " << imax << endl;

	FILE* image = fopen("file.ppm", "wb");
	fprintf(image, "P3 %d %d 255\n", SIZE, SIZE);
	if (image != NULL) {
		for (int j = 0; j < SIZE; j++) { //vertical
			for (int i = 0; i < SIZE; i++) { //horizontell
				//get the color
				glm::vec3 col = (pixels[SIZE - i - 1][SIZE - 1 - j]);
				//the scene is well-lit everywhere 
				fprintf(image, "%d %d %d ",
					(int)(col.r * 255.99 / imax),
					(int)(col.g * 255.99 / imax),
					(int)(col.b * 255.99 / imax)
				);

				/* To get more dynamic when we have bright spots in the scene
				#include <math.h>
					fprintf(image, "%d %d %d ",
					(int)(sqrt(col.color.r) 255.99/imax),
					(int)(sqrt(col.color.g) * 255.99/imax),
					(int)(sqrt(col.color.b) * 255.99/imax)

				*/
			}
		}
		fclose(image);
	}
}

double Camera::findImax() {
	double imax = 0;
	for (int j = 0; j < SIZE; j++) { //vertical
		for (int i = 0; i < SIZE; i++) { //horizontell
			//get the color
			glm::vec3 col = (pixels[SIZE - i - 1][SIZE - 1 - j]);
			if (col.r > imax) {
				imax = col.r;
			}
			if (col.g > imax) {
				imax = col.g;
			}
			if (col.b > imax) {
				imax = col.b;
			}
		}
	}
	return imax;
}
