#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgraèa){
	ploèa = Ploèa();
	srand(time(NULL));
	for (int i = 0; i < brojIgraèa; ++i) {
			igraèi[i] = Igraè(vratiBojuIgraèa(i));
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
Igraè Igra::promjenaIgraèa(Igraè * trenutniIgraè)
{	
	Boja bojaTrenutnogIgraèa = trenutniIgraè->vratiBoju();
	int brojIgraèa = igraèi.size();
	switch (bojaTrenutnogIgraèa) 
	{
	case Boja::CRVENA:
		return igraèi[1];
	case Boja::PLAVA:
		if (brojIgraèa<=2)
			return igraèi.front();
		else
			return igraèi[2];
	case Boja::ZELENA:
		if (brojIgraèa <= 3)
			return igraèi.front();
		else
			return igraèi[3];
	case Boja::ZUTA:
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

bool Igra::pomakniFiguru(Igraè* trenutniIgraè, Figura * figura, int brojPomaka)
{
	if (trenutniIgraè->pomakni(figura, brojPomaka)) {
		Figura* figuraNaTomPolju = ploèa.provjeraPolja(figura->trenutnoPolje.front());
		if (figuraNaTomPolju != nullptr) {
			figuraNaTomPolju = new Figura(figuraNaTomPolju->vratiBoju(), figuraNaTomPolju->vratiPoèetnuToèku(), figuraNaTomPolju->vratiZavršnuToèku());
			if (figura->poljeUKuæi < 0)
				ploèa.zauzmiPolje(figura, figura->trenutnoPolje.front());
		}
		return true;
	}
	return false;
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
