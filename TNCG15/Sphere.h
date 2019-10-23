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

	void Sphere::calculateNormal(glm::vec3* x)
	{
		//TODO
		//return glm::normalize(x - glm::vec3(position));
	};

	double radius;
	glm::vec4 center;
	ColorDbl color;
};

