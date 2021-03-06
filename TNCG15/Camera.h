﻿#pragma warning (disable : 4996)
#include "glm.hpp"
#include "Ray.h"
#include "Scene.h"
#include <iostream>
#include <string>


const int SIZE = 800;

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
	glm::vec3 pixels[SIZE][SIZE];
	void getEye();
	void createPixels();
	double findImax();

public:
	Camera(glm::vec4 upleftcorner, glm::vec4 uprightcorner, glm::vec4 downleftcorner, glm::vec4 downrightcorner)
		:v1{ upleftcorner }, v2{ uprightcorner }, v3{ downleftcorner }, v4{ downrightcorner }
	{
		pos1 = true;
		getEye();
		createPixels();
	};

	~Camera() {
	}

	void switchEye();
	void render(Scene* s);
	glm::vec3 indirectLight(Ray * ray, Scene * s, glm::vec3 normal, int bounce);
	glm::vec3 directLight(Ray * ray, Scene * s, glm::vec3 normal);
	glm::vec3 castRay(Ray* arg, Scene* s, int bounce);
	void toImg();
};

