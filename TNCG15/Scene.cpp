#include "Scene.h"

Scene::Scene()
{
	//triangles = new std::vector<Triangle*>();
	createRoom();	
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
	glm::vec4 m= glm::vec4(8.0, 0.0, 5.0, 1);
	glm::vec4 n = glm::vec4(8.0, 0.0, -5.0, 1);

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
	triangles.push_back(new Triangle(a,b,m,white));
	triangles.push_back(new Triangle(b,d,m,white));
	triangles.push_back(new Triangle(d,f,m,white));
	triangles.push_back(new Triangle(f,e,m,white));
	triangles.push_back(new Triangle(e,c,m,white));
	triangles.push_back(new Triangle(c,a,m,white));

	//Floor
	triangles.push_back(new Triangle(h, g, n, white));
	triangles.push_back(new Triangle(j, h, n, white));
	triangles.push_back(new Triangle(l, j, n, white));
	triangles.push_back(new Triangle(k, l, n, white));
	triangles.push_back(new Triangle(i, k, n, white));
	triangles.push_back(new Triangle(g, i, n, white));

	//Walls
	triangles.push_back(new Triangle(a,g,b,red));
	triangles.push_back(new Triangle(h,b,g,red));

	triangles.push_back(new Triangle(b,h,d,green));
	triangles.push_back(new Triangle(j,d,h,green));
	
	triangles.push_back(new Triangle(d,j,f,blue));
	triangles.push_back(new Triangle(l,f,j,blue));
	
	triangles.push_back(new Triangle(f,l,e,magenta));
	triangles.push_back(new Triangle(k,e,l,magenta));
	
	triangles.push_back(new Triangle(e,k,c,yellow));
	triangles.push_back(new Triangle(i,c,k,yellow));
	
	triangles.push_back(new Triangle(c,i,a,cyan));
	triangles.push_back(new Triangle(g,a,i,cyan));

}
