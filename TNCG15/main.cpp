#include <GLFW/glfw3.h>
#include "Scene.h"
#include "Camera.h"
#include <iostream>

using namespace std;

int main(void)
{
	//Surfaces
	// 0 nothing 
	// 1 lambertian
	// 2 Oye-nayar
	// 3 speculer
	// 4
	Scene* thescen = new Scene();
	cout << "Scen created" << endl;

	Camera* c = new Camera(glm::vec4(0, -1, -1, 1), glm::vec4(0, 1, -1, 1), glm::vec4(0, 1, 1, 1), glm::vec4(0, -1, 1, 1));
	cout << "Camera created"<< endl;

	c->switchEye();

	c->render(thescen);
	cout << "Camera renderd" << endl;

	c->toImg();
	cout << "Img done" << endl;

	return 0;
}