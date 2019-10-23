#include "Sphere.h"





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