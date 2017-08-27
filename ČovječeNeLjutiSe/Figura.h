#pragma once
class Figura
{
private:
	byte naziv;
	char boja;
	byte poèetak,cilj,trenutnoPolje;
public:
	Figura(char boja,byte poèetak,byte cilj);
	~Figura();
};

