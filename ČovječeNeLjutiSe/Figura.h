#pragma once
class Figura
{
private:
	byte naziv;
	char boja;
	byte po�etak,cilj,trenutnoPolje;
public:
	Figura(char boja,byte po�etak,byte cilj);
	~Figura();
};

