#pragma once
class Figura
{
private:
	byte naziv;
	char boja;
	byte početak,cilj;
public: int trenutnoPolje;
		int poljeUKući;
public:
	Figura(char b, byte p, byte c);
	~Figura();
	char vratiBoju();
	byte vratiPočetnuTočku();
	byte vratiZavršnuTočku();
};

