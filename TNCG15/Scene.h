#pragma once

#include <vector>
#include "Triangle.h"
#include "Sphere.h"
#include <iostream>
#include "Sphere.h"


using namespace std;
class Scene
{
private:
	void createRoom();

	std::vector<Triangle*> triangles;
	std::vector<Sphere> spheres;

public:
	Scene();
	virtual ~Scene();

	void CreateLightSource();
	void createTetrahedron();
	glm::vec4 light;
	void intersection(Ray* arg);

	void shadowRay(Ray * ray);

};

