#pragma once
#include <math.h> 
#include <vector>
#include "Vecteur.h"
class Astre
{
	public:
		const long double G = 6.673 / pow(10, 11);
		const long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315;
		Point position;
		long double masse;
		Vecteur* vitesse;
		Vecteur* acceleration;
		Astre(long double x, long double y, long double m);
		~Astre();
		void Calculer(std::vector<Astre> pts, int pos, int lenght, int dureePeriode);
		Vecteur CalculerAcceleration(Astre p);
		void CalculerVitesse(int dureePeriode);
		void CalculerPosition(int dureePeriode);
};

