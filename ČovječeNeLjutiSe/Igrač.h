#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igra�
{
private:
	
	int vratiPo�etnoPolje(Boja boja);
	int vratiZadnjePolje(Boja boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje,Figura f);
public:
	std::vector<Figura*> ku�a;
	int brojFiguraUKu�ici;
	int brojFiguraNaPolju;
	std::vector<Figura> figure;
	std::vector<Figura> figureNaPolju;
	byte zadnjeSlobodnoMjestoUKu�i;
	int brojFiguraUCilju;
	Igra�(Boja boja);
	Igra�();
	~Igra�();
	int vratiPo�etnoPolje();
	int vratiZadnjePolje();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKu�u(Figura* figura, int brojPomaka);
	Boja vratiBoju();
};

