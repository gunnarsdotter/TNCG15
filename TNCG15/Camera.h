#pragma once
#include "glm.hpp"
#include "Pixel.h"
#include "Ray.h"
#include "Scene.h"


const int SIZE = 800 * 800;
const float length = 0.0025;
class Camera
{
public:
	Camera(glm::vec4 upleftcorner, glm::vec4 uprightcorner, glm::vec4 downleftcorner, glm::vec4 downrightcorner)
		:v1{ upleftcorner }, v2{ uprightcorner }, v3{ downleftcorner }, v4{ downrightcorner }
	{
		pos1 = true;
		//create pixles?
	};
	virtual ~Camera();
	//switch eye func
	void switchEye() {pos1 = !pos1;}

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
	

	void createPixels() {
		//skapa pixel 
		//skapa en ray för varje med riktning från ögat till pixlen? 

	}
	//launches a ray through each pixel one at a time
	void render(Scene* s) {
		glm::vec4 eye;
		//choose eye point
		if (pos1) { eye = eye1; }
		else { eye = eye2; }
		

		//loop throw all pixels
			//create a ray 
			//with direction from the eye throw the pixel.  min value should be 17 enheter. 
			//pixelcoordinate (0, 1, 0);
			//End point (20, 20/cos(pi/4), 0 ) 
			//e + t((0, i·0.0025−0.99875, j·0.0025−0.99875)−e
		double i = 400;
		double j = 400;
			Ray *ray = new Ray(eye, glm::vec4(0, i*0.0025 - 0.99875, j*0.0025 - 0.99875, 1), ColorDbl(0, 0, 0));

			//add ray to pixel;
			//finde intersection point
			s->something(ray);



	};

};

