#include "stdafx.h"
#include "Igra.h"


Igra::Igra (byte brojIgra�a){
	plo�a = new Plo�a();
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		if (i < brojIgra�a)
			igra�i[i] = new Igra�(vratiBojuIgra�a(i));
		else
			igra�i[i] = nullptr;
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
Igra� * Igra::promjenaIgra�a(Igra� * trenutniIgra�)
{
	char bojaTrenutnogIgra�a = trenutniIgra�->vratiBoju();
	switch (bojaTrenutnogIgra�a) 
	{
	case 'c':
		return igra�i[1];
	case 'p':
		if (igra�i[2] == nullptr)
			return igra�i[0];
		else
			return igra�i[2];
	case 'z':
		if (igra�i[3] == nullptr)
			return igra�i[0];
		else
			return igra�i[3];
	case '�':
		return igra�i[0];
	default:
		break;
	}
	return nullptr;
}
Figura ** Igra::izaberiFiguru(Igra� * trenutniIgra�, int dobivenBrojSKocke)
{
	if (dobivenBrojSKocke == 6)
		return trenutniIgra�->figure;
	else
		return trenutniIgra�->figureNaPolju;
}
char Igra::vratiBojuIgra�a(int i)
{
	switch (i) {
	case 0:
		return 'c';
	case 1:
		return 'p';
	case 2:
		return 'z';
	case 3:
		return '�';
	default:
		break;
	}
}
