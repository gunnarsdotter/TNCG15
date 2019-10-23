#pragma once
#include "ColorDbl.h"
#include "glm.hpp"
#include "Ray.h"
class Sphere
{

private:
	glm::vec4 position;
	glm::vec3 normal;
	float radius;
	ColorDbl color;
public:
	void Sphere::calculateNormal(glm::vec3 pHit)
	{
		normal = glm::normalize(pHit - glm::vec3(position));
	};

	Sphere::Sphere(glm::vec4 pos, float r, ColorDbl c) : position{ pos }, radius{ r }, color{ c }{
	};
	~Sphere() = default;

	glm::vec3 getNormal() { return normal; };
	ColorDbl getColor() { return color; };
	bool rayIntersection(Ray *r);

};

