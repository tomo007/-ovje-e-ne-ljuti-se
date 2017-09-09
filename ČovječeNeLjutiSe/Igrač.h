#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igrač
{
private:
	std::vector<Figura*> kuća;
	int vratiPočetnoPolje(Boja boja);
	int vratiZadnjePolje(Boja boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje);
public:
	int brojFiguraNaPolju;
	std::vector<Figura> figure;
	std::vector<Figura> figureNaPolju;
	byte zadnjeSlobodnoMjestoUKući;
	int brojFiguraUCilju;
	Igrač(Boja boja);
	Igrač();
	~Igrač();
	int vratiPočetnoPolje();
	int vratiZadnjePolje();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKuću(Figura* figura, int brojPomaka);
	Boja vratiBoju();
};

