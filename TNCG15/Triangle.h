#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
class Triangle
{
public:
	Triangle() = delete;
	Triangle(Vertex* inV1, Vertex* inV2, Vertex* inV3) :
		v1(inV1), v2(inV2), v3(inV3)
	{//ColorDbl inColorcolor(inColor)
		//normal = countNormal();
	};
	Direction countNormal()
	{
		//Skapa en vektorer mellan punkterna
		//kryssprodukten mellan punkterna		
	};
	virtual ~Triangle();

	Vertex* v1;
	Vertex* v2;
	Vertex* v3;
	ColorDbl color;
	Direction normal;
};

