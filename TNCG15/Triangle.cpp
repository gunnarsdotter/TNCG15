#include "Triangle.h"

using namespace std; 
bool Triangle::rayIntersection(Ray* arg, glm::vec3* intPoint, double* it)
{
	glm::vec3 T = arg->start - v1;
	glm::vec3 E1 = v2 - v1;
	glm::vec3 E2 = v3 - v1;
	glm::vec3 D = arg->getDirection();
	glm::vec3 P = glm::cross(glm::vec3(D), glm::vec3(E2));
	glm::vec3 Q = glm::cross(glm::vec3(T), glm::vec3(E1));

	float t = glm::dot(Q, E2) / glm::dot(P, E1);
	float u = glm::dot(P, T) / glm::dot(P, E1);
	float v = glm::dot(Q, D) / glm::dot(P, E1);
	
	if ((u >= 0 && v >= 0 && u + v <= 1 )) {
		*it = t;
		intPoint->x = arg->start.x + glm::vec4(arg->getDirection() * t, 1.0f).x;
		intPoint->y = arg->start.y + glm::vec4(arg->getDirection() * t, 1.0f).y;
		intPoint->z = arg->start.z + glm::vec4(arg->getDirection() * t, 1.0f).z;
		return true;
	}
	else return false;
}