#include "stdafx.h"
#include "Figura.h"


Figura::Figura(char boja, byte poèetak, byte cilj)
{
	Figura::boja = boja;
	Figura::trenutnoPolje = -1;
	Figura::poèetak = poèetak;
	Figura::cilj = cilj;

}


Figura::~Figura()
{
}
