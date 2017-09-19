#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgraca){
	for (int i = 0; i < brojIgraca; ++i) {
		igraci.push_back(Igrac(vratiBojuIgraca(i)));
	}
	indeksIgraca = 0;
	indeksZauzetogPolja = -1;
	indeksIgracaNaZauzetomPolju = -1;
}


Igra::~Igra()
{
}
std::vector<Igrac> Igra::vratiIgrace()
{
	return igraci;
}
int Igra::brojBacanjaKocke(Igrac trenutniIgrac)
{
	if (trenutniIgrac.figureNaPolju.size() == 0)
		return 3;
	return 1;
}
bool Igra::pomakniFiguruNaPocetnoPolje(Igrac* trenutniIgrac)
{
	if (trenutniIgrac->figure.size() > 0) {
		Figura f = trenutniIgrac->figure.back();
		trenutniIgrac->figureNaPolju.push_back(f);
		if (trenutniIgrac->figure.size() > 1) {
			trenutniIgrac->figure.pop_back();
		}
		else {
			trenutniIgrac->figure.clear();
		}
		++trenutniIgrac->brojFiguraNaPolju;
		--trenutniIgrac->brojFiguraUKucici;
		return true;
	}
	else
		return false;
}
Igrac Igra::promjenaIgraca(Igrac * trenutniIgrac)
{	
	Boja bojaTrenutnogIgraca = trenutniIgrac->vratiBoju();
	int brojIgraca = igraci.size();
	switch (bojaTrenutnogIgraca) 
	{
	case Boja::CRVENA:
		indeksIgraca = 1;
		return igraci[1];
	case Boja::PLAVA:
		if (brojIgraca <= 2) {
			indeksIgraca = 0;
			return igraci.front();
		}else {
			indeksIgraca = 2;
			return igraci[2];
		}
	case Boja::ZELENA:
		if (brojIgraca <= 3) {
			indeksIgraca = 0;
			return igraci.front();
		}else
			indeksIgraca = 3;
			return igraci[3];
	case Boja::ZUTA:
		indeksIgraca = 0;
		return igraci.front();
	}
	
}

std::vector<Figura> Igra::izaberiFiguru(Igrac * trenutniIgrac, int dobivenBrojSKocke)
{
	if (dobivenBrojSKocke == 6)
		return trenutniIgrac->figure;
	else
		return trenutniIgrac->figureNaPolju;
}

bool Igra::pomakniFiguru(Igrac* trenutniIgrac, Figura* figura, int brojPomaka)
{
	int staroPoljeUKuci = figura->poljeUKuci;
	if (trenutniIgrac->pomakni(figura, brojPomaka)) {
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
		if (figura->poljeUKuci <= -1) {
			Figura* figuraNaTomPolju = ploca.provjeraPolja(figura->vratiTrenutnoPolje());
			if (figuraNaTomPolju != nullptr) {
				poljeJeZauzeto = true;
				oslobodiPolje(figuraNaTomPolju);
				ploca.zauzmiPolje(figura, figura->vratiTrenutnoPolje());
			}
			ploca.zauzmiPolje(figura, figura->vratiTrenutnoPolje());
			return true;
		}
	}if(staroPoljeUKuci!=figura->poljeUKuci)
		return true;
	return false;
	
}

void Igra::oslobodiPolje(Figura * figura)
{
	namjestiIndeksIgracaNaZauzetomPolju(figura);
	std::vector<Figura> v = igraci[indeksIgracaNaZauzetomPolju].figureNaPolju;
	auto it = std::find(v.begin(), v.end(),*figura);
	indeksZauzetogPolja = std::distance(v.begin(), it);
	if (igraci[indeksIgracaNaZauzetomPolju].brojFiguraNaPolju > 1) {
		igraci[indeksIgracaNaZauzetomPolju].figureNaPolju.erase(v.begin() + (indeksZauzetogPolja-1));
	}
	else {
		igraci[indeksIgracaNaZauzetomPolju].figureNaPolju.clear();
	}
	--igraci[indeksIgracaNaZauzetomPolju].brojFiguraNaPolju;
	igraci[indeksIgracaNaZauzetomPolju].figure.push_back(Figura(figura->vratiBoju(),figura->vratiPocetnuTocku(),figura->vratiZavrsnuTocku()));
	++igraci[indeksIgracaNaZauzetomPolju].brojFiguraUKucici;

}

void Igra::oslobodiPolje(int polje)
{
	ploca.zauzmiPolje(nullptr, polje);
}

void Igra::namjestiIndeksIgracaNaZauzetomPolju(Figura* figura)
{
	for (auto igrac : igraci)
	{
		for (auto f : igrac.figureNaPolju) {
			if (f == *figura)
				promjeniIndeksIgracaNaZauzetomPolju(igrac);
		}
	}
}

Igrac Igra::prviIgrac()
{
	return igraci.front();
}

void Igra::vratiPromjeneNakonZauzetoPolja()
{
	poljeJeZauzeto = false;
	indeksZauzetogPolja = -1;
	indeksIgracaNaZauzetomPolju = -1;
}

Boja Igra::vratiBojuIgraca(int i)
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

void Igra::promjeniIndeksIgracaNaZauzetomPolju(Igrac igrac)
{
	switch (igrac.vratiBoju()) {
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
