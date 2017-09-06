#include "stdafx.h"
#include "Vecteur.h"
#include <math.h> 

Vecteur::Vecteur(long double n, Point p1, Point p2)
{
	this->norme = n;
	this->p1 = Point(p1.x,p1.y);
	this->p2 = Point(p2.x, p2.y);
	CalculerArriver();
}


Vecteur::Vecteur()
{
}


Vecteur::~Vecteur()
{
	this->p1.~Point();
	this->p2.~Point();
}

long double Vecteur::CalculerAngle()
{
	long double deltaX = this->p2.x - this->p1.x;
	long double deltaY = this->p2.y - this->p1.y;

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
			return -PI + atan(deltaY / deltaX);
		else if (invX > 0)
			return PI - atan(deltaY / deltaX);
		else if (invY > 0)
			return - atan(deltaY / deltaX);
		else
			return atan(deltaY / deltaX);
	}
	else if (this->p2.y > this->p1.y)
		return PI / 2;
	else if (this->p2.y < this->p1.y)
		return -PI / 2;
	else
		return 0;
}

void Vecteur::CalculerArriver()
{
	long double angle = CalculerAngle();
	this->p2.x = this->p1.x + this->norme*cos(angle);
	this->p2.y = this->p1.y + this->norme*sin(angle);
}

void Vecteur::DeplacerVecteur(Point depart)
{
	this->p2.x = depart.x + (p2.x - p1.x);
	this->p2.y = depart.y + (p2.y - p1.y);
	this->p1.x = depart.x;
	this->p1.y = depart.y;
}

void Vecteur::AjouterVecteur(Vecteur vecteur)
{
	this->p2.x += vecteur.p2.x - vecteur.p1.x;
	this->p2.y += vecteur.p2.y - vecteur.p1.y;
	this->norme = this->p1.CalculerDistance(this->p2);
}
