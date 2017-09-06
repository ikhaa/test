#include "stdafx.h"
#include "Astre.h"
#include <math.h> 


Astre::Astre(long double x, long double y, long double m)
{
	this->position = Point(x, y);
	this->masse = m;
}

Astre::~Astre()
{
	this->position.~Point();
	(*this->vitesse).~Vecteur();
	(*this->acceleration).~Vecteur();
}

void Astre::Calculer(std::vector<Astre> pts, int pos, int lenght, int dureePeriode)
{
	this->acceleration = new Vecteur(0, this->position, this->position);
	for (int i = 0; i < lenght; i++)
	{
		if (i != pos)
		{
			(*this->acceleration).AjouterVecteur(CalculerAcceleration(pts[i]));
		}
	}
	CalculerVitesse(dureePeriode);
	CalculerPosition(dureePeriode);
}
Vecteur Astre::CalculerAcceleration(Astre astre){
	long double norme = G*astre.masse / this->position.CalculerDistanceCarre(astre.position);
	Vecteur acc = Vecteur(norme, this->position, astre.position);
	return acc;
}

void Astre::CalculerVitesse(int dureePeriode) {
	long double vitesseFinal = (*this->acceleration).norme * dureePeriode;
	long double vitesseMoyenne = vitesseFinal/2;
	Vecteur nouvelleVitesse = Vecteur(vitesseFinal, this->position, (*this->acceleration).p2);
	(*this->vitesse).AjouterVecteur(nouvelleVitesse);
}

void Astre::CalculerPosition(int dureePeriode) {
	this->position.x += ((*this->vitesse).p2.x - (*this->vitesse).p1.x)*dureePeriode;
	this->position.y += ((*this->vitesse).p2.y - (*this->vitesse).p1.y)*dureePeriode;
	(*this->vitesse).DeplacerVecteur(this->position);
	(*this->acceleration).DeplacerVecteur(this->position);
}