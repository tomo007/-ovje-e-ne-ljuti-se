#include "stdafx.h"
#include "Figura.h"


Figura::Figura(Boja b, byte p, byte c)
{
	boja = b;
	trenutnoPolje = -1;
	poljeUKuæi = -1;
	poèetak = p;
	cilj = c;

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
