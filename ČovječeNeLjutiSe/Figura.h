#pragma once
#include "Boja.h"
class Figura
{
private:

	byte naziv;
	Boja boja;
	byte po�etak,cilj;
public: int trenutnoPolje;
		int poljeUKu�i;
public:
	Figura(Boja b, byte p, byte c);
	~Figura();
	Boja vratiBoju();
	byte vratiPo�etnuTo�ku();
	byte vratiZavr�nuTo�ku();
};

