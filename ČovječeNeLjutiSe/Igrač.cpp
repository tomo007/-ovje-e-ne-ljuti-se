#include "stdafx.h"
#include "Igraè.h"


int Igraè::vratiPoèetnoPolje(Boja boja)
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

int Igraè::vratiZadnjePolje(Boja boja)
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

bool Igraè::provjeraZaPreskakanjeFigura(int zadanoPolje)
{
	for (int i = 0; i < 4; ++i) {
		if (figureNaPolju[i] != nullptr)
			if (figureNaPolju[i]->trenutnoPolje.front() <= zadanoPolje)
				return false;
	}
	return true;
}

Igraè::Igraè(Boja boja)
{
	for (int i = 0; i < 4; ++i) {
		kuæa[i] = nullptr;
		figureNaPolju[i] = nullptr;
		figure[i] =new Figura(boja, vratiPoèetnoPolje(boja), vratiZadnjePolje(boja));
	}
	figureUKuæi = 0;


}


Igraè::~Igraè()
{
}

bool Igraè::pomakni(Figura * figura, int brojPomaka)
{	
	int novoPolje = figura->trenutnoPolje.front() + brojPomaka;
	int zadnjePolje = figura->vratiZavršnuToèku();

	if(figura->trenutnoPolje.size()<brojPomaka)
		return pomakniUKuæu(figura, novoPolje - zadnjePolje);
	else {
		for (int i = 0; i < brojPomaka; ++i)
			figura->trenutnoPolje.pop_front();
	}
	return true;
}

bool Igraè::pomakniUKuæu(Figura * figura, int brojPomaka)
{
	if (figura->poljeUKuæi < 0)
		++figureUKuæi;
	if (brojPomaka <= 4) {
		for (int i = 0; i < 4; ++i) {
			if (figureNaPolju[i] != nullptr)
				if (figureNaPolju[i]->poljeUKuæi >= 0)
					if (figureNaPolju[i] != figura)
						return false;
		}
		if ((figura->poljeUKuæi + brojPomaka - 1) > 4)
			return false;
		kuæa.at(brojPomaka - 1) = figura;
		figura->poljeUKuæi = brojPomaka - 1;
		return true;
	}
	return false;
}

Boja Igraè::vratiBoju()
{
	return figure[0]->vratiBoju();
}
