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
			if (figureNaPolju[i]->trenutnoPolje.front() <= zadanoPolje)
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
	figureUKu�i = 0;


}


Igra�::~Igra�()
{
}

bool Igra�::pomakni(Figura * figura, int brojPomaka)
{	
	int novoPolje = figura->trenutnoPolje.front() + brojPomaka;
	int zadnjePolje = figura->vratiZavr�nuTo�ku();

	if(figura->trenutnoPolje.size()<brojPomaka)
		return pomakniUKu�u(figura, novoPolje - zadnjePolje);
	else {
		for (int i = 0; i < brojPomaka; ++i)
			figura->trenutnoPolje.pop_front();
	}
	return true;
}

bool Igra�::pomakniUKu�u(Figura * figura, int brojPomaka)
{
	if (figura->poljeUKu�i < 0)
		++figureUKu�i;
	if (brojPomaka <= 4) {
		for (int i = 0; i < 4; ++i) {
			if (figureNaPolju[i] != nullptr)
				if (figureNaPolju[i]->poljeUKu�i >= 0)
					if (figureNaPolju[i] != figura)
						return false;
		}
		if ((figura->poljeUKu�i + brojPomaka - 1) > 4)
			return false;
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
