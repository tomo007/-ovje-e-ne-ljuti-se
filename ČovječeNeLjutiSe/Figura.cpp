#include "stdafx.h"
#include "Figura.h"


Figura::Figura(Boja b, byte p, byte c)
{
	boja = b;
	trenutnoPolje = -1;
	poljeUKu�i = -1;
	po�etak = p;
	cilj = c;

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
