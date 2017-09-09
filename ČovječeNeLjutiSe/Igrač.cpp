#include "stdafx.h"
#include "Igrač.h"


int Igrač::vratiPočetnoPolje(Boja boja)
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

int Igrač::vratiZadnjePolje(Boja boja)
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

bool Igrač::provjeraZaPreskakanjeFigura(int zadanoPolje)
{
	int brojFiguraNaPolju = figureNaPolju.size();
	for (int i = 0; i < brojFiguraNaPolju; ++i) {
			if (figureNaPolju[i].trenutnoPolje.front() <= zadanoPolje)
				return false;
	}
	return true;
}

Igrač::Igrač(Boja boja)
{
	for (int i = 0; i < 4; ++i) {
		figure.push_back(Figura(boja, vratiPočetnoPolje(boja), vratiZadnjePolje(boja)));
		kuća.push_back(nullptr);
	}
	zadnjeSlobodnoMjestoUKući = 4;
	brojFiguraNaPolju = 0;
	brojFiguraUCilju = 0;
}

Igrač::Igrač()
{
}




Igrač::~Igrač()
{
}

int Igrač::vratiPočetnoPolje()
{
	return figure[0].vratiPočetnuTočku();
}

int Igrač::vratiZadnjePolje()
{
	return figure[0].vratiZavršnuTočku();;
}

bool Igrač::pomakni(Figura * figura, int brojPomaka)
{	
	int novoPolje = figura->trenutnoPolje.front() + brojPomaka;
	int zadnjePolje = figura->vratiZavršnuTočku();

	if(figura->trenutnoPolje.size()<brojPomaka)
		return pomakniUKuću(figura, novoPolje - zadnjePolje);
	else {
		for (int i = 0; i < brojPomaka; ++i)
			figura->trenutnoPolje.pop_front();
	}
	return true;
}

bool Igrač::pomakniUKuću(Figura * figura, int brojPomaka)
{
	int brojFiguraNaPolju = figureNaPolju.size();
	if (brojPomaka <= 4) {
		for (int i = 0; i < brojFiguraNaPolju; ++i) {
				if (figureNaPolju[i].poljeUKući <= brojPomaka)
						return false;
		}
		if ((figura->poljeUKući + brojPomaka - 1) > zadnjeSlobodnoMjestoUKući)
			return false;
		kuća.at(brojPomaka - 1) = figura;
		++brojFiguraUCilju;
		figura->poljeUKući += brojPomaka - 1;
		if(figura->poljeUKući == zadnjeSlobodnoMjestoUKući)
			--zadnjeSlobodnoMjestoUKući;
		return true;
	}
	return false;
}

Boja Igrač::vratiBoju()
{
	return figure[0].vratiBoju();
}
