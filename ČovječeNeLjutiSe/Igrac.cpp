#include "stdafx.h"
#include "Igrac.h"


int Igrac::vratiPocetnoPolje(Boja boja)
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

int Igrac::vratiZadnjePolje(Boja boja)
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

bool Igrac::provjeraZaPreskakanjeFigura(int zadanoPolje,Figura f)
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

Igrac::Igrac(Boja boja)
{
	for (int i = 0; i < 4; ++i) {
		figure.push_back(Figura(boja, vratiPocetnoPolje(boja), vratiZadnjePolje(boja)));
		cilj.push_back(nullptr);
	}
	zadnjeSlobodnoMjestoUKuci = 4;
	brojFiguraUKucici = 4;
	brojFiguraNaPolju = 0;
	brojFiguraUCilju = 0;
}

Igrac::Igrac()
{
}




Igrac::~Igrac()
{
	cilj.clear();
}

int Igrac::vratiPocetnoPolje()
{
	return figure[0].vratiPocetnuTocku();
}

int Igrac::vratiZadnjePolje()
{
	return figure[0].vratiZavrsnuTocku();;
}

bool Igrac::pomakni(Figura * figura, int brojPomaka)
{	
	int novoPolje = (figura->vratiTrenutnoPolje() + brojPomaka);
	int zadnjePolje = figura->vratiZavrsnuTocku();
	if (figura->poljeUKuci > 0)
		return pomakniUKucu(figura, brojPomaka);
	if(figura->trenutnoPolje.size()<brojPomaka)
		return pomakniUKucu(figura, novoPolje - zadnjePolje);
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

bool Igrac::pomakniUKucu(Figura * figura, int brojPomaka)
{
int brojFiguraNaPolju = figureNaPolju.size();
	if (brojPomaka <= 4) {
		for (int i = 0; i < brojFiguraNaPolju; ++i) {
				if (figureNaPolju[i].poljeUKuci <= brojPomaka&&figureNaPolju[i].poljeUKuci >-1)
						return false;
		}
		if ((figura->poljeUKuci + brojPomaka - 1) > zadnjeSlobodnoMjestoUKuci)
			return false;
		cilj[brojPomaka - 1] = figura;
		++brojFiguraUCilju;
		if (figura->poljeUKuci = -1)
			figura->poljeUKuci = brojPomaka -1;
		else
		figura->poljeUKuci += brojPomaka - 1;
		if(figura->poljeUKuci == zadnjeSlobodnoMjestoUKuci)
			--zadnjeSlobodnoMjestoUKuci;
		return true;
	}
	return false;
}

Boja Igrac::vratiBoju()
{
	return figure[0].vratiBoju();
}
