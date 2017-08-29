#pragma once
#include "Boja.h"
#include <deque>
class Figura
{
private:
	byte naziv;
	Boja boja;
	byte po�etak,cilj;
public: std::deque<int> trenutnoPolje;
		int poljeUKu�i;
public:
	Figura(Boja b, byte p, byte c);
	~Figura();
	Boja vratiBoju();
	byte vratiPo�etnuTo�ku();
	byte vratiZavr�nuTo�ku();
};

