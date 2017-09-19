#pragma once
#include "Ploca.h"
#include "Igrac.h"
#include "Figura.h"
#include <time.h> 
#include <vector>
class Igra
{
private:
	Ploca ploca;
	Boja vratiBojuIgraca(int i);
	void promjeniIndeksIgracaNaZauzetomPolju(Igrac igrac);
public:
	bool poljeJeZauzeto = false;
	int indeksZauzetogPolja;
	int indeksIgracaNaZauzetomPolju;
	Igra(byte brojIgraca);
	~Igra();
	std::vector<Igrac> igraci;
	std::vector<Igrac> vratiIgrace();
	int brojBacanjaKocke(Igrac trenutniIgrac);
	int indeksIgraca;
	bool pomakniFiguruNaPocetnoPolje(Igrac* trenutniIgrac);
	Igrac promjenaIgraca(Igrac* trenutniIgrac);
	std::vector<Figura> izaberiFiguru(Igrac* trenutniIgrac, int dobivenBrojSKocke);
	bool pomakniFiguru(Igrac* trenutniIgrac,Figura* figura, int brojPomaka);
	void oslobodiPolje(Figura* figura);
	void oslobodiPolje(int polje);
	void namjestiIndeksIgracaNaZauzetomPolju(Figura* figura);
	Igrac prviIgrac();
	void vratiPromjeneNakonZauzetoPolja();
};

