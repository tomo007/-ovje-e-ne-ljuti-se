#pragma once
class Figura
{
private:
	byte naziv;
	char boja;
	byte po�etak,cilj;
public: int trenutnoPolje;
		int poljeUKu�i;
public:
	Figura(char b, byte p, byte c);
	~Figura();
	char vratiBoju();
	byte vratiPo�etnuTo�ku();
	byte vratiZavr�nuTo�ku();
};

