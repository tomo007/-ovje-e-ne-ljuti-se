#pragma once
#include <stdio.h>
#include "Figura.h"
#include <map>
class Ploèa
{
private:
	std::map<int, Figura*> polje;
public:
	Ploèa();
	virtual ~Ploèa();
	void zauzmiPolje(Figura* figura,int trenutnoPolje);
	Figura* provjeraPolja(int trenutnoPolje);
};

