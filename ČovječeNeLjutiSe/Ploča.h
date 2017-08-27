#pragma once
#include <stdio.h>
#include "Figura.h"
#include <map>
class Plo�a
{
private:
	std::map<int, Figura*> polje;
public:
	Plo�a();
	virtual ~Plo�a();
	void zauzmiPolje(Figura* figura,int trenutnoPolje);
	Figura* provjeraPolja(int trenutnoPolje);
};

