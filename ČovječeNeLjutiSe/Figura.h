#pragma once
#include "Boja.h"
#include <deque>
class Figura
{
private:
	byte naziv;
	Boja boja;
	byte početak,cilj;
public: std::deque<int> trenutnoPolje;
		int poljeUKući;
public:
	Figura(Boja b, byte p, byte c);
	~Figura();
	Boja vratiBoju();
	byte vratiPočetnuTočku();
	byte vratiZavršnuTočku();
};

