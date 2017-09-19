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
		int poljeUKuci;
public:
	Figura(Boja b, byte p, byte c);
	Figura();
	~Figura();
	Boja vratiBoju();
	byte vratiTrenutnoPolje();
	byte vratiPocetnuTocku();
	byte vratiZavrsnuTocku();
	void pomakni();
	bool operator== (Figura fig);
};

