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
	int brojFiguraNaPolju = figureNaPolju.size();
	for (int i = 0; i < brojFiguraNaPolju; ++i) {
			if (figureNaPolju[i].trenutnoPolje.front() <= zadanoPolje)
				return false;
	}
	return true;
}

Igraè::Igraè(Boja boja)
{
	for (int i = 0; i < 4; ++i) {
		figure.push_back(Figura(boja, vratiPoèetnoPolje(boja), vratiZadnjePolje(boja)));
		kuæa.push_back(nullptr);
	}
	zadnjeSlobodnoMjestoUKuæi = 4;
	brojFiguraNaPolju = 0;
	brojFiguraUCilju = 0;
}

Igraè::Igraè()
{
}




Igraè::~Igraè()
{
}

int Igraè::vratiPoèetnoPolje()
{
	return figure[0].vratiPoèetnuToèku();
}

int Igraè::vratiZadnjePolje()
{
	return figure[0].vratiZavršnuToèku();;
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
	int brojFiguraNaPolju = figureNaPolju.size();
	if (brojPomaka <= 4) {
		for (int i = 0; i < brojFiguraNaPolju; ++i) {
				if (figureNaPolju[i].poljeUKuæi <= brojPomaka)
						return false;
		}
		if ((figura->poljeUKuæi + brojPomaka - 1) > zadnjeSlobodnoMjestoUKuæi)
			return false;
		kuæa.at(brojPomaka - 1) = figura;
		++brojFiguraUCilju;
		figura->poljeUKuæi += brojPomaka - 1;
		if(figura->poljeUKuæi == zadnjeSlobodnoMjestoUKuæi)
			--zadnjeSlobodnoMjestoUKuæi;
		return true;
	}
	return false;
}

Boja Igraè::vratiBoju()
{
	return figure[0].vratiBoju();
}
