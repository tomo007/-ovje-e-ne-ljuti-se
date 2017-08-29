#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igraè
{
private:
	byte figureUKuæi;
	std::map<int, Figura*> kuæa;
	int vratiPoèetnoPolje(Boja boja);
	int vratiZadnjePolje(Boja boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje);
public:
	std::vector<Figura*> figure;
	std::vector<Figura*> figureNaPolju;
	Igraè(Boja boja);
	~Igraè();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKuæu(Figura* figura, int brojPomaka);
	Boja vratiBoju();
};

