#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
class Triangle
{
public:
	Triangle();
	virtual ~Triangle();

	Vertex v1, v2, v3;
	ColorDbl color;
	Direction normal;
};

