#pragma once
#include <iostream>
#include "glm.hpp"
#include "Ray.h"
#include "ColorDbl.h"
class Sphere
{
public:
	Sphere(double r, glm::vec4 c, ColorDbl col);
	virtual ~Sphere();

	bool rayIntersection(Ray* arg, glm::vec3* x);
	
	ColorDbl getColor() { return color; };
	
	double radius;
	glm::vec4 center;
	ColorDbl color;

	/*void Sphere::calculateNormal(glm::vec3 pHit)
	{
		normal = glm::normalize(pHit - glm::vec3(position));
	};

	Sphere::Sphere(glm::vec4 pos, float r, ColorDbl c) : position{ pos }, radius{ r }, color{ c }{
	};
	bool rayIntersection(Ray *r);*/
};

