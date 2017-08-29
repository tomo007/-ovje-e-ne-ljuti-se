#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgra�a){
	plo�a = Plo�a();
	srand(time(NULL));
	for (int i = 0; i < brojIgra�a; ++i) {
			igra�i[i] = Igra�(vratiBojuIgra�a(i));
	}
}


Igra::~Igra()
{
}
int Igra::bacajKocku()
{
	srand(time(NULL));
	return rand() % 6+1;
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
	if (trenutniIgra�->pomakni(figura, brojPomaka)) {
		Figura* figuraNaTomPolju = plo�a.provjeraPolja(figura->trenutnoPolje.front());
		if (figuraNaTomPolju != nullptr) {
			figuraNaTomPolju = new Figura(figuraNaTomPolju->vratiBoju(), figuraNaTomPolju->vratiPo�etnuTo�ku(), figuraNaTomPolju->vratiZavr�nuTo�ku());
			if (figura->poljeUKu�i < 0)
				plo�a.zauzmiPolje(figura, figura->trenutnoPolje.front());
		}
		return true;
	}
	return false;
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
