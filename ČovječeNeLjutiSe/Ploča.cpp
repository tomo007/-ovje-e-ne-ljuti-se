#include "stdafx.h"
#include "Ploèa.h"


Ploèa::Ploèa()
{
	for (int i = 0; i < 40; ++i)
		polje[i] = nullptr;
}


Ploèa::~Ploèa()
{
	polje.clear();
}

void Ploèa::zauzmiPolje(Figura* figura, int trenutnoPolje)
{
	polje.at(trenutnoPolje) = figura;
}

Figura * Ploèa::provjeraPolja(int trenutnoPolje)
{
	if (polje.find(trenutnoPolje) != polje.end())
		return polje.find(trenutnoPolje)->second;
	return nullptr;
}
