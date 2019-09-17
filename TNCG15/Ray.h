#pragma once
#include "Vertex.h"
#include "Triangle.h"
#include "ColorDbl.h"
class Ray
{
public:
	Ray();
	virtual ~Ray();

	Vertex start, end;
	ColorDbl color;
	Triangle &t;
};

