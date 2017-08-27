#include "stdafx.h"
#include "Ploèa.h"


Ploèa::Ploèa()
{
}


Ploèa::~Ploèa()
{
	for (int i = 0; i < 40; ++i)
		Ploèa::polje[i] = nullptr;
}

void Ploèa::zauzmiPolje(Figura* figura, int trenutnoPolje)
{
	Ploèa::polje.at(trenutnoPolje) = figura;
}

Figura * Ploèa::provjeraPolja(int trenutnoPolje)
{
	std::map<int, Figura*>::const_iterator it;
	it = Ploèa::polje.find(trenutnoPolje);
	return it->second;
}
