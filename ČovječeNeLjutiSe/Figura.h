#pragma once
#include "Boja.h"
class Figura
{
private:

	byte naziv;
	Boja boja;
	byte početak,cilj;
public: int trenutnoPolje;
		int poljeUKući;
public:
	Figura(Boja b, byte p, byte c);
	~Figura();
	Boja vratiBoju();
	byte vratiPočetnuTočku();
	byte vratiZavršnuTočku();
};

