#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
class Igraè
{
private:
	std::map<int, Figura*> kuæa;
	int vratiPoèetnoPolje(char boja);
	int vratiZadnjePolje(char boja);
public:
	Figura* figure[4];
	Figura* figureNaPolju[4];
	Igraè(char boja);
	~Igraè();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKuæu(Figura* figura, int brojPomaka);
	char vratiBoju();
};

