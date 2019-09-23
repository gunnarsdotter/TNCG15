#pragma once
#include "Ray.h"
#include "ColorDbl.h"
class Pixel
{
public:
	Pixel();
	virtual ~Pixel() = default;
	ColorDbl color;
	//Ray &ray;
};

