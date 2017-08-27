#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
class Igraè
{
private:
	Figura* figure[4];
	Figura* figureNaPolju[4];
	std::map<int, Figura*> kuæa;
	int vratiPoèetnoPolje(char boja);
	int vratiZadnjePolje(char boja);
public:
	Igraè(char boja);
	~Igraè();
	void move(Figura* figura,int brojPomaka);
};

