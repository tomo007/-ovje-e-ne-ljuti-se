#pragma once
#include "Plo�a.h"
#include "Igra�.h"
#include <time.h> 
class Igra
{
private:
	Plo�a* plo�a;
	Igra�* igra�i[4];
	char vratiBojuIgra�a(int i);
public:
	Igra(byte brojIgra�a);
	~Igra();
	int bacajKocku();
	Igra�* promjenaIgra�a(Igra�* trenutniIgra�);
	Figura** izaberiFiguru(Igra�* trenutniIgra�, int dobivenBrojSKocke);
	bool pomakniFiguru(Igra�* trenutniIgra�,Figura* figura, int brojPomaka);
};

