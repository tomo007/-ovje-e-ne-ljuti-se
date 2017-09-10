#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgraèa){
	for (int i = 0; i < brojIgraèa; ++i) {
		igraèi.push_back(Igraè(vratiBojuIgraèa(i)));
	}
	indeksIgraèa = 0;
}


Igra::~Igra()
{
}
std::vector<Igraè> Igra::vratiIgraèe()
{
	return igraèi;
}
int Igra::brojBacanjaKocke(Igraè trenutniIgraè)
{
	if (trenutniIgraè.figureNaPolju.size() == 0)
		return 3;
	return 1;
}
bool Igra::pomakniFiguruNaPoèetnoPolje(Igraè trenutniIgraè)
{
	if (trenutniIgraè.figure.size() > 0) {
		trenutniIgraè.figureNaPolju.push_back(trenutniIgraè.figure.back());
		trenutniIgraè.figureNaPolju.back().pomakni();
		trenutniIgraè.figure.pop_back();
		return true;
	}
	else
		return false;
}
Igraè Igra::promjenaIgraèa(Igraè * trenutniIgraè)
{	
	Boja bojaTrenutnogIgraèa = trenutniIgraè->vratiBoju();
	int brojIgraèa = igraèi.size();
	switch (bojaTrenutnogIgraèa) 
	{
	case Boja::CRVENA:
		indeksIgraèa = 2;
		return igraèi[1];
	case Boja::PLAVA:
		if (brojIgraèa <= 2) {
			indeksIgraèa = 1;
			return igraèi.front();
		}else {
			indeksIgraèa = 3;
			return igraèi[2];
		}
	case Boja::ZELENA:
		if (brojIgraèa <= 3) {
			indeksIgraèa = 1;
			return igraèi.front();
		}else
			indeksIgraèa = 4;
			return igraèi[3];
	case Boja::ZUTA:
		indeksIgraèa = 1;
		return igraèi.front();
	}
	
}

std::vector<Figura> Igra::izaberiFiguru(Igraè * trenutniIgraè, int dobivenBrojSKocke)
{
	if (dobivenBrojSKocke == 6)
		return trenutniIgraè->figure;
	else
		return trenutniIgraè->figureNaPolju;
}

bool Igra::pomakniFiguru(Igraè* trenutniIgraè, Figura* figura, int brojPomaka)
{
	bool flagFiguraNaPolju = false;
	for each (Figura var in trenutniIgraè->figureNaPolju)
	{
		if (var == *figura) {
			flagFiguraNaPolju = true;
			break;
		}
	}
	if (!flagFiguraNaPolju){
		trenutniIgraè->figureNaPolju.push_back(*figura);
		++trenutniIgraè->brojFiguraNaPolju;
	}
	if (trenutniIgraè->pomakni(figura, brojPomaka)) {
		Figura* figuraNaTomPolju = ploèa.provjeraPolja(figura->trenutnoPolje.front());
		if (figuraNaTomPolju != nullptr) {
			oslobodiPolje(figuraNaTomPolju);
			figuraNaTomPolju = new Figura(figuraNaTomPolju->vratiBoju(), figuraNaTomPolju->vratiPoèetnuToèku(), figuraNaTomPolju->vratiZavršnuToèku());
			ploèa.zauzmiPolje(figura, figura->trenutnoPolje.front());
		}
		if (trenutniIgraè->zadnjeSlobodnoMjestoUKuæi == 0)
			return true;
	}
	return false;
}

void Igra::oslobodiPolje(Figura * figura)
{
	Igraè* igraè = dajIgraèaSTomFigurom(figura);
	std::vector<Figura> v = igraè->figureNaPolju;
	igraè->figureNaPolju.erase(std::find(v.begin(), v.end(), figura));
	--igraè->brojFiguraNaPolju;
	igraè->figure.push_back(*figura);

}

Igraè* Igra::dajIgraèaSTomFigurom(Figura* figura)
{
	for each (Igraè var in igraèi)
	{
		if (figura->vratiBoju() == var.vratiBoju())
			return &var;
	}
	return nullptr;
}

Igraè Igra::prviIgraè()
{
	return igraèi.front();
}

Boja Igra::vratiBojuIgraèa(int i)
{
	switch (i) {
	case 0:
		return Boja::CRVENA;
	case 1:
		return Boja::PLAVA;
	case 2:
		return Boja::ZELENA;
	case 3:
		return Boja::ZUTA;
	default:
		break;
	}
}

void Igra::promjeniIndeksIgraèa(Igraè igraè)
{
	switch (igraè.vratiBoju()) {
	case Boja::CRVENA:
		indeksIgraèa=1;
		break;
	case Boja::PLAVA:
		indeksIgraèa = 2;
		break;
	case Boja::ZELENA:
		indeksIgraèa = 3;
		break;
	case Boja::ZUTA:
		indeksIgraèa = 4;
		break;
	default:
		break;
	}
}
