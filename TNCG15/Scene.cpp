#include "Scene.h"

Scene::Scene()
{	
	light = glm::vec4(0, 0, 0, 1);
	createTetrahedron();
	//createSphere();
	createRoom();	
	Sphere sphere1(1.0, glm::vec4( 8, -3.5, -2, 1), ColorDbl(1.0, 0.0, 0.0), 3);
	spheres.push_back(sphere1);
	CreateLightSource();
}

Scene::~Scene()
{
}

void Scene::CreateLightSource() {
	/*double d = 4.0;
	//vertices
	glm::vec4 j = glm::vec4( 5.0 + (d / 2), (d / 2), 5.0, 1);
	glm::vec4 k = glm::vec4( 5.0 - (d / 2), (d / 2), 5.0, 1);
	glm::vec4 l = glm::vec4( 5.0 - (d / 2), -(d / 2), 5.0, 1);
	glm::vec4 m = glm::vec4( 5.0 + (d / 2), -(d / 2), 5.0, 1);

	ColorDbl white = ColorDbl(1.0, 1.0, 1.0);

	triangles.push_back(new Triangle(j, k, l, white,0));
	triangles.push_back(new Triangle(j, k, m, white,0));*/
	light = glm::vec4(5.0, 0, 4.9, 0);
}

void Scene::createTetrahedron()
{
	//vertices
	glm::vec4 a = glm::vec4( 7.0, 0.0, -2.0, 1);
	glm::vec4 b = glm::vec4( 9.0, 2.0, -2.0, 1);
	glm::vec4 c = glm::vec4( 9.0,-2.0, -2.0, 1);
	glm::vec4 d = glm::vec4( 8.0, 0.0,  0.0, 1);

	ColorDbl lightblue = ColorDbl(0.54, 0.82, 1.0);

	triangles.push_back(new Triangle(b, a, d, lightblue,3));
	triangles.push_back(new Triangle(a, c, d, lightblue,3));
	triangles.push_back(new Triangle(a, b, c, lightblue,3));
	triangles.push_back(new Triangle(c, b, d, lightblue,3));
}

void Scene::intersection(Ray* arg)
{
	glm::vec3 hitpoint = glm::vec3(0, 0, 0);
	double t = 0;
	for (auto it = triangles.begin(); it != triangles.end(); ++it) {
		if ((*(*it)).rayIntersection(arg, &hitpoint, &t)) {
			if (t > 1 && (arg->t == NULL || arg->t > t)) {
				//set intersection point in the ray.
				arg->setTriangle(*it, hitpoint, (*it)->getColor(), t);
				arg->S = nullptr; //to choose the right normal.
			}
		}
	}
	for (auto it = spheres.begin(); it != spheres.end(); ++it) {
		if ((*it).rayIntersection(arg, &hitpoint, &t)) {
			//check if the previus intersectionpoint is infront of the sphere.
			if (arg->t > 0.5 && arg->t > t) {
				//set intersection point in the ray.
				arg->setSphere(&(*it), hitpoint, (*it).color, t);
				arg->T = nullptr; //to choose the right normal.
			}
		}
	}
}

void Scene::shadowRay(Ray* ray) {
	Ray sRay = Ray(
		glm::vec4(ray->intersectionpoint.x, ray->intersectionpoint.y,
				  ray->intersectionpoint.z, 1), light, ColorDbl(0.2, 0.2, 0.2));
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
		if ((*it).rayIntersection(&sRay, &hitpoint, &t)) {
			//check that the object is between the light and intPoint
			if (t > 0) {
				//set color black, in the shadow d
				//TODO something else
				ray->color = sRay.color;
				break;
			}
		}
	}

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
	ColorDbl white   = ColorDbl(1.0, 1.0, 1.0);
	ColorDbl black   = ColorDbl(0, 0, 0);
	ColorDbl red     = ColorDbl(1.0, 0.0, 0.0);
	ColorDbl green   = ColorDbl(0.0, 1.0, 0.0);
	ColorDbl blue    = ColorDbl(0.0, 0.0, 1.0);
	ColorDbl magenta = ColorDbl(1.0, 0.0, 1.0);
	ColorDbl yellow	 = ColorDbl(1.0, 1.0, 0.0);
	ColorDbl cyan    = ColorDbl(0.0, 1.0, 1.0);


	//Add all triangles to the scen
	//Roof
	triangles.push_back(new Triangle(a,b,m, white,1));
	triangles.push_back(new Triangle(b,d,m, white, 1));
	triangles.push_back(new Triangle(d,f,m, white, 1));
	triangles.push_back(new Triangle(f,e,m, white, 1));
	triangles.push_back(new Triangle(e,c,m, white, 1)); //??
	triangles.push_back(new Triangle(c,a,m, white, 1)); //??

	//Floor
	triangles.push_back(new Triangle(h, g, n, white, 1));
	triangles.push_back(new Triangle(j, h, n, white, 1));
	triangles.push_back(new Triangle(l, j, n, white, 1));
	triangles.push_back(new Triangle(k, l, n, white, 1));
	triangles.push_back(new Triangle(i, k, n, white, 1));
	triangles.push_back(new Triangle(g, i, n, white, 1));

	//Walls
	triangles.push_back(new Triangle(a,g,b,red, 1));
	triangles.push_back(new Triangle(h,b,g,red, 1));

	triangles.push_back(new Triangle(b,h,d,green, 1));
	triangles.push_back(new Triangle(j,d,h,green, 1));

	triangles.push_back(new Triangle(d,j,f,blue, 1));
	triangles.push_back(new Triangle(l,f,j,blue, 1));;
	
	triangles.push_back(new Triangle(f,l,e,magenta, 1));
	triangles.push_back(new Triangle(k,e,l,magenta, 1));
	
	triangles.push_back(new Triangle(e,k,c,yellow, 1));
	triangles.push_back(new Triangle(i,c,k,yellow, 1));
	
	triangles.push_back(new Triangle(c,i,a,cyan, 1));
	triangles.push_back(new Triangle(g,a,i,cyan, 1));

}
