#include "Sphere.h"

Sphere::~Sphere()
{
}

bool Sphere::rayIntersection(Ray* arg, glm::vec3* x, double* t) {
	glm::vec3 rayDirection = glm::normalize(arg->direction);
	glm::vec3 L = glm::vec3(center - arg->start);

	//Project the viwedirection on the ray direction. 
	float tca = glm::dot(L, rayDirection);

	//needs to be posetive to be infront of the eye
	if (tca < 0)
		return false;

	float d2 = glm::dot(L, L) - tca * tca;

	float radius2 = radius * radius;
	//d2 can not be larger then radius2 for the sqrt
	// if larger the ray misset the sphere
	if (d2 > radius2)
		return false;

	//calculate the intersectionpoints.
	float thc = glm::sqrt(radius2 - d2);
	float t0 = tca - thc;
	float t1 = tca + thc;
	//Swap to test the smallest t first
	if (t0 > t1)
		std::swap(t0, t1);
	//check if t is not negative 
	if (t0 < 0) {
		t0 = t1; // if t0 is negative, let's use t1 instead
		if (t0 < 0)
			return  false; // both t0 and t1 are negative
	}
	*t = t0;
	//add the intersection point to x t0 is importent
	x->x = arg->start.x + glm::vec4(rayDirection * t0, 1.0f).x;
	x->y = arg->start.y + glm::vec4(rayDirection * t0, 1.0f).y;
	x->z = arg->start.z + glm::vec4(rayDirection * t0, 1.0f).z;

	return true;
}