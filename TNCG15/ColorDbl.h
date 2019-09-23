#pragma once
class ColorDbl
{
public:
	ColorDbl(float r, float g, float b) :r{ r }, g{ g }, b{ b } {};
	virtual ~ColorDbl() = default;
private:
	float r, g, b;
};

