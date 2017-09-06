#include "stdafx.h"
#include "Point.h"
#include <math.h>

Point::Point(long double x, long double y)
{
	this->x = x;
	this->y = y;
}


Point::Point()
{
}


Point::~Point()
{
}

long double Point::CalculerDistanceCarre(Point p2)
{
	return pow(p2.x - this->x, 2) + pow(p2.y - this->y, 2);
}

long double Point::CalculerDistance(Point p2)
{
	return sqrt(pow(p2.x - this->x, 2) + pow(p2.y - this->y, 2));
}
