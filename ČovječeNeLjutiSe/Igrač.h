#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
class Igra�
{
private:
	std::map<int, Figura*> ku�a;
	int vratiPo�etnoPolje(char boja);
	int vratiZadnjePolje(char boja);
public:
	Figura* figure[4];
	Figura* figureNaPolju[4];
	Igra�(char boja);
	~Igra�();
	bool pomakni(Figura* figura,int brojPomaka);
	bool pomakniUKu�u(Figura* figura, int brojPomaka);
	char vratiBoju();
};

