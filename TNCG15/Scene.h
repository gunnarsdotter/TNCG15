#pragma once
#include <vector>
#include "Triangle.h"
#include "Camera.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	

	//It should have a method that determines which triangle is
	//intersected by the Ray arg by calling successively 
	//the rayIntersection(Ray arg) method of each Triangle. 
	//It then passes references to the triangle and
	//the intersection point to theRay arg.
	//void something(Ray arg) {
	//	for (auto it = triangles->begin; it != triangles->end; ++it) {
	//		if (*it->rayIntersection(arg)) {
	//			//it is a hit.
	//			arg.setTriangel(*it);
	//		}
	//	}

	//}

private: 
	void createRoom();
	Camera* c; 
	std::vector<Triangle*>* triangles;
};

