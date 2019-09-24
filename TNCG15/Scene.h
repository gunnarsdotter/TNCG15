#pragma once
#include <vector>
#include "Triangle.h"
#include "Vertex.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void createRoom();

	//It should have a method that determines which triangle is
	//intersected bytheRay argby calling successively 
	//therayIntersection(Ray arg)methodof eachTriangle. 
	//It then passes references to the triangle and 
	//theintersection point to theRay arg.
	
	std::vector<Triangle*>* triangles;
};

