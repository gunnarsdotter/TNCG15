#pragma once

#include "ColorDbl.h"
class Triangle;

class Ray
{
public:
	Ray(glm::vec4 start, glm::vec4 end, ColorDbl color):
		start{ start }, end{ end }, color{ color } 
	{
		direction = end- start;
		T = nullptr;
		intersectionpoint = glm::vec3(NULL, NULL, NULL);
	};
	virtual ~Ray() = default;
	glm::vec3 getDirection() const;
	void setTriangle(Triangle* in, glm::vec3 inPoint, ColorDbl c); 


	glm::vec4 start, end;
	ColorDbl color;
	glm::vec3 direction;
	Triangle *T;
	glm::vec3 intersectionpoint;
};

