#include "stdafx.h"
#include "Igra�.h"


int Igra�::vratiPo�etnoPolje(Boja boja)
{
	switch (boja) {
	case Boja::CRVENA:
		return 0;
	case Boja::PLAVA:
		return 10;
	case Boja::ZELENA:
		return 20;
	case Boja::ZUTA:
		return 30;
	default:
		break;
	}
}

int Igra�::vratiZadnjePolje(Boja boja)
{
	switch (boja) {
	case Boja::CRVENA:
		return 39;
	case Boja::PLAVA:
		return 9;
	case Boja::ZELENA:
		return 19;
	case Boja::ZUTA:
		return 29;
	default:
		break;
	}
}

bool Igra�::provjeraZaPreskakanjeFigura(int zadanoPolje)
{
	for (int i = 0; i < 4; ++i) {
		if (figureNaPolju[i] != nullptr)
			if (figureNaPolju[i]->trenutnoPolje >= zadanoPolje)
				return false;
	}
	return true;
}

Igra�::Igra�(Boja boja)
{
	for (int i = 0; i < 4; ++i) {
		ku�a[i] = nullptr;
		figureNaPolju[i] = nullptr;
		figure[i] =new Figura(boja, vratiPo�etnoPolje(boja), vratiZadnjePolje(boja));
	}


}


Igra�::~Igra�()
{
}

bool Igra�::pomakni(Figura * figura, int brojPomaka)
{	
	int novoPolje = figura->trenutnoPolje + brojPomaka;
	int zadnjePolje = figura->vratiZavr�nuTo�ku();
	if (novoPolje <= zadnjePolje) {
		if (provjeraZaPreskakanjeFigura(novoPolje)) {
			figura->trenutnoPolje = novoPolje % 39;
			return true;
		}
		else 
			return false;		
	}
	else {
		return pomakniUKu�u(figura, novoPolje - zadnjePolje);
	}
}

bool Igra�::pomakniUKu�u(Figura * figura, int brojPomaka)
{
	if (brojPomaka <= 4) {
		for (int i = 0; i < 4; ++i) {
			if (figureNaPolju[i] != nullptr)
				if (figureNaPolju[i]->poljeUKu�i >= 0)
					if (figureNaPolju[i] != figura)
						return false;
		}
		ku�a.at(brojPomaka - 1) = figura;
		figura->poljeUKu�i = brojPomaka - 1;
		return true;
	}
	return false;
}

Boja Igra�::vratiBoju()
{
	return figure[0]->vratiBoju();
}
