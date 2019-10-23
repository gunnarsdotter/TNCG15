#pragma once

#include <vector>
#include "Triangle.h"
#include <iostream>
#include "Sphere.h"


using namespace std;
class Scene
{
private:
	void createRoom();

	std::vector<Triangle*> triangles;
	std::vector<Sphere*> spheres;
	std::vector<Triangle*> tetrahedras;

public:
	Scene();
	virtual ~Scene();

	void createTetrahedron();
	void createSphere();

		
	void intersection(Ray* arg) {
		for (auto it = spheres.begin(); it != spheres.end(); ++it) {
			if ((*(*it)).rayIntersection(arg)) {
				//it can only interact with one wall at the time.
				//break;
			}
		}
		for (auto it = tetrahedras.begin(); it != tetrahedras.end(); ++it) {
			if ((*(*it)).rayIntersection(arg)) {
				//it can only interact with one wall at the time.
				//break;
			}
		}
		for (auto it = triangles.begin(); it != triangles.end(); ++it) {
			if ((*(*it)).rayIntersection(arg)) {
				//it can only interact with one wall at the time.
				//break;
			}
		}
	}

};

