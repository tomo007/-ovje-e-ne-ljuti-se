#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
#include <vector>
class Igra�
{
private:
	byte figureUKu�i;
	std::map<int, Figura*> ku�a;
	int vratiPo�etnoPolje(Boja boja);
	int vratiZadnjePolje(Boja boja);
	bool provjeraZaPreskakanjeFigura(int zadanoPolje);
public:
	std::vector<Figura*> figure;
	std::vector<Figura*> figureNaPolju;
	Igra�(Boja boja);
	~Igra�();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKu�u(Figura* figura, int brojPomaka);
	Boja vratiBoju();
};

