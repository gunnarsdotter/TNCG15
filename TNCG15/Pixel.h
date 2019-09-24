#pragma once
#include "Ray.h"
#include "ColorDbl.h"
class Pixel
{
public:
	Pixel(ColorDbl c, Ray r) :color{ c }, ray{ r } {};
	virtual ~Pixel() = default;
	ColorDbl color;
	Ray &ray;
};

