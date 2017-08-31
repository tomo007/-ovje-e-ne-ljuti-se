#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgra�a){
	for (int i = 0; i < brojIgra�a; ++i) {
		igra�i.push_back(Igra�(vratiBojuIgra�a(i)));
	}
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
Igra� Igra::promjenaIgra�a(Igra� * trenutniIgra�)
{	
	Boja bojaTrenutnogIgra�a = trenutniIgra�->vratiBoju();
	int brojIgra�a = igra�i.size();
	switch (bojaTrenutnogIgra�a) 
	{
	case Boja::CRVENA:
		return igra�i[1];
	case Boja::PLAVA:
		if (brojIgra�a<=2)
			return igra�i.front();
		else
			return igra�i[2];
	case Boja::ZELENA:
		if (brojIgra�a <= 3)
			return igra�i.front();
		else
			return igra�i[3];
	case Boja::ZUTA:
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
