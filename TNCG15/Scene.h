#pragma once

#include <vector>
#include "Triangle.h"
#include <iostream>



using namespace std;
class Scene
{
private:
	void createRoom();

	std::vector<Triangle*> triangles;
public:
	Scene();
	virtual ~Scene();

	void createTetrahedron();

		
	void intersection(Ray* arg) {
		for (auto it = triangles.begin(); it != triangles.end(); ++it) {
			if ((*(*it)).rayIntersection(arg)) {
				//it can only interact with one wall at the time.
				//break;
			}
		}
	}

};

