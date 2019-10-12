#include "Ray.h"

void Ray::setTriangle(Triangle* in, glm::vec3 inPoint, ColorDbl c){
	T = in;
	intersectionpoint = inPoint;
	color = c;
	//c.display();
}

glm::vec3  Ray::getDirection() const {
	return direction;
}