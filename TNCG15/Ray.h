#pragma once
#include "ColorDbl.h"
class Triangle;

class Ray
{
public:
	Ray(glm::vec4 start, glm::vec4 end, ColorDbl color):
		start{ start }, end{ end }, color{ color } 
	{
		direction = start - end;
		T = nullptr;
	};
	virtual ~Ray() = default;
	glm::vec3 getDirection() const{
		return direction;
	}
	void setTriangel(Triangle* in) {
		T = in;
		//point = inPoint;
	}

	glm::vec4 start, end;
	ColorDbl color;
	glm::vec3 direction;
	Triangle *T;
};

