#include "stdafx.h"
#include "Figura.h"


Figura::Figura(char boja, byte po�etak, byte cilj)
{
	Figura::boja = boja;
	Figura::trenutnoPolje = -1;
	Figura::po�etak = po�etak;
	Figura::cilj = cilj;

}


Figura::~Figura()
{
}
