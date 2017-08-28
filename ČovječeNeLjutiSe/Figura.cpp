#include "stdafx.h"
#include "Figura.h"


Figura::Figura(char b, byte p, byte c)
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

char Figura::vratiBoju()
{
	return Figura::boja;
}

byte Figura::vratiPočetnuTočku()
{
	return početak;
}

byte Figura::vratiZavršnuTočku()
{
	return cilj;
}
