#pragma once
#include "glm.hpp"
#include "Pixel.h"
#include "Ray.h"
#include "Scene.h"
#include <iostream>
#include <string>


const int SIZE = 800;
const double length = 0.0025;
class Camera
{
private:
	glm::vec4 v1, v2, v3, v4;
	//eye position variable
	glm::vec4 eye1 = glm::vec4(-2, 0, 0, 1);
	glm::vec4 eye2 = glm::vec4(-1, 0, 0, 1);
	bool pos1;
	//Camera variable
	double delta = 0.0025;
	double cameralength = 0.99875;
	glm::vec4 eye = eye1;
	// Pixel 2D array 800x800 
	Pixel* pixels[SIZE][SIZE];

	//choose eye point
	void getEye() {
		if (pos1) { eye = eye1; }
		else { eye = eye2; }
	}

	void createPixels() {
		//skapa pixel 
		for (int j = 0; j < SIZE; j++) { //vertical
			for (int i = 0; i < SIZE; i++) { //horizontell
				pixels[i][j] = new Pixel(ColorDbl(0, 0, 0), nullptr);
			}
		}
	}

public:
	Camera(glm::vec4 upleftcorner, glm::vec4 uprightcorner, glm::vec4 downleftcorner, glm::vec4 downrightcorner)
		:v1{ upleftcorner }, v2{ uprightcorner }, v3{ downleftcorner }, v4{ downrightcorner }
	{
		pos1 = true;
		createPixels();
	};

	 ~Camera() {
		 for (int j = 0; j < SIZE; j++) { //vertical
			 for (int i = 0; i < SIZE; i++) { //horizontell
				 delete pixels[i][j];
			 }
		 }
	}
	//switch eye func
	void switchEye() {
		pos1 = !pos1;
		getEye();
	}
	

	
	void toImg() {
		int a = (24, 24, 24);
		FILE* image = fopen("file.ppm", "wb");
		fprintf(image, "P3 %d %d 255\n", SIZE, SIZE);
		if (image != NULL) {
			for (int j = 0; j < SIZE; j++) { //vertical
				for (int i = 0; i < SIZE; i++) { //horizontell
					//get the color
					ColorDbl col = (*pixels[i][j]).getColor();
					//TODO - do the pixel to rgb 0-255 and print it
					fprintf(image, "%d %d %d ", 
							(int)col.color.r * 255,
							(int)col.color.g * 255,
							(int)col.color.b * 255
						);
					/*fprintf(image, (int)col.color.r + " ");
					fprintf(image, (int)col.color.g + " ");
					fprintf(image, (int)col.color.b + "\n");*/
				}
			}
			fclose(image);
		}
		
	}
	//Render
	//Lanch a ray from each pixle radiance lec 4 &5
	//launches a ray through each pixel one at a time
	void render(Scene* s) {
		for (int j = 0; j < SIZE; j++) { //vertical
			for (int i = 0; i < SIZE; i++) { //horizontell
				//create a ray glm::vec4(0, i*delta - 0.99875, j*delta - 0.99875, 1)
				Ray *ray = new Ray(eye, glm::vec4(0, i*delta - 0.99875, j*delta - 0.99875, 1), ColorDbl(0, 0, 0));
				
				//finde intersection point
				s->intersection(ray);	

				//add ray to pixel;
				pixels[i][j]->addRay(ray);
			}
		}
	};

};

