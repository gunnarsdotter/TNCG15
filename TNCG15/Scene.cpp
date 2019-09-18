#include "Scene.h"



Scene::Scene()
{
	triangles = new std::vector<Triangle*>();
	createRoom();
}


Scene::~Scene()
{
}


void Scene::createRoom()
{
	//Create the room Vertices
	Vertex* a = new Vertex(0.0,  6.0,  5.0, 1);
	Vertex* b = new Vertex(10.0, 6.0,  5.0, 1);
	Vertex* c = new Vertex(-3.0, 0.0,  5.0, 1);
	Vertex* d = new Vertex(13.0, 0.0,  5.0, 1);
	Vertex* e = new Vertex(0.0, -6.0,  5.0, 1);
	Vertex* f = new Vertex(10.0,-6.0,  5.0, 1);
	Vertex* g = new Vertex(0.0,  6.0, -5.0, 1);
	Vertex* h = new Vertex(10.0, 6.0, -5.0, 1);
	Vertex* i = new Vertex(-3.0, 0.0, -5.0, 1);
	Vertex* j = new Vertex(13.0, 0.0, -5.0, 1);
	Vertex* k = new Vertex(0.0, -6.0, -5.0, 1);
	Vertex* l = new Vertex(10.0,-6.0, -5.0, 1);
	Vertex* m = new Vertex(0.0,  8.0,  5.0, 1);
	Vertex* n = new Vertex(0.0,  8.0, -5.0, 1);

	//Create 24 diffrence triangle
	//Roof
	Triangle* triangle1  = new Triangle(a, b, m);
	Triangle* triangle2  = new Triangle(b, d, m);
	Triangle* triangle3  = new Triangle(d, f, m);
	Triangle* triangle4  = new Triangle(f, e, m);
	Triangle* triangle5  = new Triangle(e, c, m);
	Triangle* triangle6  = new Triangle(c, a, m);
	//Floor
	Triangle* triangle7  = new Triangle(g, h, n);
	Triangle* triangle8  = new Triangle(h, j, n);
	Triangle* triangle9  = new Triangle(j, l, n);
	Triangle* triangle10 = new Triangle(l, k, n);
	Triangle* triangle11 = new Triangle(k, i, n);
	Triangle* triangle12 = new Triangle(i, g, n);
	//Walls
	Triangle* triangle13 = new Triangle(a, g, b);
	Triangle* triangle14 = new Triangle(b, h, g);

	Triangle* triangle15 = new Triangle(b, h, d);
	Triangle* triangle16 = new Triangle(d, j, h);

	Triangle* triangle17 = new Triangle(d, j, f);
	Triangle* triangle18 = new Triangle(f, l, j);

	Triangle* triangle19 = new Triangle(f, l, e);
	Triangle* triangle20 = new Triangle(e, k, l);

	Triangle* triangle21 = new Triangle(e, k, c);
	Triangle* triangle22 = new Triangle(c, i, k);

	Triangle* triangle23 = new Triangle(c, i, a);
	Triangle* triangle24 = new Triangle(a, g, i);

	//Add all triangles to the scen
	triangles->push_back(triangle1);
	triangles->push_back(triangle2);
	triangles->push_back(triangle3);
	triangles->push_back(triangle4);
	triangles->push_back(triangle5);
	triangles->push_back(triangle6);
	triangles->push_back(triangle7);
	triangles->push_back(triangle8);
	triangles->push_back(triangle9);
	triangles->push_back(triangle10);
	triangles->push_back(triangle11);
	triangles->push_back(triangle12);
	triangles->push_back(triangle13);
	triangles->push_back(triangle14);
	triangles->push_back(triangle15);
	triangles->push_back(triangle16);
	triangles->push_back(triangle17);
	triangles->push_back(triangle18);
	triangles->push_back(triangle19);
	triangles->push_back(triangle20);
	triangles->push_back(triangle21);
	triangles->push_back(triangle22);
	triangles->push_back(triangle23);
	triangles->push_back(triangle24);
}
