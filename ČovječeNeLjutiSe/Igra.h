#pragma once
#include "Ploèa.h"
#include "Igraè.h"
#include <time.h> 
class Igra
{
private:
	Ploèa* ploèa;
	Igraè* igraèi[4];
	char vratiBojuIgraèa(int i);
public:
	Igra(byte brojIgraèa);
	~Igra();
	int bacajKocku();
	Igraè* promjenaIgraèa(Igraè* trenutniIgraè);
	Figura** izaberiFiguru(Igraè* trenutniIgraè, int dobivenBrojSKocke);
	bool pomakniFiguru(Igraè* trenutniIgraè,Figura* figura, int brojPomaka);
};

