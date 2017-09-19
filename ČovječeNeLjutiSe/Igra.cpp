#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgra�a){
	for (int i = 0; i < brojIgra�a; ++i) {
		igra�i.push_back(Igra�(vratiBojuIgra�a(i)));
	}
	indeksIgra�a = 0;
	indeksZauzetogPolja = -1;
	indeksIgracaNaZauzetomPolju = -1;
}


Igra::~Igra()
{
}
std::vector<Igra�> Igra::vratiIgra�e()
{
	return igra�i;
}
int Igra::brojBacanjaKocke(Igra� trenutniIgra�)
{
	if (trenutniIgra�.figureNaPolju.size() == 0)
		return 3;
	return 1;
}
bool Igra::pomakniFiguruNaPo�etnoPolje(Igra�* trenutniIgra�)
{
	if (trenutniIgra�->figure.size() > 0) {
		Figura f = trenutniIgra�->figure.back();
		trenutniIgra�->figureNaPolju.push_back(f);
		if (trenutniIgra�->figure.size() > 1) {
			trenutniIgra�->figure.pop_back();
		}
		else {
			trenutniIgra�->figure.clear();
		}
		++trenutniIgra�->brojFiguraNaPolju;
		--trenutniIgra�->brojFiguraUKu�ici;
		return true;
	}
	else
		return false;
}
Igra� Igra::promjenaIgra�a(Igra� * trenutniIgra�)
{	
	Boja bojaTrenutnogIgra�a = trenutniIgra�->vratiBoju();
	int brojIgra�a = igra�i.size();
	switch (bojaTrenutnogIgra�a) 
	{
	case Boja::CRVENA:
		indeksIgra�a = 1;
		return igra�i[1];
	case Boja::PLAVA:
		if (brojIgra�a <= 2) {
			indeksIgra�a = 0;
			return igra�i.front();
		}else {
			indeksIgra�a = 2;
			return igra�i[2];
		}
	case Boja::ZELENA:
		if (brojIgra�a <= 3) {
			indeksIgra�a = 0;
			return igra�i.front();
		}else
			indeksIgra�a = 3;
			return igra�i[3];
	case Boja::ZUTA:
		indeksIgra�a = 0;
		return igra�i.front();
	}
	
}

std::vector<Figura> Igra::izaberiFiguru(Igra� * trenutniIgra�, int dobivenBrojSKocke)
{
	if (dobivenBrojSKocke == 6)
		return trenutniIgra�->figure;
	else
		return trenutniIgra�->figureNaPolju;
}

bool Igra::pomakniFiguru(Igra�* trenutniIgra�, Figura* figura, int brojPomaka)
{
	int staroPoljeUKuci = figura->poljeUKu�i;
	if (trenutniIgra�->pomakni(figura, brojPomaka)) {
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
		if (figura->poljeUKu�i <= -1) {
			Figura* figuraNaTomPolju = plo�a.provjeraPolja(figura->vratiTrenutnoPolje());
			if (figuraNaTomPolju != nullptr) {
				poljeJeZauzeto = true;
				oslobodiPolje(figuraNaTomPolju);
				plo�a.zauzmiPolje(figura, figura->vratiTrenutnoPolje());
			}
			plo�a.zauzmiPolje(figura, figura->vratiTrenutnoPolje());
			return true;
		}
	}if(staroPoljeUKuci!=figura->poljeUKu�i)
		return true;
	return false;
	
}

void Igra::oslobodiPolje(Figura * figura)
{
	namjestiIndeksIgra�aNaZauzetomPolju(figura);
	std::vector<Figura> v = igra�i[indeksIgracaNaZauzetomPolju].figureNaPolju;
	auto it = std::find(v.begin(), v.end(),*figura);
	indeksZauzetogPolja = std::distance(v.begin(), it);
	if (igra�i[indeksIgracaNaZauzetomPolju].brojFiguraNaPolju > 1) {
		igra�i[indeksIgracaNaZauzetomPolju].figureNaPolju.erase(v.begin() + (indeksZauzetogPolja-1));
	}
	else {
		igra�i[indeksIgracaNaZauzetomPolju].figureNaPolju.clear();
	}
	--igra�i[indeksIgracaNaZauzetomPolju].brojFiguraNaPolju;
	igra�i[indeksIgracaNaZauzetomPolju].figure.push_back(Figura(figura->vratiBoju(),figura->vratiPo�etnuTo�ku(),figura->vratiZavr�nuTo�ku()));
	++igra�i[indeksIgracaNaZauzetomPolju].brojFiguraUKu�ici;

}

void Igra::oslobodiPolje(int polje)
{
	plo�a.zauzmiPolje(nullptr, polje);
}

void Igra::namjestiIndeksIgra�aNaZauzetomPolju(Figura* figura)
{
	for (auto igrac : igra�i)
	{
		for (auto f : igrac.figureNaPolju) {
			if (f == *figura)
				promjeniIndeksIgra�aNaZauzetomPolju(igrac);
		}
	}
}

Igra� Igra::prviIgra�()
{
	return igra�i.front();
}

void Igra::vratiPromjeneNakonZauzetoPolja()
{
	poljeJeZauzeto = false;
	indeksZauzetogPolja = -1;
	indeksIgracaNaZauzetomPolju = -1;
}

Boja Igra::vratiBojuIgra�a(int i)
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

void Igra::promjeniIndeksIgra�aNaZauzetomPolju(Igra� igra�)
{
	switch (igra�.vratiBoju()) {
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
