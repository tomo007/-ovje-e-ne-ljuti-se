#pragma once
#include "Ploèa.h"
#include "Igraè.h"
#include "Figura.h"
#include <time.h> 
#include <vector>
class Igra
{
private:
	Ploèa ploèa;
	Boja vratiBojuIgraèa(int i);
	void promjeniIndeksIgraèa(Igraè igraè);
public:
	Igra(byte brojIgraèa);
	~Igra();
	std::vector<Igraè> igraèi;
	std::vector<Igraè> vratiIgraèe();
	int brojBacanjaKocke(Igraè trenutniIgraè);
	int indeksIgraèa;
	bool pomakniFiguruNaPoèetnoPolje(Igraè* trenutniIgraè);
	Igraè promjenaIgraèa(Igraè* trenutniIgraè);
	std::vector<Figura> izaberiFiguru(Igraè* trenutniIgraè, int dobivenBrojSKocke);
	bool pomakniFiguru(Igraè* trenutniIgraè,Figura* figura, int brojPomaka);
	void oslobodiPolje(Figura* figura);
	Igraè* dajIgraèaSTomFigurom(Figura* figura);
	Igraè prviIgraè();
};

