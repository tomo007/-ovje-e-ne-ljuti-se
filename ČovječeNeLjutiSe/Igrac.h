#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igrac
{
private:
	
	int vratiPocetnoPolje(Boja boja);
	int vratiZadnjePolje(Boja boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje,Figura f);
public:
	std::vector<Figura*> cilj;
	int brojFiguraUKucici;
	int brojFiguraNaPolju;
	std::vector<Figura> figure;
	std::vector<Figura> figureNaPolju;
	byte zadnjeSlobodnoMjestoUKuci;
	int brojFiguraUCilju;
	Igrac(Boja boja);
	Igrac();
	~Igrac();
	int vratiPocetnoPolje();
	int vratiZadnjePolje();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKucu(Figura* figura, int brojPomaka);
	Boja vratiBoju();
};

