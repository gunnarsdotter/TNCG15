#include "Ray.h"

void Ray::setTriangle(Triangle* in, glm::vec3 inPoint, ColorDbl c) {
	T = in;
	intersectionpoint = inPoint;
	color = c;
	//c.display();
}

void Ray::setSphere(Sphere* in, glm::vec3 inPoint, ColorDbl c) {
	//S = in;
	intersectionpoint = inPoint;
	color = c;
};


glm::vec3  Ray::getDirection() const {
	return direction;
};