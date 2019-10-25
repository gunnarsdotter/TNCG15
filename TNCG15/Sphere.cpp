#include "Sphere.h"

Sphere::~Sphere()
{
}

bool Sphere::rayIntersection(Ray* arg, glm::vec3* x) {
	glm::vec3 rayDirection = glm::normalize(arg->direction);
	glm::vec3 L = glm::vec3(center) - rayDirection;

	float tca = glm::dot(L, rayDirection);

	if (tca < 0)
		return false;

	float d2 = glm::dot(L, L) - tca * tca;

	float radius2 = radius * radius;

	if (d2 > radius2)
		return false;

	float thc = glm::sqrt(radius2 - d2);
	float t0 = tca - thc;
	float t1 = tca + thc;

	if (t0 > t1)
		std::swap(t0, t1);

	if (t0 < 0) {
		t0 = t1; // if t0 is negative, let's use t1 instead
		if (t0 < 0)
			return  false; // both t0 and t1 are negative
	}
	//t = t0;
	//add the intersection point to x
	x->x = arg->start.x + glm::vec4(rayDirection * t0, 1.0f).x;
	x->y = arg->start.y + glm::vec4(rayDirection * t0, 1.0f).y;
	x->z = arg->start.z + glm::vec4(rayDirection * t0, 1.0f).z;
	
	return true;
}

/*  BORT ???		
	glm::vec4 viewdir = arg->start - center;
	double b = 2 * glm::dot(glm::normalize(arg->direction), glm::vec3(viewdir));
	double c = glm::dot(viewdir, viewdir) - pow(radius, 2);
	if (c < pow((b / 2), 2)) {
		double d1 = -(b / 2) + sqrt(pow((b / 2), 2) - c);
		double d2 = -(b / 2) - sqrt(pow((b / 2), 2) - c);
		double d = 0;

		if (d1 < d2)	d = d1;
		else d = d2;
		x->x = arg->start.x + d * glm::normalize(arg->direction).x;
		x->y = arg->start.y + d * glm::normalize(arg->direction).y;
		x->z = arg->start.z + d * glm::normalize(arg->direction).z;
		return true;
	}
	return false;


bool Sphere::rayIntersection(Ray *r) {

	glm::vec3 rayDirection = glm::normalize(glm::vec3(r->end - r->start));
	glm::vec3 L = glm::vec3(position) - rayDirection;

	float tca = glm::dot(L, rayDirection);

	if (tca < 0)
		return false;

	float d2 = glm::dot(L,L) - tca*tca;

	float radius2 = radius*radius;

	if (d2 > radius2)
		return false;

	float thc = glm::sqrt(radius2 - d2);
	float t0 = tca - thc;
	float t1 = tca + thc;

	if 	(t0 > t1)
		std::swap(t0, t1);

	if (t0 < 0) {
		t0 = t1; // if t0 is negative, let's use t1 instead
		if (t0 < 0)
			return  false; // both t0 and t1 are negative
	}

	//t = t0;

	glm::vec4 hitPoint = r->start + glm::vec4(rayDirection * t0, 1.0f);

	calculateNormal(glm::vec3(hitPoint));


	r->setSphere(this, glm::vec3(hitPoint), color);

	return true;

};
*/