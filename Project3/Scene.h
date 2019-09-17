#pragma once
#include <vector>
#include "Triangle.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	std::vector<Triangle> triangles;
};

