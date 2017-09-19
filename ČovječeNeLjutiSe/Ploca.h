#pragma once
#include <stdio.h>
#include "Figura.h"
#include <map>
class Ploca
{
private:
	std::map<int, Figura*> polje;
public:
	Ploca();
	virtual ~Ploca();
	void zauzmiPolje(Figura* figura,int trenutnoPolje);
	Figura* provjeraPolja(int trenutnoPolje);
};

