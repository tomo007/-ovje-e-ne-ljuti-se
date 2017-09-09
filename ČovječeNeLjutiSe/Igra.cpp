#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgrača){
	for (int i = 0; i < brojIgrača; ++i) {
		igrači.push_back(Igrač(vratiBojuIgrača(i)));
	}
	indeksIgrača = 0;
}


Igra::~Igra()
{
}
std::vector<Igrač> Igra::vratiIgrače()
{
	return igrači;
}
int Igra::bacajKocku(Igrač trenutniIgrač)
{
	if (trenutniIgrač.figureNaPolju.size() == 0)
		return 3;
	return 1;
}
bool Igra::pomakniFiguruNaPočetnoPolje(Igrač trenutniIgrač)
{
	if (trenutniIgrač.figure.size() > 0) {
		trenutniIgrač.figureNaPolju.push_back(trenutniIgrač.figure.back());
		trenutniIgrač.figureNaPolju.back().trenutnoPolje.pop_front();
		trenutniIgrač.figure.pop_back();
		return true;
	}
	else
		return false;
}
Igrač Igra::promjenaIgrača(Igrač * trenutniIgrač)
{	
	Boja bojaTrenutnogIgrača = trenutniIgrač->vratiBoju();
	int brojIgrača = igrači.size();
	switch (bojaTrenutnogIgrača) 
	{
	case Boja::CRVENA:
		indeksIgrača = 2;
		return igrači[1];
	case Boja::PLAVA:
		if (brojIgrača <= 2) {
			indeksIgrača = 1;
			return igrači.front();
		}else {
			indeksIgrača = 3;
			return igrači[2];
		}
	case Boja::ZELENA:
		if (brojIgrača <= 3) {
			indeksIgrača = 1;
			return igrači.front();
		}else
			indeksIgrača = 4;
			return igrači[3];
	case Boja::ZUTA:
		indeksIgrača = 1;
		return igrači.front();
	}
	
}

std::vector<Figura> Igra::izaberiFiguru(Igrač * trenutniIgrač, int dobivenBrojSKocke)
{
	if (dobivenBrojSKocke == 6)
		return trenutniIgrač->figure;
	else
		return trenutniIgrač->figureNaPolju;
}

bool Igra::pomakniFiguru(Igrač* trenutniIgrač, Figura* figura, int brojPomaka)
{
	bool flagFiguraNaPolju = false;
	for each (Figura var in trenutniIgrač->figureNaPolju)
	{
		if (&var == figura) {
			flagFiguraNaPolju = true;
			break;
		}
	}
	if (!flagFiguraNaPolju){
		trenutniIgrač->figureNaPolju.push_back(*figura);
		++trenutniIgrač->brojFiguraNaPolju;
	}
	if (trenutniIgrač->pomakni(figura, brojPomaka)) {
		Figura* figuraNaTomPolju = ploča.provjeraPolja(figura->trenutnoPolje.front());
		if (figuraNaTomPolju != nullptr) {
			oslobodiPolje(figuraNaTomPolju);
			figuraNaTomPolju = new Figura(figuraNaTomPolju->vratiBoju(), figuraNaTomPolju->vratiPočetnuTočku(), figuraNaTomPolju->vratiZavršnuTočku());
			ploča.zauzmiPolje(figura, figura->trenutnoPolje.front());
		}
		if (trenutniIgrač->zadnjeSlobodnoMjestoUKući == 0)
			return true;
	}
	return false;
}

void Igra::oslobodiPolje(Figura * figura)
{
	Igrač* igrač = dajIgračaSTomFigurom(figura);
	std::vector<Figura> v = igrač->figureNaPolju;
	igrač->figureNaPolju.erase(std::find(v.begin(), v.end(), figura));
	--igrač->brojFiguraNaPolju;
	igrač->figure.push_back(*figura);

}

Igrač* Igra::dajIgračaSTomFigurom(Figura* figura)
{
	for each (Igrač var in igrači)
	{
		if (figura->vratiBoju() == var.vratiBoju())
			return &var;
	}
	return nullptr;
}

Igrač Igra::prviIgrač()
{
	return igrači.front();
}

Boja Igra::vratiBojuIgrača(int i)
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

void Igra::promjeniIndeksIgrača(Igrač igrač)
{
	switch (igrač.vratiBoju()) {
	case Boja::CRVENA:
		indeksIgrača=1;
		break;
	case Boja::PLAVA:
		indeksIgrača = 2;
		break;
	case Boja::ZELENA:
		indeksIgrača = 3;
		break;
	case Boja::ZUTA:
		indeksIgrača = 4;
		break;
	default:
		break;
	}
}
