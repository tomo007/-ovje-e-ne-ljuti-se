#include "stdafx.h"
#include "Figura.h"


Figura::Figura(Boja b, byte p, byte c)
{
	boja = b;
	poljeUKuæi = -1;
	poèetak = p;
	cilj = c;
	for (int i = poèetak; i != cilj;) {
		trenutnoPolje.push_back(i);
		i = (i % 40) + 1;
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

byte Figura::vratiPoèetnuToèku()
{
	return poèetak;
}

byte Figura::vratiZavršnuToèku()
{
	return cilj;
}
