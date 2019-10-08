#pragma once
#include "glm.hpp"
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
private:
	glm::vec3 color;
};

