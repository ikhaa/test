#pragma once
#include "Point.h"
#include <vector>
#include "Vecteur.h"
#include "Astre.h"
#include <iostream>
#include <fstream>
class Simulation
{
public:
	std::vector<Astre> pts;
	const int minute = 60;
	const int heure = 3600;
	const int jour = 86400;
	const int annee = 31557600;
	void Lancer();
	Simulation();
	~Simulation();
};

