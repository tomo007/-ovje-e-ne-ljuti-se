#pragma once
class Figura
{
private:
	byte naziv;
	char boja;
	byte poèetak,cilj;
public: int trenutnoPolje;
		int poljeUKuæi;
public:
	Figura(char b, byte p, byte c);
	~Figura();
	char vratiBoju();
	byte vratiPoèetnuToèku();
	byte vratiZavršnuToèku();
};

