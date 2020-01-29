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

	float tmp = glm::dot(P, E1);

	float t = glm::dot(Q, E2) / tmp;
	float u = glm::dot(P, T) / tmp;
	float v = glm::dot(Q, D) / tmp;

	


	if ((u >= 0 && v >= 0 && u + v <= 1 )) {
		*it = t;
		glm::vec4 temp = glm::vec4(arg->getDirection() * t, 1.0f);
		intPoint->x = arg->start.x + temp.x;
		intPoint->y = arg->start.y + temp.y;
		intPoint->z = arg->start.z + temp.z;
		return true;
	}
	else return false;
}
/*
bool Triangle::rayIntersection(Ray* arg, glm::vec3* intPoint, double* it)
{
	const float EPSILON = 0.0000001;
	glm::vec3 E1 = v2 - v1;
	glm::vec3 E2 = v3 - v1;

	glm::vec3 D = arg->getDirection();
	glm::vec3 h = glm::cross(glm::vec3(D), glm::vec3(E2));

	float a = glm::dot(h, E1);
	if (a > -EPSILON && a < EPSILON)
		return false;

	float f = 1.0 / a;
	glm::vec3 s = arg->start - v1;

	float u = f * glm::dot(s, h);

	if (u < 0.0 || u > 1.0)
		return false;

	glm::vec3 q = glm::cross(s, E1);
	float v = f * glm::dot(D, q);

	if (v < 0.0 || u + v > 1.0)
		return false;

	float t = f * glm::dot(E2, q);
	if (t > EPSILON&& t < 1 / EPSILON) { // ray intersection
		*it = t;
		intPoint->x = arg->start.x + glm::vec4(arg->getDirection() * t, 1.0f).x;
		intPoint->y = arg->start.y + glm::vec4(arg->getDirection() * t, 1.0f).y;
		intPoint->z = arg->start.z + glm::vec4(arg->getDirection() * t, 1.0f).z;
		return true;
	}
	else return false;
}
*/