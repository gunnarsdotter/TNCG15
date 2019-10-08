#pragma once
#include "glm.hpp"
#include "Pixel.h"

const int SIZE = 800 * 800;
class Camera
{
public:
	Camera(glm::vec4 upleftcorner, glm::vec4 uprightcorner, glm::vec4 downleftcorner, glm::vec4 downrightcorner)
		:v1{ upleftcorner }, v2{ uprightcorner }, v3{ downleftcorner }, v4{ downrightcorner }
	{
		
		pos1 = true;
	};
	virtual ~Camera();
	//switch eye func

	//Render
	//Lanch a ray from each pixle radiance lec 4 &5
	//Test by assining the first hit the color to the ray.
	glm::vec4 v1, v2, v3, v4;
	//eye position
	glm::vec4 eye1 = glm::vec4(-2, 0, 0, 1);
	glm::vec4 eye2 = glm::vec4(-1, 0, 0, 1);
	bool pos1; 
	// Pixel 2D array 800x800 
	
	Pixel pixels[SIZE];
	
};

