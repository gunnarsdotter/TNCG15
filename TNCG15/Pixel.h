#pragma once
#include "Ray.h"
#include "ColorDbl.h"

class Pixel
{
public:
	Pixel() {};
	Pixel(ColorDbl c, Ray* r) :color{ c }, ray{ r } {};
	virtual ~Pixel() = default;

private: 
	ColorDbl color;
	Ray* ray;
};

