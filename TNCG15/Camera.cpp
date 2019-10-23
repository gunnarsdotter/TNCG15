#include "Camera.h"

//switch eye func
void Camera::switchEye() {
	pos1 = !pos1;
	getEye();
}
//choose eye point
void Camera::getEye() {
	if (pos1) { eye = eye1; }
	else { eye = eye2; }
}


void Camera::createPixels() {
	//skapa pixel 
	for (int j = 0; j < SIZE; j++) { //vertical
		for (int i = 0; i < SIZE; i++) { //horizontell
			pixels[i][j] = new Pixel(ColorDbl(0, 0, 0), nullptr);
		}
	}
}
//Render
//Lanch a ray from each pixle radiance lec 4 &5
void Camera::render(Scene* s) {
	for (int j = 0; j < SIZE; j++) { //vertical
		for (int i = 0; i < SIZE; i++) { //horizontell
			//create a ray glm::vec4(0, i*delta - 0.99875, j*delta - 0.99875, 1)
			Ray *ray = new Ray(eye, glm::vec4(0, i*delta - 0.99875, j*delta - 0.99875, 1), ColorDbl(0, 0, 0));

			//finde intersection point
			s->intersection(ray);

			//add ray to pixel;
			pixels[i][j]->addRay(ray);
		}
		std::cout << "j= " << j << std::endl;
	}
};

void Camera::toImg() {
	double imax = findImax();

	FILE* image = fopen("file.ppm", "wb");
	fprintf(image, "P3 %d %d 255\n", SIZE, SIZE);
	if (image != NULL) {
		for (int j = 0; j < SIZE; j++) { //vertical
			for (int i = 0; i < SIZE; i++) { //horizontell
				//get the color
				ColorDbl col = (*pixels[SIZE - i - 1][SIZE - 1 - j]).getColor();
				//the scene is well-lit everywhere 
				fprintf(image, "%d %d %d ",
					(int)(col.color.r * 255.99/imax),
					(int)(col.color.g * 255.99/imax),
					(int)(col.color.b * 255.99/imax)
				); 
				
				/* To get more dynamic when we have bright spots in the scene
				#include <math.h>
					fprintf(image, "%d %d %d ",
					(int)(sqrt(col.color.r) 255.99/imax),
					(int)(sqrt(col.color.g) * 255.99/imax),
					(int)(sqrt(col.color.b) * 255.99/imax)

				*/
			}
		}
		fclose(image);
	}
}
double Camera::findImax() {
	double imax = 0;
	for (int j = 0; j < SIZE; j++) { //vertical
		for (int i = 0; i < SIZE; i++) { //horizontell
			//get the color
			ColorDbl col = (*pixels[SIZE - i - 1][SIZE - 1 - j]).getColor();
			if (col.color.r > imax) {
				imax = col.color.r;
			}
			if (col.color.g > imax) {
				imax = col.color.g;
			}
			if (col.color.b > imax) {
				imax = col.color.b;
			}
		}
	}
	return imax;
}
