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

	std::vector<Triangle*>* triangles;
};

