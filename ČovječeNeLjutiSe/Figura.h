#pragma once
#include "Boja.h"
#include <deque>
class Figura
{
private:
	byte naziv;
	Boja boja;
	byte poèetak,cilj;
public: std::deque<int> trenutnoPolje;
		int poljeUKuæi;
public:
	Figura(Boja b, byte p, byte c);
	Figura();
	~Figura();
	Boja vratiBoju();
	byte vratiTrenutnoPolje();
	byte vratiPoèetnuToèku();
	byte vratiZavršnuToèku();
	void pomakni();
	bool operator== (Figura fig);
};

