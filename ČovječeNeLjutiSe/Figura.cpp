#include "stdafx.h"
#include "Figura.h"


Figura::Figura(Boja b, byte p, byte c)
{
	boja = b;
	poljeUKuci = -1;
	pocetak = p;
	cilj = c;
	for (int i = pocetak; i != cilj;) {
		trenutnoPolje.push_back(i);
		i = (i + 1 )% 40 ;
	}
}

Figura::Figura()
{
}


Figura::~Figura()
{
}

Boja Figura::vratiBoju()
{
	return boja;
}

byte Figura::vratiTrenutnoPolje()
{
	return trenutnoPolje.front();
}

byte Figura::vratiPocetnuTocku()
{
	return pocetak;
}

byte Figura::vratiZavrsnuTocku()
{
	return cilj;
}

void Figura::pomakni()
{
	if(trenutnoPolje.size()>0)
		trenutnoPolje.pop_front();
}

bool Figura::operator==(Figura fig)
{
	if (this->boja == fig.boja)
		if (this->trenutnoPolje.front() == fig.trenutnoPolje.front())
			return true;
	return false;
}


