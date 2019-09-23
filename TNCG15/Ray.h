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

	//Vertex start, end;
	glm::vec4 start, end;
	ColorDbl color;
	//Triangle &t;
};

