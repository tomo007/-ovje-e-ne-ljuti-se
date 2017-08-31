#include "stdafx.h"
#include "Figura.h"


Figura::Figura(Boja b, byte p, byte c)
{
	boja = b;
	poljeUKu�i = -1;
	po�etak = p;
	cilj = c;
	for (int i = po�etak; i != cilj;) {
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

byte Figura::vratiPo�etnuTo�ku()
{
	return po�etak;
}

byte Figura::vratiZavr�nuTo�ku()
{
	return cilj;
}
