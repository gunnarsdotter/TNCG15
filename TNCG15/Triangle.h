#pragma once
#include "Triangle.h"
#include "ColorDbl.h"
#include "glm.hpp"
#include "Ray.h"

class Triangle
{
public:
	Triangle() = delete;
	Triangle(glm::vec4 inV1, glm::vec4 inV2, glm::vec4 inV3, ColorDbl color) :
		v1{inV1 }, v2{ inV2 }, v3{ inV3 }, normal(calculateNormal(v1, v2, v3)), color{color}
	{};
	
	glm::vec3 calculateNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3){
		return glm::normalize(glm::cross(v2 - v1, v3 - v1));
	};

	//Computes the intersection point with Möller-Trumbore algorithm
	bool rayIntersection(Ray* arg, glm::vec3*intPoint);

	glm::vec3 getNormal() { return normal; };
	ColorDbl getColor() {return color;};
	virtual ~Triangle() = default;

private:
	glm::vec4 v1, v2, v3;
	glm::vec3 normal;
	ColorDbl color;
};

