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
	void createSquareRoom();
	void createRoom();

	std::vector<Triangle*> triangles;
	std::vector<Triangle*> lights;

	std::vector<Sphere*> spheres;

	glm::vec3 light;

public:
	Scene();
	void createSphereRoom();
	virtual ~Scene();

	void CreateLightSource();
	void createTetrahedron();
	void intersection(Ray* arg);
	glm::vec3 getPointOnLightSource();

	void shadowRay(Ray* ray);
};

