#pragma once
#include "Ray.h"
#include "ColorDbl.h"
class Pixel
{
public:
	Pixel();
	virtual ~Pixel();
	ColorDbl color;
	//Ray &ray;
};

