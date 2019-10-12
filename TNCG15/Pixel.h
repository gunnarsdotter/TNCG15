#pragma once
#include "Ray.h"
#include "ColorDbl.h"

class Pixel
{
public:
	Pixel() {};
	Pixel(ColorDbl c, Ray* r) :color{ c }, ray{ r } {};
	virtual ~Pixel() = default;
	void addRay(Ray* inRay) {
		ray = inRay;
	//TABORT
		color = ray->color;
	}
	ColorDbl getColor() { return color; }

private: 
	ColorDbl color;
	Ray* ray;
};

