// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Simulation.h"


int main()
{
	Simulation s;
	s.Lancer();
	s.~Simulation();
    return 0;
}

