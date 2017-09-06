#pragma once
#include "Point.h"
#include <math.h> 
class Vecteur
{
public:
	const long double PI = 3.1415926535;
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

