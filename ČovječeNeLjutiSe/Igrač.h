#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igraè
{
private:
	
	int vratiPoèetnoPolje(Boja boja);
	int vratiZadnjePolje(Boja boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje,Figura f);
public:
	std::vector<Figura*> kuæa;
	int brojFiguraUKuèici;
	int brojFiguraNaPolju;
	std::vector<Figura> figure;
	std::vector<Figura> figureNaPolju;
	byte zadnjeSlobodnoMjestoUKuæi;
	int brojFiguraUCilju;
	Igraè(Boja boja);
	Igraè();
	~Igraè();
	int vratiPoèetnoPolje();
	int vratiZadnjePolje();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKuæu(Figura* figura, int brojPomaka);
	Boja vratiBoju();
};

