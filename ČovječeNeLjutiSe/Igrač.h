#pragma once
#include "Figura.h"
#include <stdio.h>
#include <map>
class Igra�
{
private:
	Figura* figure[4];
	Figura* figureNaPolju[4];
	std::map<int, Figura*> ku�a;
	int vratiPo�etnoPolje(char boja);
	int vratiZadnjePolje(char boja);
public:
	Igra�(char boja);
	~Igra�();
	void move(Figura* figura,int brojPomaka);
};

