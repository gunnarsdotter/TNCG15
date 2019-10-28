#include "Camera.h"
#include <random>
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
			pixels[i][j] = new Pixel(ColorDbl(0, 0, 0), nullptr);
		}
	}
}

//Render
//Lanch a ray from each pixle radiance lec 4 &5
void Camera::render(Scene* s) {
	std::cout << "Render: " << std::endl;
	for (int j = 0; j < SIZE; j++) { //vertical
		for (int i = 0; i < SIZE; i++) { //horizontell
			
			glm::vec3 color(0,0,0);
			//create a ray
			Ray *ray = new Ray(eye, glm::vec4(0, i*delta - 0.99875, j*delta - 0.99875, 1), ColorDbl(0, 0, 0));

			//Cast a ray
			//castRay(ray, s);
			castRay(ray, s, 1);
			//ray->color = ColorDbl(color.x, color.y, color.z);
			//s->intersection(ray);
			//add ray to pixel;
			pixels[i][j]->addRay(ray);
		}
	}
};

//get normal depending on type
void getNormal(Ray* ray, glm::vec3 &normal, int &sType) {
	if (ray->T) {
		normal = ray->T->getNormal();
		sType = ray->T->getSurfaceType();
	}
	else if (ray->S) {
		normal = ray->S->calcNormal(ray->intersectionpoint);
		sType = ray->S->getSurfaceType();
	}

}

//create local coordinate system
void createCoordinateSystem(const glm::vec3& N,	glm::vec3& Nt, glm::vec3& Nb)
{
	if (std::fabs(N.x) > std::fabs(N.y))
		Nt = glm::vec3(N.z, 0, -N.x) / sqrtf(N.x * N.x + N.z * N.z);
	else
		Nt = glm::vec3(0, -N.z, N.y) / sqrtf(N.y * N.y + N.z * N.z);
	Nb = glm::cross(N,Nt);
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

void Camera::castRay(Ray* ray, Scene *s, int bounce) {
	if (bounce > 3)return;
		int sType = 0;

		glm::vec3 normal;
		glm::vec3 iDirection = ray->getDirection();
		glm::vec3 rDirection;

		//get intersectionpoint
		s->intersection(ray);

		//send a shadow Ray
		s->shadowRay(ray);

		//get normal depending on objectType
		getNormal(ray, normal, sType);

		//choose the reflectans by the surfucetype.
		//calc light depending on surfacetype
		
		switch (sType) {
		case 1: { // Lambertian

			break;
		}
		case 3: { // Specular
			//Create a new ray 
			rDirection = iDirection - 2.0f*glm::dot(iDirection,normal)*normal;
			Ray *rRay = new Ray(glm::vec4(ray->intersectionpoint, 1), glm::vec4((ray->intersectionpoint + rDirection),1), ray->color);
			//Cast the ray untill x bounces
			castRay(rRay, s, bounce + 1);
			//if x bounces retrun color = color first.
			ray->color = rRay->color;

		}
		default: break;
		}


		//cast new ray med den reflecterande. 
		//???
//???
		/*
	const float EPSILON = 0.00001f;
	const int MAX_DEPTH = 1;

	//random gen
	std::default_random_engine generator;
	std::uniform_real_distribution<> distribution(0.0, 1.0);
	std::uniform_real_distribution<> disPi(0.0, M_PI);

	float r1,r2;
	float pdf = 1 / (2 * M_PI);

	int sType=0;
	int numSamples = 1;

	glm::vec3 normal, Nt, Nb, color(0,0,0);
	glm::vec3 iDirection = ray->getDirection();
	glm::vec4 rDirection;

	//get normal depending on objectType
	getNormal(ray, normal, sType);

	//calc light depending on surfacetype
	switch(sType){
	case 1: { // Lambertian

		createCoordinateSystem(normal, Nt, Nb);

		for (int i = 0; i < numSamples; i++) {
			r1 = distribution(generator);
			r2 = distribution(generator);
			glm::vec3 sample = uniformSampleHemisphere(r1, r2);
			rDirection = glm::vec4(
				sample.x * Nb.x + sample.y * normal.x + sample.z * Nt.x,
				sample.x * Nb.y + sample.y * normal.y + sample.z * Nt.y,
				sample.x * Nb.z + sample.y * normal.z + sample.z * Nt.z,1);
			
			Ray *rRay= new Ray(glm::vec4(ray->intersectionpoint, 1), rDirection, ColorDbl(0,0,0));
			
			//color += castRay(rRay,s);


		}
		//color = color / (float)numSamples;

		break;
	}
	case 3: { // Specular

		rDirection = glm::vec4(iDirection-normal*glm::dot(normal,iDirection),4);
		Ray *rRay= new Ray(glm::vec4(ray->intersectionpoint,1),rDirection,ray->color);
		//color += castRay(rRay, s);

	}
	default: break;
	}
	return ray->color.getColor();
	*/
}


void Camera::toImg() {
	double imax = findImax();

	FILE* image = fopen("file.ppm", "wb");
	fprintf(image, "P3 %d %d 255\n", SIZE, SIZE);
	if (image != NULL) {
		for (int j = 0; j < SIZE; j++) { //vertical
			for (int i = 0; i < SIZE; i++) { //horizontell
				//get the color
				ColorDbl col = (*pixels[SIZE - i - 1][SIZE - 1 - j]).getColor();
				//the scene is well-lit everywhere 
				fprintf(image, "%d %d %d ",
					(int)(col.color.r * 255.99/imax),
					(int)(col.color.g * 255.99/imax),
					(int)(col.color.b * 255.99/imax)
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
			ColorDbl col = (*pixels[SIZE - i - 1][SIZE - 1 - j]).getColor();
			if (col.color.r > imax) {
				imax = col.color.r;
			}
			if (col.color.g > imax) {
				imax = col.color.g;
			}
			if (col.color.b > imax) {
				imax = col.color.b;
			}
		}
	}
	return imax;
}
