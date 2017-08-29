#include "stdafx.h"
#include "Figura.h"


Figura::Figura(Boja b, byte p, byte c)
{
	boja = b;
	poljeUKući = -1;
	početak = p;
	cilj = c;
	for (int i = početak; i != cilj; ++i)
		trenutnoPolje.push_back(i % 40);

}


Figura::~Figura()
{
}

Boja Figura::vratiBoju()
{
	return boja;
}

byte Figura::vratiPočetnuTočku()
{
	return početak;
}

byte Figura::vratiZavršnuTočku()
{
	return cilj;
}
