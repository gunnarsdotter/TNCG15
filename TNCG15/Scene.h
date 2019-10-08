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

	

	//It should have a method that determines which triangle is
	//intersected by the Ray arg by calling successively 
	//the rayIntersection(Ray arg) method of each Triangle. 
	//It then passes references to the triangle and
	//the intersection point to theRay arg.
	void something(Ray* arg) {
		for (auto it = triangles.begin(); it != triangles.end(); ++it) {
			if ((*(*it)).rayIntersection(arg)) {
				cout <<  "yes"<< endl;
				
			}
			
			//if ()  //*it.rayIntersection(arg)) {
			//	//it is a hit.
			//	//arg->setTriangel(*it);
			//	break;
			//}
		}

	}

};

