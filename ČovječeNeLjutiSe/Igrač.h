#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igrač
{
private:
	std::map<int, Figura*> kuća;
	int vratiPočetnoPolje(Boja boja);
	int vratiZadnjePolje(Boja boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje);
public:
	std::vector<Figura> figure;
	std::vector<Figura> figureNaPolju;
	byte zadnjeSlobodnoMjestoUKući;
	Igrač(Boja boja);
	~Igrač();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKuću(Figura* figura, int brojPomaka);
	Boja vratiBoju();
};

