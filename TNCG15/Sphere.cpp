#include "Sphere.h"


Sphere::Sphere(double r, glm::vec4 c, ColorDbl col) :
	radius{ r }, center{c}, color{col}
{

}


Sphere::~Sphere()
{
}

bool Sphere::rayIntersection(Ray* arg, glm::vec3* x) {

	glm::vec4 viewdir = arg->start - center;
	double b = 2*glm::dot(glm::normalize(arg->direction),glm::vec3(viewdir));
	double c = glm::dot(viewdir,viewdir)- pow(radius,2);
	if (c < pow((b / 2), 2)) {
		double d1 = -(b / 2) + sqrt(pow((b / 2), 2) - c);
		double d2 = -(b / 2) - sqrt(pow((b / 2), 2) - c);
		double d = 0;

		if(d1 < d2)	d = d1;
		else d = d2;
		x->x = arg->start.x + d * glm::normalize(arg->direction).x;
		x->y = arg->start.y + d * glm::normalize(arg->direction).y;
		x->z = arg->start.z + d * glm::normalize(arg->direction).z;
		return true;
	}	
	return false;
}