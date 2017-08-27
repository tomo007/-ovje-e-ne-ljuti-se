#include "stdafx.h"
#include "Igraè.h"


int Igraè::vratiPoèetnoPolje(char boja)
{
	switch (boja) {
	case 'c':
		return 0;
	case 'p':
		return 10;
	case 'z':
		return 20;
	case 'ž':
		return 30;
	default:
		break;
	}
}

int Igraè::vratiZadnjePolje(char boja)
{
	switch (boja) {
	case 'c':
		return 39;
	case 'p':
		return 9;
	case 'z':
		return 19;
	case 'ž':
		return 29;
	default:
		break;
	}
}

Igraè::Igraè(char boja)
{
	for (int i = 0; i < 4; ++i) {
		Igraè::kuæa[i] = nullptr;
		Igraè::figureNaPolju[i] = nullptr;
		Igraè::figure[i] = new Figura(boja, vratiPoèetnoPolje(boja), vratiZadnjePolje(boja));
	}


}


Igraè::~Igraè()
{
}

void Igraè::move(Figura * figura, int brojPomaka)
{
}
