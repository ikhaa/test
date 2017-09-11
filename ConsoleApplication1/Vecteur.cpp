#include "stdafx.h"
#include "Vecteur.h"
#include <math.h> 

Vecteur::Vecteur(long double n, Point p1, Point p2)
{
	this->norme = n;
	this->p1 = Point(p1.x,p1.y,p1.z);
	this->p2 = Point(p2.x, p2.y,p2.z);
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


void Vecteur::CalculerArriver()
{
	long double deltaX = this->p2.x - this->p1.x;
	long double deltaY = this->p2.y - this->p1.y;
	long double deltaZ = this->p2.z - this->p1.z;

	long double normeActuel = p1.CalculerDistance(p2);

	if (normeActuel != 0)
	{
		long double coef = norme / normeActuel;

		this->p2.x = this->p1.x + deltaX*coef;
		this->p2.y = this->p1.y + deltaY*coef;
		this->p2.z = this->p1.z + deltaZ*coef;
	}
}

void Vecteur::DeplacerVecteur(Point depart)
{
	this->p2.x = depart.x + (p2.x - p1.x);
	this->p2.y = depart.y + (p2.y - p1.y);
	this->p2.z = depart.z + (p2.z - p1.z);
	this->p1.x = depart.x;
	this->p1.y = depart.y;
	this->p1.z = depart.z;
}

void Vecteur::AjouterVecteur(Vecteur vecteur)
{
	this->p2.x += vecteur.p2.x - vecteur.p1.x;
	this->p2.y += vecteur.p2.y - vecteur.p1.y;
	this->p2.z += vecteur.p2.z - vecteur.p1.z;
	this->norme = this->p1.CalculerDistance(this->p2);
}
