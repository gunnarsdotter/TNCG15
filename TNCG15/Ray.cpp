#include "Ray.h"

void Ray::setTriangle(Triangle* in, glm::vec3 inPoint, glm::vec3 col, double tc) {
	T = in;
	intersectionpoint = inPoint;
	t = tc;
	color = col;

	//c.display();
}

void Ray::setSphere(Sphere* in, glm::vec3 inPoint, glm::vec3 col, double tc) {
	S = in;
	intersectionpoint = inPoint;
	t = tc;
	color = col;
};


glm::vec3  Ray::getDirection() const {
	return direction;
};