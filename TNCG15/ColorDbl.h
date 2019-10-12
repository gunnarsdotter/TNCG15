#pragma once
#include "glm.hpp"
#include <iostream>

class ColorDbl
{
public:
	ColorDbl() {
		color = glm::vec3(0, 0, 0);
	}
	ColorDbl(float r, float g, float b) {
		color = glm::vec3(r, g, b);
	};
	virtual ~ColorDbl() = default;
	//BORT?
	void display() {
		std::cout << " (" << color.r << ", " << color.g << ", " << color.b << ")";
	}

	glm::vec3 color;
};

