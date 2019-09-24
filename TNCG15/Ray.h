#pragma once
#include "Vertex.h"
#include "Triangle.h"
#include "ColorDbl.h"

class Ray
{
public:
	virtual ~Ray() = default;
	Ray(glm::vec4 start, glm::vec4 end, ColorDbl color):
		start{ start }, end{ end }, color{ color } {};
	glm::vec3 getDirection() {
		direction = start - end;
		return start - end;
	}
	//Vertex start, end;
	glm::vec4 start, end;
	ColorDbl color;
	glm::vec3 direction;
	//TODO-Raycontains a reference to the triangle on which theend point is located.
	//Triangle &t;
};

