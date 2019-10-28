#include "Ray.h"

void Ray::setTriangle(Triangle* in, glm::vec3 inPoint, ColorDbl c, double tc) {
	T = in;
	intersectionpoint = inPoint;
	color = c;
	t = tc;
	
	//c.display();
}

void Ray::setSphere(Sphere* in, glm::vec3 inPoint, ColorDbl c, double tc) {
	S = in;
	intersectionpoint = inPoint;
	color = c;
	t = tc;
};


glm::vec3  Ray::getDirection() const {
	return direction;
};