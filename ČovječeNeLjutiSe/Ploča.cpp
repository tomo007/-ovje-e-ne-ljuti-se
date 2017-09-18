#include "stdafx.h"
#include "Plo�a.h"


Plo�a::Plo�a()
{
	for (int i = 0; i < 40; ++i)
		polje[i] = nullptr;
}


Plo�a::~Plo�a()
{
	polje.clear();
}

void Plo�a::zauzmiPolje(Figura* figura, int trenutnoPolje)
{
	polje[trenutnoPolje] = figura;
}

Figura * Plo�a::provjeraPolja(int trenutnoPolje)
{
	return polje[trenutnoPolje];
}
