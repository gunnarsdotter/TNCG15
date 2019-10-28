#pragma once
#include <iostream>
#include "glm.hpp"
#include "Ray.h"
#include "ColorDbl.h"
class Sphere
{
public:
	Sphere(double r, glm::vec4 c, ColorDbl col, int t):
		radius{ r }, center{ c }, color{ col }, surfaceType{ t }{};
	virtual ~Sphere();

	bool rayIntersection(Ray * arg, glm::vec3 * x, double * t);
	
	ColorDbl getColor() { return color; };
	int getSurfaceType() { return surfaceType; };

	glm::vec3 Sphere::calcNormal(glm::vec3 Phit)
	{
		return glm::normalize(Phit - glm::vec3(center));
	};

	double radius;
	glm::vec4 center;
	ColorDbl color;
	int surfaceType;
};

