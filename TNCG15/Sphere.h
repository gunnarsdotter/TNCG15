#pragma once
#include <iostream>
#include "glm.hpp"
#include "Ray.h"
#include "ColorDbl.h"
class Sphere
{
public:
	Sphere();
	Sphere(double r, glm::vec4 c, ColorDbl col);
	virtual ~Sphere();

	bool rayIntersection(Ray* arg, glm::vec3* x);

	double radius;
	glm::vec4 center;
	ColorDbl color;
};

