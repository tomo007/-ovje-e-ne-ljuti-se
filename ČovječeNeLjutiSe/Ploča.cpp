#include "stdafx.h"
#include "Plo�a.h"


Plo�a::Plo�a()
{
}


Plo�a::~Plo�a()
{
	for (int i = 0; i < 40; ++i)
		polje[i] = nullptr;
}

void Plo�a::zauzmiPolje(Figura* figura, int trenutnoPolje)
{
	polje.at(trenutnoPolje) = figura;
}

Figura * Plo�a::provjeraPolja(int trenutnoPolje)
{
	std::map<int, Figura*>::const_iterator it;
	it = polje.find(trenutnoPolje);
	return it->second;
}
