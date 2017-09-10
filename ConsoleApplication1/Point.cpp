#include "stdafx.h"
#include "Point.h"
#include <math.h>

Point::Point(long double x, long double y, long double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point()
{
}

Point::~Point()
{
}

long double Point::CalculerDistanceCarre(Point p2)
{
	return pow(p2.x - this->x, 2) + pow(p2.y - this->y, 2) + pow(p2.z - this->z, 2);
}

long double Point::CalculerDistance(Point p2)
{
	return sqrt(pow(p2.x - this->x, 2) + pow(p2.y - this->y, 2) + pow(p2.z - this->z, 2));
}

std::vector<long double> Point::CalculerAngle(Point p2)
{
	std::vector<long double> angles(2);
	long double points[2][4];
	points[0][0] = this->x;
	points[0][1] = this->y;
	points[0][2] = p2.x;
	points[0][3] = p2.y;

	points[1][0] = this->x;
	points[1][1] = this->z;
	points[1][2] = p2.x;
	points[1][3] = p2.z;

	for (int i = 0; i < 2; i++)
	{
		long double deltaX = points[i][2] - points[i][0];
		long double deltaY = points[i][3] - points[i][1];

		if (deltaX != 0)
		{
			bool invX = false;
			bool invY = false;

			if (deltaX < 0)
			{
				invX = true;
				deltaX = -deltaX;
			}

			if (deltaY < 0)
			{
				invY = true;
				deltaY = -deltaY;
			}

			if (invX && invY)
				angles[i] = -PI + atan(deltaY / deltaX);
			else if (invX > 0)
				angles[i] = PI - atan(deltaY / deltaX);
			else if (invY > 0)
				angles[i] = -atan(deltaY / deltaX);
			else
				angles[i] = atan(deltaY / deltaX);
		}
		else if (deltaY > 0)
			angles[i] = PI / 2;
		else if (deltaY < 0)
			angles[i] = -PI / 2;
		else
			angles[i] = 0;
	}
	return angles;
}
