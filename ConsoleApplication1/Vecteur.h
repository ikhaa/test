#pragma once
#include "Point.h"
#include <math.h> 
class Vecteur
{
public:
	Point p1;
	Point p2;
	long double norme;
	Vecteur(long double n, Point p, Point p2);
	Vecteur();
	~Vecteur();
	long double CalculerAngle();
	void CalculerArriver();
	void DeplacerVecteur(Point arriver);
	void AjouterVecteur(Vecteur vecteur);
};

