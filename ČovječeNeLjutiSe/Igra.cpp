#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgraèa){
	for (int i = 0; i < brojIgraèa; ++i) {
		igraèi.push_back(Igraè(vratiBojuIgraèa(i)));
	}
	indeksIgraèa = 0;
	indeksZauzetogPolja = -1;
	indeksIgracaNaZauzetomPolju = -1;
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
bool Igra::pomakniFiguruNaPoèetnoPolje(Igraè* trenutniIgraè)
{
	if (trenutniIgraè->figure.size() > 0) {
		Figura f = trenutniIgraè->figure.back();
		trenutniIgraè->figureNaPolju.push_back(f);
		if (trenutniIgraè->figure.size() > 1) {
			trenutniIgraè->figure.pop_back();
		}
		else {
			trenutniIgraè->figure.clear();
		}
		++trenutniIgraè->brojFiguraNaPolju;
		--trenutniIgraè->brojFiguraUKuèici;
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
		indeksIgraèa = 1;
		return igraèi[1];
	case Boja::PLAVA:
		if (brojIgraèa <= 2) {
			indeksIgraèa = 0;
			return igraèi.front();
		}else {
			indeksIgraèa = 2;
			return igraèi[2];
		}
	case Boja::ZELENA:
		if (brojIgraèa <= 3) {
			indeksIgraèa = 0;
			return igraèi.front();
		}else
			indeksIgraèa = 3;
			return igraèi[3];
	case Boja::ZUTA:
		indeksIgraèa = 0;
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
	int staroPoljeUKuci = figura->poljeUKuæi;
	if (trenutniIgraè->pomakni(figura, brojPomaka)) {
		if (figura->vratiTrenutnoPolje() > 6) {
			oslobodiPolje((figura->vratiTrenutnoPolje() - brojPomaka));
		}
		else {
			switch (figura->vratiTrenutnoPolje()) {
			case 0:
				oslobodiPolje(40 - brojPomaka);
				break;
			case 1:
				oslobodiPolje(41 - brojPomaka);
				break;
			case 2:
				oslobodiPolje(42 - brojPomaka);
				break;
			case 3:
				oslobodiPolje(43 - brojPomaka);
				break;
			case 4:
				oslobodiPolje(44 - brojPomaka);
				break;
			case 5:
				oslobodiPolje(45 - brojPomaka);
				break;
			case 6:
				oslobodiPolje(0);
				break;
			default:
				break;
			}
		}
		if (figura->poljeUKuæi <= -1) {
			Figura* figuraNaTomPolju = ploèa.provjeraPolja(figura->vratiTrenutnoPolje());
			if (figuraNaTomPolju != nullptr) {
				poljeJeZauzeto = true;
				oslobodiPolje(figuraNaTomPolju);
				ploèa.zauzmiPolje(figura, figura->vratiTrenutnoPolje());
			}
			ploèa.zauzmiPolje(figura, figura->vratiTrenutnoPolje());
			return true;
		}
	}if(staroPoljeUKuci!=figura->poljeUKuæi)
		return true;
	return false;
	
}

void Igra::oslobodiPolje(Figura * figura)
{
	namjestiIndeksIgraèaNaZauzetomPolju(figura);
	std::vector<Figura> v = igraèi[indeksIgracaNaZauzetomPolju].figureNaPolju;
	auto it = std::find(v.begin(), v.end(),*figura);
	indeksZauzetogPolja = std::distance(v.begin(), it);
	if (igraèi[indeksIgracaNaZauzetomPolju].brojFiguraNaPolju > 1) {
		igraèi[indeksIgracaNaZauzetomPolju].figureNaPolju.erase(v.begin() + (indeksZauzetogPolja-1));
	}
	else {
		igraèi[indeksIgracaNaZauzetomPolju].figureNaPolju.clear();
	}
	--igraèi[indeksIgracaNaZauzetomPolju].brojFiguraNaPolju;
	igraèi[indeksIgracaNaZauzetomPolju].figure.push_back(Figura(figura->vratiBoju(),figura->vratiPoèetnuToèku(),figura->vratiZavršnuToèku()));
	++igraèi[indeksIgracaNaZauzetomPolju].brojFiguraUKuèici;

}

void Igra::oslobodiPolje(int polje)
{
	ploèa.zauzmiPolje(nullptr, polje);
}

void Igra::namjestiIndeksIgraèaNaZauzetomPolju(Figura* figura)
{
	for (auto igrac : igraèi)
	{
		for (auto f : igrac.figureNaPolju) {
			if (f == *figura)
				promjeniIndeksIgraèaNaZauzetomPolju(igrac);
		}
	}
}

Igraè Igra::prviIgraè()
{
	return igraèi.front();
}

void Igra::vratiPromjeneNakonZauzetoPolja()
{
	poljeJeZauzeto = false;
	indeksZauzetogPolja = -1;
	indeksIgracaNaZauzetomPolju = -1;
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

void Igra::promjeniIndeksIgraèaNaZauzetomPolju(Igraè igraè)
{
	switch (igraè.vratiBoju()) {
	case Boja::CRVENA:
		indeksIgracaNaZauzetomPolju =0;
		break;
	case Boja::PLAVA:
		indeksIgracaNaZauzetomPolju = 1;
		break;
	case Boja::ZELENA:
		indeksIgracaNaZauzetomPolju = 2;
		break;
	case Boja::ZUTA:
		indeksIgracaNaZauzetomPolju = 3;
		break;
	default:
		break;
	}
}
