#pragma once
#include "Ploèa.h"
#include "Igraè.h"
#include "Figura.h"
#include <time.h> 
#include <vector>
class Igra
{
private:
	Ploèa* ploèa;
	std::vector<Igraè*> igraèi;
	Boja vratiBojuIgraèa(int i);
public:
	Igra(byte brojIgraèa);
	~Igra();
	int bacajKocku();
	Igraè* promjenaIgraèa(Igraè* trenutniIgraè);
	std::vector<Figura *> izaberiFiguru(Igraè* trenutniIgraè, int dobivenBrojSKocke);
	bool pomakniFiguru(Igraè* trenutniIgraè,Figura* figura, int brojPomaka);
};

