#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igraè
{
private:
	std::map<int, Figura*> kuæa;
	int vratiPoèetnoPolje(char boja);
	int vratiZadnjePolje(char boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje);
public:
	std::vector<Figura*> figure;
	std::vector<Figura*> figureNaPolju;
	Igraè(char boja);
	~Igraè();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKuæu(Figura* figura, int brojPomaka);
	char vratiBoju();
};

