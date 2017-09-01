#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgra�a){
	for (int i = 0; i < brojIgra�a; ++i) {
		igra�i.push_back(Igra�(vratiBojuIgra�a(i)));
	}
	indeksIgra�a = 0;
}


Igra::~Igra()
{
}
std::vector<Igra�> Igra::vratiIgra�e()
{
	return igra�i;
}
int Igra::bacajKocku(Igra� trenutniIgra�)
{
	if (trenutniIgra�.figureNaPolju.size() == 0)
		return 3;
	return 1;
}
bool Igra::pomakniFiguruNaPo�etnoPolje(Igra� trenutniIgra�)
{	
	if (trenutniIgra�.figureNaPolju.size() > 0) {
		int i = 0;
		while (i < trenutniIgra�.figureNaPolju.size()) {
			if(trenutniIgra�.figureNaPolju[i].vratiTrenutnoPolje()+1== trenutniIgra�.vratiPo�etnoPolje()+1)
				return false;
			++i;
		}
	}	
	trenutniIgra�.figureNaPolju.push_back(trenutniIgra�.figure.back());
	trenutniIgra�.figureNaPolju.back().trenutnoPolje.pop_front();
	trenutniIgra�.figure.pop_back();
	return true;
}
Igra� Igra::promjenaIgra�a(Igra� * trenutniIgra�)
{	
	Boja bojaTrenutnogIgra�a = trenutniIgra�->vratiBoju();
	int brojIgra�a = igra�i.size();
	switch (bojaTrenutnogIgra�a) 
	{
	case Boja::CRVENA:
		indeksIgra�a = 2;
		return igra�i[1];
	case Boja::PLAVA:
		if (brojIgra�a <= 2) {
			indeksIgra�a = 1;
			return igra�i.front();
		}else {
			indeksIgra�a = 3;
			return igra�i[2];
		}
	case Boja::ZELENA:
		if (brojIgra�a <= 3) {
			indeksIgra�a = 1;
			return igra�i.front();
		}else
			indeksIgra�a = 4;
			return igra�i[3];
	case Boja::ZUTA:
		indeksIgra�a = 1;
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

bool Igra::pomakniFiguru(Igra�* trenutniIgra�, Figura * figura, int brojPomaka)
{
	bool flagFiguraNaPolju = false;
	for each (Figura var in trenutniIgra�->figureNaPolju)
	{
		if (&var == figura) {
			flagFiguraNaPolju = true;
				break;
		}	
	}
	if (!flagFiguraNaPolju){
		trenutniIgra�->figureNaPolju.push_back(*figura);
		++trenutniIgra�->brojFiguraNaPolju;
	}
	if (trenutniIgra�->pomakni(figura, brojPomaka)) {
		Figura* figuraNaTomPolju = plo�a.provjeraPolja(figura->trenutnoPolje.front());
		if (figuraNaTomPolju != nullptr) {
			figuraNaTomPolju = new Figura(figuraNaTomPolju->vratiBoju(), figuraNaTomPolju->vratiPo�etnuTo�ku(), figuraNaTomPolju->vratiZavr�nuTo�ku());
			if (figura->poljeUKu�i < 0)
				plo�a.zauzmiPolje(figura, figura->trenutnoPolje.front());
		}
		if (trenutniIgra�->zadnjeSlobodnoMjestoUKu�i == 0)
			return true;
	}
	return false;
}

Igra� Igra::prviIgra�()
{
	return igra�i.front();
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

void Igra::promjeniIndeksIgra�a(Igra� igra�)
{
	switch (igra�.vratiBoju()) {
	case Boja::CRVENA:
		indeksIgra�a=1;
		break;
	case Boja::PLAVA:
		indeksIgra�a = 2;
		break;
	case Boja::ZELENA:
		indeksIgra�a = 3;
		break;
	case Boja::ZUTA:
		indeksIgra�a = 4;
		break;
	default:
		break;
	}
}
