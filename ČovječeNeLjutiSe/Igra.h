#pragma once
#include "Plo�a.h"
#include "Igra�.h"
#include "Figura.h"
#include <time.h> 
#include <vector>
class Igra
{
private:
	Plo�a plo�a;
	Boja vratiBojuIgra�a(int i);
	void promjeniIndeksIgra�aNaZauzetomPolju(Igra� igra�);
public:
	bool poljeJeZauzeto = false;
	int indeksZauzetogPolja;
	int indeksIgracaNaZauzetomPolju;
	Igra(byte brojIgra�a);
	~Igra();
	std::vector<Igra�> igra�i;
	std::vector<Igra�> vratiIgra�e();
	int brojBacanjaKocke(Igra� trenutniIgra�);
	int indeksIgra�a;
	bool pomakniFiguruNaPo�etnoPolje(Igra�* trenutniIgra�);
	Igra� promjenaIgra�a(Igra�* trenutniIgra�);
	std::vector<Figura> izaberiFiguru(Igra�* trenutniIgra�, int dobivenBrojSKocke);
	bool pomakniFiguru(Igra�* trenutniIgra�,Figura* figura, int brojPomaka);
	void oslobodiPolje(Figura* figura);
	void oslobodiPolje(int polje);
	void namjestiIndeksIgra�aNaZauzetomPolju(Figura* figura);
	Igra� prviIgra�();
	void vratiPromjeneNakonZauzetoPolja();
};

