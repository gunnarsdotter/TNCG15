#pragma once
class Vertex
{
public:
	Vertex() = delete;
	Vertex(double inX, double inY, double inZ, double inW):
		x(inX), y(inY), z(inZ), w(inW == 0)
	{};

	virtual ~Vertex();

	double x, y, z, w;
};

