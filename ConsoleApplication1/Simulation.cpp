#include "stdafx.h"
#include "Simulation.h"
#include "Astre.h"
#include "Vecteur.h"
#include <iostream>
#include <fstream>


Simulation::Simulation()
{
}


void Simulation::Lancer() {
	int nombreCycle = 365*24;
	int dureePeriode = heure;

	Astre Terre(0, 0, 0, 5.9736 * pow(10, 24));
	Terre.vitesse = &Vecteur(0, Terre.position, Terre.position);
	Terre.acceleration = &Vecteur(0, Terre.position, Terre.position);
	Astre Lune(0, 0, 384399000, 7.3477 * pow(10, 22));
	Lune.acceleration = &Vecteur(0, Lune.position, Lune.position);
	Lune.vitesse = &Vecteur(1022, Lune.position, Point(0, 1022, 384399000));
	/*Astre Mercure(57909176000, 0, 3.311 * pow(10, 26));
	Mercure.acceleration = Deplacement(47360, 0, 57909176000, 47360);
	Astre Venus(0, 108208930000, 4.8685 * pow(10, 27));
	Venus.acceleration = Deplacement(35020, 0, -35020, 108208930000);
	Astre Terre(-149597887500, 0 , 5.9736 * pow(10, 27));
	Terre.acceleration = Deplacement(29783, 0, -149597887500, -29783);
	Astre Mars(0, -227936637000, 641.85 * pow(10, 24));
	Mars.acceleration = Deplacement(24077, 0, 24077, -227936637000);
	Astre Jupiter(778412027000, 0, 1.8986 * pow(10, 30));
	Jupiter.acceleration = Deplacement(13057, 0, 778412027000, 13057);
	Astre Saturne(0, 1429394069000, 568.46 * pow(10, 27));
	Saturne.acceleration = Deplacement(9644, 0, -9644, 1429394069000);
	Astre Uranus(-2870658186000, 0, 8.6810 * pow(10, 28));
	Uranus.acceleration = Deplacement(6800, 0, -1495978875000, -6800);
	Astre Neptune(0, -4503443661000, 102.43 * pow(10, 27));
	Neptune.acceleration = Deplacement(5431, 0, 5431, -4503443661000);*/

	
	std::ofstream FichierTerre;
	FichierTerre.open("Terre.csv");

	pts = std::vector<Astre>{ Terre, Lune };

	int nombreObjet = pts.size();

	for (int i = 0; i < nombreCycle; i++)
	{
		for (int j = 0; j < nombreObjet; j++)
		{
			pts[j].Calculer(pts, j, nombreObjet, dureePeriode);

			FichierTerre << pts[j].position.x << ";" << pts[j].position.y << ";" << pts[j].position.z << ";";
			FichierTerre << pts[j].vitesse->p2.x - pts[j].vitesse->p1.x << ";" << pts[j].vitesse->p2.y - pts[j].vitesse->p1.y << ";" << pts[j].vitesse->norme << ";";
			FichierTerre << pts[j].acceleration->p2.x - pts[j].acceleration->p1.x << ";" << pts[j].acceleration->p2.y - pts[j].acceleration->p1.y << ";" << pts[j].acceleration->norme << ";";
			if (j == 1)
				FichierTerre << "\n";
			else
				FichierTerre << ";";
		}
	}
	FichierTerre.close();
}


Simulation::~Simulation()
{
	for (int i = 0; i < pts.size(); i++)
	{
		pts[i].~Astre();
	}
}
