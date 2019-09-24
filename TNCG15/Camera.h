#pragma once
#include "Vertex.h"
#include "glm.hpp"
#include "Pixel.h"

const int SIZE = 800 * 800;
class Camera
{
public:
	Camera(glm::vec4 leftEye, glm::vec4 rightEye) :v1{ leftEye }, v2{ rightEye } {
		pos1 = true;
	};
	virtual ~Camera();

	glm::vec4 v1, v2;
	bool pos1; //eye position
	Pixel pixels[SIZE];
	// Pixel 2D array 800x800 
	//Vertex v1, v2, v3;
};

