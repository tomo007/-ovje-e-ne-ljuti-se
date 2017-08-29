#include "stdafx.h"
#include "Figura.h"


Figura::Figura(Boja b, byte p, byte c)
{
	boja = b;
	trenutnoPolje = -1;
	poljeUKući = -1;
	početak = p;
	cilj = c;

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
