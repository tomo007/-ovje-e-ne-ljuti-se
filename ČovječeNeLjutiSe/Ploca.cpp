#include "stdafx.h"
#include "Ploca.h"


Ploca::Ploca()
{
	for (int i = 0; i < 40; ++i)
		polje[i] = nullptr;
}


Ploca::~Ploca()
{
	polje.clear();
}

void Ploca::zauzmiPolje(Figura* figura, int trenutnoPolje)
{
	polje[trenutnoPolje] = figura;
}

Figura * Ploca::provjeraPolja(int trenutnoPolje)
{
	return polje[trenutnoPolje];
}
