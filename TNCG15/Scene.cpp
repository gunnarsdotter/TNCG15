#include "Scene.h"

Scene::Scene()
{
	triangles = new std::vector<Triangle*>();
	createRoom();
	c = new Camera(glm::vec4(0, -1, -1, 1), glm::vec4(0, 1, -1, 1), glm::vec4(0, 1, 1, 1), glm::vec4(0, -1, 1, 1));
}

Scene::~Scene()
{
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
	glm::vec4 m= glm::vec4(0.0, 8.0, 5.0, 1);
	glm::vec4 n = glm::vec4(0.0, 8.0, -5.0, 1);

	//color
	ColorDbl white   = ColorDbl(1.0, 1.0, 1.0);
	ColorDbl red     = ColorDbl(1.0, 0.0, 0.0);
	ColorDbl green   = ColorDbl(0.0, 1.0, 0.0);
	ColorDbl blue    = ColorDbl(0.0, 0.0, 1.0);
	ColorDbl magenta = ColorDbl(1.0, 0.0, 1.0);
	ColorDbl yellow	 = ColorDbl(1.0, 1.0, 0.0);
	ColorDbl cyan    = ColorDbl(0.0, 1.0, 1.0);


	//Add all triangles to the scen
	//Roof
	triangles->push_back(new Triangle(a,b,m,white));
	triangles->push_back(new Triangle(b,d,m,white));
	triangles->push_back(new Triangle(d,f,m,white));
	triangles->push_back(new Triangle(f,e,m,white));
	triangles->push_back(new Triangle(e,c,m,white));
	triangles->push_back(new Triangle(c,a,m,white));

	//Floor
	triangles->push_back(new Triangle(g,h,n,white));
	triangles->push_back(new Triangle(h,j,n,white));
	triangles->push_back(new Triangle(j,l, n, white));
	triangles->push_back(new Triangle(l,k, n, white));
	triangles->push_back(new Triangle(k,i, n, white));
	triangles->push_back(new Triangle(i,g, n, white));

	//Walls
	triangles->push_back(new Triangle(a,g,b,red));
	triangles->push_back(new Triangle(b,h,g,red));

	triangles->push_back(new Triangle(b,h,d,green));
	triangles->push_back(new Triangle(d,j,h,green));
	
	triangles->push_back(new Triangle(d,j,f,blue));
	triangles->push_back(new Triangle(f,l,j,blue));
	
	triangles->push_back(new Triangle(f,l,e,magenta));
	triangles->push_back(new Triangle(e,k,l,magenta));
	
	triangles->push_back(new Triangle(e,k,c,yellow));
	triangles->push_back(new Triangle(c,i,k,yellow));
	
	triangles->push_back(new Triangle(c,i,a,cyan));
	triangles->push_back(new Triangle(a,g,i,cyan));



	/*
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
	*/


}
