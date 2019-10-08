#include "Triangle.h"


bool Triangle::rayIntersection(Ray arg)
{
	glm::vec3 T = arg.start - v1;
	glm::vec3 E1 = v2 - v1;
	glm::vec3 E2 = v3 - v1;
	glm::vec3 D = arg.getDirection();
	glm::vec3 P = glm::cross(glm::vec3(D), glm::vec3(E2));
	glm::vec3 Q = glm::cross(glm::vec3(T), glm::vec3(E1));

	float t = glm::dot(Q, E2) / glm::dot(P, E1);
	float u = glm::dot(P, T) / glm::dot(P, E1);
	float v = glm::dot(Q, D) / glm::dot(P, E1);

	if (u >= 0 && v >= 0 && u + v <= 1)return true;
	else return false;
}
