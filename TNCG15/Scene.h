#pragma once

#include <vector>
#include "Triangle.h"
#include "Sphere.h"
#include <iostream>



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
	
	void sphereIntersection(Ray* arg) {
		glm::vec3 intPoint = glm::vec3(0, 0, 0);
		for (auto it = spheres.begin(); it != spheres.end(); ++it) {
			if ((*it).rayIntersection(arg, &intPoint)) {
				//set intersection point in the ray.
				arg->intersectionpoint = intPoint;
				arg->color = (*it).color;
			}
		}
	}
		
	void intersection(Ray* arg) {
		glm::vec3 intPoint = glm::vec3(0, 0, 0);
		for (auto it = triangles.begin(); it != triangles.end(); ++it) {
			if ((*(*it)).rayIntersection(arg, &intPoint)) {
				//set intersection point in the ray.
				arg->setTriangle(*it, intPoint, (*it)->getColor());
			}
		}
	}

};

