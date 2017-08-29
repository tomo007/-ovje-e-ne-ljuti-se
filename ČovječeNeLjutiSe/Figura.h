#pragma once
#include "Boja.h"
class Figura
{
private:

	byte naziv;
	Boja boja;
	byte poèetak,cilj;
public: int trenutnoPolje;
		int poljeUKuæi;
public:
	Figura(Boja b, byte p, byte c);
	~Figura();
	Boja vratiBoju();
	byte vratiPoèetnuToèku();
	byte vratiZavršnuToèku();
};

