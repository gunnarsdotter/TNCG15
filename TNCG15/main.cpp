#include <GLFW/glfw3.h>
#include "Scene.h"
#include "Camera.h"
#include <iostream>

using namespace std;

int main(void)
{
	//GLFWwindow* window;
	Scene* thescen = new Scene();
	cout << "Scen created" << endl;

	Camera* c = new Camera(glm::vec4(0, -1, -1, 1), glm::vec4(0, 1, -1, 1), glm::vec4(0, 1, 1, 1), glm::vec4(0, -1, 1, 1));
	cout << "Camera created"<< endl;

	c->switchEye();

	c->render(thescen);
	cout << "Camera renderd" << endl;

	c->toImg();
	cout << "Img done" << endl;

	///* Initialize the library */
	//if (!glfwInit())
	//	return -1;

	///* Create a windowed mode window and its OpenGL context */
	//window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	//if (!window)
	//{
	//	glfwTerminate();
	//	return -1;
	//}

	///* Make the window's context current */
	//glfwMakeContextCurrent(window);

	///* Loop until the user closes the window */
	//while (!glfwWindowShouldClose(window))
	//{
	//	/* Render here */
	//	glClear(GL_COLOR_BUFFER_BIT);

	//	/* Swap front and back buffers */
	//	glfwSwapBuffers(window);

	//	/* Poll for and process events */
	//	glfwPollEvents();
	//}

	//glfwTerminate();
	return 0;
}