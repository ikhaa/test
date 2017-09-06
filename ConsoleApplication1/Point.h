#pragma once
#include <math.h>
class Point
{
public:
	long double x; long double y;
	Point(long double x, long double y);
	Point();
	~Point();
	long double CalculerDistanceCarre(Point p);
	long double CalculerDistance(Point p);
};

