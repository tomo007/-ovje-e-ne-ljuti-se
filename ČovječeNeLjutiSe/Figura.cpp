#include "stdafx.h"
#include "Figura.h"


Figura::Figura(char b, byte p, byte c)
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

char Figura::vratiBoju()
{
	return Figura::boja;
}

byte Figura::vratiPo�etnuTo�ku()
{
	return po�etak;
}

byte Figura::vratiZavr�nuTo�ku()
{
	return cilj;
}
