#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgraèa){
	ploèa = new Ploèa();
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		if (i < brojIgraèa)
			igraèi[i] = new Igraè(vratiBojuIgraèa(i));
		else
			igraèi[i] = nullptr;
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
Igraè * Igra::promjenaIgraèa(Igraè * trenutniIgraè)
{
	char bojaTrenutnogIgraèa = trenutniIgraè->vratiBoju();
	switch (bojaTrenutnogIgraèa) 
	{
	case 'c':
		return igraèi[1];
	case 'p':
		if (igraèi[2] == nullptr)
			return igraèi[0];
		else
			return igraèi[2];
	case 'z':
		if (igraèi[3] == nullptr)
			return igraèi[0];
		else
			return igraèi[3];
	case 'ž':
		return igraèi[0];
	default:
		break;
	}
	return nullptr;
}
Figura ** Igra::izaberiFiguru(Igraè * trenutniIgraè, int dobivenBrojSKocke)
{
	if (dobivenBrojSKocke == 6)
		return trenutniIgraè->figure;
	else
		return trenutniIgraè->figureNaPolju;
}
char Igra::vratiBojuIgraèa(int i)
{
	switch (i) {
	case 0:
		return 'c';
	case 1:
		return 'p';
	case 2:
		return 'z';
	case 3:
		return 'ž';
	default:
		break;
	}
}
