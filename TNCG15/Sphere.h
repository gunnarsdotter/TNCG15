#pragma once
#include <iostream>
#include "glm.hpp"
#include "Ray.h"
class Sphere
{
public:
	Sphere(double r, glm::vec3 c, glm::vec3 col, int t) :
		radius{ r }, center{ c }, color{ col }, surfaceType{ t }{};
	virtual ~Sphere();

	bool rayIntersection(Ray* arg, glm::vec3* x, double* t);

	int getSurfaceType() { return surfaceType; };
	glm::vec3 getColor() { return color; };


	glm::vec3 calcNormal(glm::vec3 Phit)
	{
		return glm::normalize(Phit - glm::vec3(center));
	};

	double radius;
	glm::vec3 center;
	glm::vec3 color;
	int surfaceType;
};

