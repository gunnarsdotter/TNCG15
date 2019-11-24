#pragma once
#include "Triangle.h"
#include "glm.hpp"
#include "Ray.h"

class Triangle
{
public:
	Triangle() = delete;
	Triangle(glm::vec3 inV1, glm::vec3 inV2, glm::vec3 inV3, glm::vec3 color, int t) :
		v1{ inV1 }, v2{ inV2 }, v3{ inV3 }, color{ color }, surfaceType{ t }
	{
		normal = glm::normalize(glm::cross(inV2 - inV1, inV3 - inV1));

	};

	glm::vec3 calculateNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3) {
		return glm::normalize(glm::cross(v2 - v1, v3 - v1));
	};

	//Computes the intersection point with Möller-Trumbore algorithm
	bool rayIntersection(Ray* arg, glm::vec3* intPoint, double* it);

	int getSurfaceType() { return surfaceType; };
	glm::vec3 getNormal() { return normal; };
	glm::vec3 getColor() { return color; };
	virtual ~Triangle() = default;

	glm::vec3 v1, v2, v3;

private:
	glm::vec3 normal;
	glm::vec3 color;
	int surfaceType;
};

