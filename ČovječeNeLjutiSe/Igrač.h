#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igra�
{
private:
	std::vector<Figura*> ku�a;
	int vratiPo�etnoPolje(Boja boja);
	int vratiZadnjePolje(Boja boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje);
public:
	int brojFiguraNaPolju;
	std::vector<Figura> figure;
	std::vector<Figura> figureNaPolju;
	byte zadnjeSlobodnoMjestoUKu�i;
	Igra�(Boja boja);
	Igra�();
	~Igra�();
	int vratiPo�etnoPolje();
	int vratiZadnjePolje();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKu�u(Figura* figura, int brojPomaka);
	Boja vratiBoju();
};

