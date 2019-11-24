#pragma once
#include "glm.hpp"
class Triangle;
class Sphere;


class Ray
{
public:
	Ray(glm::vec3 start, glm::vec3 end, glm::vec3 col) :
		start{ start }, end{ end }
	{
		direction = end - start;
		T = nullptr;
		S = nullptr;
		color = col;
		intersectionpoint = glm::vec3(NULL, NULL, NULL);
		t = NULL;
	};
	virtual ~Ray() = default;
	glm::vec3 getDirection() const;
	void setTriangle(Triangle* in, glm::vec3 inPoint, glm::vec3 col, double t);
	void setSphere(Sphere* in, glm::vec3 inPoint, glm::vec3 col, double t);


	glm::vec3 start, end;
	glm::vec3 direction, color;
	Triangle* T;
	Sphere* S;
	double t;
	glm::vec3 intersectionpoint;
};

