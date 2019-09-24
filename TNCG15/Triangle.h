#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "glm.hpp"
#include "Direction.h"
class Triangle
{
public:
	Triangle() = delete;
	Triangle(glm::vec4 inV1, glm::vec4 inV2, glm::vec4 inV3, ColorDbl color) :
		v1{inV1 }, v2{ inV2 }, v3{ inV3 }, normal(calculateNormal(v1, v2, v3)), color{color}
	{};
	
	glm::vec3 calculateNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3){
		return glm::normalize(glm::cross(v2 - v1, v3 - v1));
	};
	//TODO-  rayIntersection(Ray arg)
	//that computes the intersectionbetween aRayand 
	//theTrianglewith the Möller-Trumbore algorithm
	glm::vec3 rayIntersection(Ray arg){
		glm::vec4 T = arg.start - v1;
		glm::vec4 E1 = v2 - v1;
		glm::vec4 E2 = v3 - v1;
		glm::vec4 D = arg.end - arg.start;
		//glm::vec3 P = glm::cross(D, E2);
		//glm::vec3 Q = glm::cross(T, E1);

		return v1;
	}

	glm::vec3 getNormal() { return normal; };
	ColorDbl getColor() {return color;};
	virtual ~Triangle() = default;

private:
	glm::vec4 v1, v2, v3;
	glm::vec3 normal;
	ColorDbl color;
};

