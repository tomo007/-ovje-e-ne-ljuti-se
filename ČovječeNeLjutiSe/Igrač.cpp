#include "stdafx.h"
#include "Igra�.h"


int Igra�::vratiPo�etnoPolje(char boja)
{
	switch (boja) {
	case 'c':
		return 0;
	case 'p':
		return 10;
	case 'z':
		return 20;
	case '�':
		return 30;
	default:
		break;
	}
}

int Igra�::vratiZadnjePolje(char boja)
{
	switch (boja) {
	case 'c':
		return 39;
	case 'p':
		return 9;
	case 'z':
		return 19;
	case '�':
		return 29;
	default:
		break;
	}
}

Igra�::Igra�(char boja)
{
	for (int i = 0; i < 4; ++i) {
		Igra�::ku�a[i] = nullptr;
		Igra�::figureNaPolju[i] = nullptr;
		Igra�::figure[i] = new Figura(boja, vratiPo�etnoPolje(boja), vratiZadnjePolje(boja));
	}


}


Igra�::~Igra�()
{
}

void Igra�::move(Figura * figura, int brojPomaka)
{
}
