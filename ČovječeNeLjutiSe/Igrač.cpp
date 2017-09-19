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

bool Igraè::provjeraZaPreskakanjeFigura(int zadanoPolje,Figura f)
{
	int brojFiguraNaPolju = figureNaPolju.size();
	for (int i = 0; i < brojFiguraNaPolju; ++i) {
		if (figureNaPolju[i] == f)
			continue;
		if (figureNaPolju[i].vratiTrenutnoPolje() == zadanoPolje)
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
	brojFiguraUKuèici = 4;
	brojFiguraNaPolju = 0;
	brojFiguraUCilju = 0;
}

Igraè::Igraè()
{
}




Igraè::~Igraè()
{
	kuæa.clear();
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
	int novoPolje = (figura->vratiTrenutnoPolje() + brojPomaka);
	int zadnjePolje = figura->vratiZavršnuToèku();
	
	if(figura->trenutnoPolje.size()<brojPomaka)
		return pomakniUKuæu(figura, novoPolje - zadnjePolje);
	else {
		if (provjeraZaPreskakanjeFigura(novoPolje, *figura)) {
			for (int i = 0; i < brojPomaka; ++i) {
				figura->pomakni();
			}
		}
		else {
				return false;
		}
	}
	return true;
}

bool Igraè::pomakniUKuæu(Figura * figura, int brojPomaka)
{
int brojFiguraNaPolju = figureNaPolju.size();
	if (brojPomaka <= 4) {
		for (int i = 0; i < brojFiguraNaPolju; ++i) {
				if (figureNaPolju[i].poljeUKuæi <= brojPomaka&&figureNaPolju[i].poljeUKuæi >-1)
						return false;
		}
		if ((figura->poljeUKuæi + brojPomaka - 1) > zadnjeSlobodnoMjestoUKuæi)
			return false;
		kuæa[brojPomaka - 1] = figura;
		++brojFiguraUCilju;
		if (figura->poljeUKuæi = -1)
			figura->poljeUKuæi = brojPomaka -1;
		else
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
