#include "Scene.h"

Scene::Scene()
{
	light = glm::vec3(0, 0, 0);
	createTetrahedron();
	//createSphere();
	createSquareRoom();
	//createRoom();	
	spheres.push_back(new Sphere(2.0, glm::vec4(8, -3.5, -2, 1), glm::vec3(1.0, 1.0, 1.0), 3));
	//createSphereRoom();
	CreateLightSource(glm::vec3(7.0, 0.0, 4.9));
}
void Scene::createSphereRoom() {
	spheres.push_back(new Sphere(100000.0, glm::vec4(100010.0,0.0,0.0, 1), glm::vec3(1.0, 1.0, 1.0), 1));
	spheres.push_back(new Sphere(100000.0, glm::vec4(5.0,100006.0,0.0, 1), glm::vec3(1.0, 0.0, 0.0), 1));
	spheres.push_back(new Sphere(100000.0, glm::vec4(5.0, -100006.0, 0.0, 1), glm::vec3(0.0, 0.0, 1.0), 1));

	spheres.push_back(new Sphere(100000.0, glm::vec4(5.0, 0.0,-100006.0, 1), glm::vec3(1.0, 1.0, 1.0), 1));
	spheres.push_back(new Sphere(100000.0, glm::vec4(5.0, 0.0,100006.0, 1), glm::vec3(1.0, 1.0, 1.0), 1));


}
Scene::~Scene()
{
}

void Scene::CreateLightSource(glm::vec3 in) {

	if (in == glm::vec3(0.0f, 0.0f, 0.0f)) {
		glm::vec3 white = glm::vec3(1.0, 1.0, 1.0);

		glm::vec3 a = glm::vec3(6.0, 1.0, 4.9);
		glm::vec3 b = glm::vec3(8.0, 1.0, 4.9);
		glm::vec3 c = glm::vec3(6.0, -1.0, 4.9);
		glm::vec3 d = glm::vec3(8.0, -1.0, 4.9);

		lights.push_back(new Triangle(a, b, c, white, 2));
		lights.push_back(new Triangle(b, c, d, white, 2));
	}else
		light = in;
}

void Scene::createTetrahedron()
{
	//vertices
	glm::vec4 a = glm::vec4(7.0, 0.0, -2.0, 1);
	glm::vec4 b = glm::vec4(9.0, 2.0, -2.0, 1);
	glm::vec4 c = glm::vec4(9.0, -2.0, -2.0, 1);
	glm::vec4 d = glm::vec4(8.0, 0.0, 0.0, 1);

	glm::vec3 lightblue = glm::vec3(0.54, 0.82, 1.0);

	triangles.push_back(new Triangle(b, a, d, lightblue, 1));
	triangles.push_back(new Triangle(a, c, d, lightblue, 1));
	triangles.push_back(new Triangle(a, b, c, lightblue, 1));
	triangles.push_back(new Triangle(c, b, d, lightblue, 1));
}

void Scene::intersection(Ray* arg)
{
	glm::vec3 hitpoint = glm::vec3(0, 0, 0);
	double t = 0;
	for (auto it = triangles.begin(); it != triangles.end(); ++it) {
		if ((*(*it)).rayIntersection(arg, &hitpoint, &t)) {
			if (t > 1 && (arg->t == NULL || arg->t > t)) {
				//std::cout <<  arg->t << "    ---------" << endl;
				//std::cout << t << "    " << arg->t << endl;
				//set intersection point in the ray.
				arg->setTriangle(*it, hitpoint, (*it)->getColor(), t);
				arg->S = nullptr; //to choose the right normal.
			}
		}
	}
	for (auto it = spheres.begin(); it != spheres.end(); ++it) {
		if ((*(*it)).rayIntersection(arg, &hitpoint, &t)) {
			//std::cout << t << "    " << arg->t << endl;
			//check if the previus intersectionpoint is infront of the sphere.
			if (t > 0.5 && (arg->t == NULL || arg->t > t)) {
				//std::cout << t << "    " << arg->t << endl;

				//set intersection point in the ray.
				arg->setSphere(*it, hitpoint, (*it)->getColor(), t);
				arg->T = nullptr; //to choose the right normal.
			}
		}
	}
	for (auto it = lights.begin(); it != lights.end(); ++it) {
		if ((*(*it)).rayIntersection(arg, &hitpoint, &t)) {
			if (t > 1 && (arg->t == NULL || arg->t > t)) {
				//set intersection point in the ray.
				arg->setTriangle(*it, hitpoint, (*it)->getColor(), t);
				arg->S = nullptr; //to choose the right normal.
			}
		}
	}
}

glm::vec3 Scene::getPointOnLightSource()
{
	//select point light if defined
	if (light != glm::vec3(0, 0, 0))
		return light;
	float random = glm::clamp((float)std::rand() / RAND_MAX, 0.01f, 0.99f);
	float u = random / ((std::rand() % 8) + 2.0);
	float v = random - u;
	float w = 1 - u - v;

	int r = (double)rand() / RAND_MAX;

	Triangle* p = lights[r];
	glm::vec3 point = glm::vec3((u * p->v1 + v * p->v2 + w * p->v3));
	return point;

}

void Scene::shadowRay(Ray* ray) {

	glm::vec3 l = getPointOnLightSource();
	Ray sRay = Ray(
		glm::vec4(ray->intersectionpoint, 1), l, glm::vec3(0.0, 0.0, 0.0));
	glm::vec3 hitpoint = glm::vec3(0, 0, 0);
	double t = NULL;


	for (auto it = triangles.begin(); it != triangles.end(); ++it) {
		if ((*(*it)).rayIntersection(&sRay, &hitpoint, &t)) {
			//check that the object is between the light and intPoint
			if (t > 0.0001 && t < 1) {
				//set color black, in the shadow
				//TODO something else
				ray->color = sRay.color;
				break;
			}
		}
	}
	for (auto it = spheres.begin(); it != spheres.end(); ++it) {
		if ((*(*it)).rayIntersection(&sRay, &hitpoint, &t)) {
			//check that the object is between the light and intPoint
			if (t > 0.0001 && t < 1) {
				//set color black, in the shadow d
				//TODO something else
				ray->color = sRay.color;
				break;
			}
		}
	}
	for (auto it = lights.begin(); it != lights.end(); ++it) {
		if ((*(*it)).rayIntersection(&sRay, &hitpoint, &t)) {
			//check that the object is between the light and intPoint
			if (t > 0.0001 && t < 1) {
				//set color black, in the shadow
				//TODO something else
				ray->color = sRay.color;
				break;
			}
		}
	}
}
//Temporary for faster rendering
void Scene::createSquareRoom()
{
	glm::vec4 a = glm::vec4(-3.0, 6.0, 5.0, 1);
	glm::vec4 b = glm::vec4(13.0, 6.0, 5.0, 1);
	glm::vec4 c = glm::vec4(-3.0, -6.0, 5.0, 1);
	glm::vec4 d = glm::vec4(13.0, -6.0, 5.0, 1);
	glm::vec4 e = glm::vec4(-3.0, 6.0, -5.0, 1);
	glm::vec4 f = glm::vec4(13.0, 6.0, -5.0, 1);
	glm::vec4 g = glm::vec4(-3.0, -6.0, -5.0, 1);
	glm::vec4 h = glm::vec4(13.0, -6.0, -5.0, 1);


	glm::vec3 white = glm::vec3(1.0, 1.0, 1.0);
	glm::vec3 black = glm::vec3(0, 0, 0);
	glm::vec3 red = glm::vec3(1.0, 0.0, 0.0);
	glm::vec3 green = glm::vec3(0.0, 1.0, 0.0);
	glm::vec3 blue = glm::vec3(0.0, 0.0, 1.0);
	glm::vec3 magenta = glm::vec3(1.0, 0.0, 1.0);


	//roof
	triangles.push_back(new Triangle(a, b, c, white, 1));
	triangles.push_back(new Triangle(b, d, c, white, 1));
	//floor
	triangles.push_back(new Triangle(e, g, f, white, 1));
	triangles.push_back(new Triangle(f, g, h, white, 1));
	//wall
	triangles.push_back(new Triangle(a, e, f, red, 1));
	triangles.push_back(new Triangle(a, f, b, red, 1));

	triangles.push_back(new Triangle(b, f, h, white, 1));
	triangles.push_back(new Triangle(b, h, d, white, 1));

	triangles.push_back(new Triangle(c, h, g, blue, 1));
	triangles.push_back(new Triangle(c, d, h, blue, 1));

	triangles.push_back(new Triangle(a, c, e, black, 1));
	triangles.push_back(new Triangle(a, c, g, black, 1));
}
void Scene::createRoom()
{
	//vertices
	glm::vec4 a = glm::vec4(0.0, 6.0, 5.0, 1);
	glm::vec4 b = glm::vec4(10.0, 6.0, 5.0, 1);
	glm::vec4 c = glm::vec4(-3.0, 0.0, 5.0, 1);
	glm::vec4 d = glm::vec4(13.0, 0.0, 5.0, 1);
	glm::vec4 e = glm::vec4(0.0, -6.0, 5.0, 1);
	glm::vec4 f = glm::vec4(10.0, -6.0, 5.0, 1);
	glm::vec4 g = glm::vec4(0.0, 6.0, -5.0, 1);
	glm::vec4 h = glm::vec4(10.0, 6.0, -5.0, 1);
	glm::vec4 i = glm::vec4(-3.0, 0.0, -5.0, 1);
	glm::vec4 j = glm::vec4(13.0, 0.0, -5.0, 1);
	glm::vec4 k = glm::vec4(0.0, -6.0, -5.0, 1);
	glm::vec4 l = glm::vec4(10.0, -6.0, -5.0, 1);
	glm::vec4 m = glm::vec4(8.0, 0.0, 5.0, 1);
	glm::vec4 n = glm::vec4(8.0, 0.0, -5.0, 1);

	//color
	glm::vec3 white = glm::vec3(1.0, 1.0, 1.0);
	glm::vec3 black = glm::vec3(0, 0, 0);
	glm::vec3 red = glm::vec3(1.0, 0.0, 0.0);
	glm::vec3 green = glm::vec3(0.0, 1.0, 0.0);
	glm::vec3 blue = glm::vec3(0.0, 0.0, 1.0);
	glm::vec3 magenta = glm::vec3(1.0, 0.0, 1.0);
	glm::vec3 yellow = glm::vec3(1.0, 1.0, 0.0);
	glm::vec3 cyan = glm::vec3(0.0, 1.0, 1.0);


	//Add all triangles to the scen
	//Roof
	triangles.push_back(new Triangle(a, b, m, white, 1));
	triangles.push_back(new Triangle(b, d, m, white, 1));
	triangles.push_back(new Triangle(d, f, m, white, 1));
	triangles.push_back(new Triangle(f, e, m, white, 1));
	triangles.push_back(new Triangle(e, c, m, white, 1)); //??
	triangles.push_back(new Triangle(c, a, m, white, 1)); //??

	//Floor
	triangles.push_back(new Triangle(h, g, n, white, 1));
	triangles.push_back(new Triangle(j, h, n, white, 1));
	triangles.push_back(new Triangle(l, j, n, white, 1));
	triangles.push_back(new Triangle(k, l, n, white, 1));
	triangles.push_back(new Triangle(i, k, n, white, 1));
	triangles.push_back(new Triangle(g, i, n, white, 1));

	//Walls
	triangles.push_back(new Triangle(a, g, b, red, 1));
	triangles.push_back(new Triangle(h, b, g, red, 1));

	triangles.push_back(new Triangle(b, h, d, green, 1));
	triangles.push_back(new Triangle(j, d, h, green, 1));

	triangles.push_back(new Triangle(d, j, f, blue, 1));
	triangles.push_back(new Triangle(l, f, j, blue, 1));;

	triangles.push_back(new Triangle(f, l, e, magenta, 1));
	triangles.push_back(new Triangle(k, e, l, magenta, 1));

	triangles.push_back(new Triangle(e, k, c, yellow, 1));
	triangles.push_back(new Triangle(i, c, k, yellow, 1));

	triangles.push_back(new Triangle(c, i, a, cyan, 1));
	triangles.push_back(new Triangle(g, a, i, cyan, 1));

}
