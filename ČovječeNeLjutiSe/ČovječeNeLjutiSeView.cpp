

	// ČovječeNeLjutiSeView.cpp : implementation of the CČovječeNeLjutiSeView class
	//

#include "stdafx.h"
	// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
	// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ČovječeNeLjutiSe.h"
#endif

#include "ČovječeNeLjutiSeDoc.h"
#include "ČovječeNeLjutiSeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


	// CČovječeNeLjutiSeView

	IMPLEMENT_DYNCREATE(CČovječeNeLjutiSeView, CView)

BEGIN_MESSAGE_MAP(CČovječeNeLjutiSeView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_DVA_IGRACA, &CČovječeNeLjutiSeView::OnFileNewDvaIgrača)
	ON_COMMAND(ID_TRI_IGRACA, &CČovječeNeLjutiSeView::OnFileNewTriIgrača)
	ON_COMMAND(ID_CETRI_IGRACA, &CČovječeNeLjutiSeView::OnFileNewCetriIgrača)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK(UINT nFlags, CPoint point)
END_MESSAGE_MAP()

// CČovječeNeLjutiSeView construction/destruction
bool operator==(const RECT& a, const RECT& b) {
	return a.left == b.left && a.right == b.right && a.top == b.top &&
		a.bottom == b.bottom;
};


CČovječeNeLjutiSeView::CČovječeNeLjutiSeView()
{
	igra = nullptr;

}



CČovječeNeLjutiSeView::~CČovječeNeLjutiSeView()
{
	
		delete igra;
}


BOOL CČovječeNeLjutiSeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CČovječeNeLjutiSeView drawing
void CČovječeNeLjutiSeView::igraj()
{
	if (trenutniIgrac.brojFiguraNaPolju <= 0 && brojSKocke == 6) {
		postaviFiguruNaPocetnoPolje();
	}
	if (brojSKocke != 6 && trenutniIgrac.brojFiguraNaPolju <= 0) {
		if (brojBacanjaKocke <= 0) {
			trenutniIgrac = igra->promjenaIgrača(&trenutniIgrac);
			brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
			Invalidate();
			protresiKucicuIgraca();
			//protresiKocku();
			return;
		}
		//protresiKocku();
		return;
	}
	protresiDostupneFigure();
	if (brojSKocke == 6 || trenutniIgrac.brojFiguraNaPolju > 0) {
		if (figuraJeOdabrana) {
			figuraJeOdabrana = false;
			pomakniFiguru();
			if (brojSKocke == 6) {
				brojBacanjaKocke = 1;
				return;
			}
			else {
				trenutniIgrac = igra->promjenaIgrača(&trenutniIgrac);
				brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
				Invalidate();
				protresiKucicuIgraca();
			}
		}
	}	
}

void CČovječeNeLjutiSeView::iscrtajPolje(CDC* pDC, double dx, double dy)
{

	CPen * oldPen;
	CPen crvenaOlovka(PS_SOLID, 7, RGB(255, 0, 0));
	CPen plavaOlovka(PS_SOLID, 7, RGB(0, 0, 255));
	CPen zelenaOlovka(PS_SOLID, 7, RGB(0, 255, 0));
	CPen zutaOlovka(PS_SOLID, 7, RGB(255, 255, 0));
	CPen crnaOlovka(PS_SOLID, 5, RGB(0, 0, 0));

	CBrush crvenaPozadina(RGB(255, 0, 0));
	CBrush plavaPozadina(RGB(0, 0, 255));
	CBrush zelenaPozadina(RGB(0, 255, 0));
	CBrush zutaPozadina(RGB(255, 255, 0));
	CBrush crnaPozadina(RGB(0, 0, 0));

	oldPen = pDC->SelectObject(&crvenaOlovka);
	iscrtajKučicu(pDC, 0, 0);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKučicu(pDC, devetiStupac, 0);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKučicu(pDC, 0, devetiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKučicu(pDC, devetiStupac, devetiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	iscrtajCijeliRedHorizontalno(pDC, 0, cetvrtiRed);
	iscrtajCijeliRedHorizontalno(pDC, 0, sestiRed);
	iscrtajCijeliRedVertikalno(pDC, cetvrtiStupac, 0);
	iscrtajCijeliRedVertikalno(pDC, sestiStupac, 0);
	pDC->Ellipse(0, petiRed, duljinaKučice, sestiRed);
	pDC->Ellipse(petiStupac, desetiRed, sestiStupac,desetiRed+visinaKučice);
	pDC->Ellipse(desetiStupac, petiRed, desetiStupac+duljinaKučice, sestiRed);
	pDC->Ellipse(petiStupac, 0, sestiStupac, visinaKučice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, cetvrtiRed, duljinaKučice, petiRed);
	iscrtajCiljHorizontalno(pDC, duljinaKučice, petiRed);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(desetiStupac, sestiRed, desetiStupac+duljinaKučice, sedmiRed);
	iscrtajCiljHorizontalno(pDC, sestiStupac, petiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(sestiStupac, 0, sedmiStupac, visinaKučice);
	iscrtajCiljVertikalno(pDC, petiStupac, visinaKučice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(cetvrtiStupac, desetiRed, petiStupac, desetiRed+visinaKučice);
	iscrtajCiljVertikalno(pDC, petiStupac, sestiRed);
	pDC->SelectObject(oldPen);

}

void CČovječeNeLjutiSeView::iscrtajKučicu(CDC * pDC, double dx, double dy)
{
	int i = 1;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		pDC->Ellipse(dx + duljinaKučice, dy, dx + duljinaKučice * 2, dy + visinaKučice);
		dy = dy + visinaKučice;
		++i;
	}
}

void CČovječeNeLjutiSeView::iscrtajCijeliRedHorizontalno(CDC * pDC, double dx, double dy)
{
	while (dx < duljinaKučice*brojRedova) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dx += duljinaKučice;
	}
}

void CČovječeNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy)
{
	while (dy < visinaKučice*brojRedova) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dy += visinaKučice;
	}
}

void CČovječeNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dx += duljinaKučice;
		++i;
	}

}

void CČovječeNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dy += visinaKučice;
		++i;
	}
}

void CČovječeNeLjutiSeView::protresiDostupneFigure()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	if (brojSKocke == 6) {
		for (auto var : kučice[igra->indeksIgrača])
		{
			int i = 0;
			while (i < 4) {
				iscrtajFiguru(pDC, var.left, var.top - visinaKučiceUKockici);
				Sleep(50);
				iscrtajFiguru(pDC, var.left, var.top);
				++i;
			}
		}
	}
	if (figureNaPolju[igra->indeksIgrača].size() > 0) {
		for (auto var : figureNaPolju[igra->indeksIgrača])
		{
			int i = 0;
			while (i < 2) {
				iscrtajFiguru(pDC, var.left, var.top - visinaKučiceUKockici);
				Sleep(50);
				iscrtajFiguru(pDC, var.left, var.top);
				++i;
			}
		}
	}
	delete (pDC->SelectObject(oldBrush));
	ReleaseDC(pDC);
}

void CČovječeNeLjutiSeView::protresiKocku()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush;
	CBrush crnaPozadina(RGB(0, 0, 0));
	oldBrush = pDC->SelectObject(&crnaPozadina);
	int i = 1;
	RECT r;
	r.bottom = sestiRed;
	r.top = petiRed;
	r.right = sestiStupac;
	r.left = petiStupac;

	while (i < 2) {
		Sleep(50);
		switch (brojSKocke)
		{
		case 1:
			iscrtajKockuJedan(pDC, petiStupac + duljinaKučiceUKockici * 2, petiRed + visinaKučiceUKockici * 2);
			break;
		case 2:
			iscrtajKockuDva(pDC, petiStupac + duljinaKučiceUKockici, petiRed + visinaKučiceUKockici);
			break;
		case 3:
			iscrtajKockuTri(pDC, petiStupac + duljinaKučiceUKockici * 2, petiRed + 5);
			break;
		case 4:
			iscrtajKockuCetri(pDC, petiStupac + duljinaKučiceUKockici, petiRed + visinaKučiceUKockici);
			break;
		case 5:
			iscrtajKockuPet(pDC, petiStupac + duljinaKučiceUKockici, petiRed + 5);
			break;
		case 6:
			iscrtajKockuSest(pDC, petiStupac + duljinaKučiceUKockici, petiRed + 5);
			break;
		default:
			iscrtajKockuPet(pDC, petiStupac + duljinaKučiceUKockici, petiRed + 5);
			break;
		}
		InvalidateRect(&r, false);
		if (brojSKocke < 1 || brojSKocke>6)
			InvalidateRect(&r, 1);
		++i;
	}
	pDC->SelectObject(oldBrush);
	ReleaseDC(pDC);
}

void CČovječeNeLjutiSeView::protresiKucicuIgraca()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush;
	oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	for(auto var : kučice[igra->indeksIgrača])
	{
		int i = 0;
		while (i < 2) {
			iscrtajFiguru(pDC, var.left, var.top - visinaKučiceUKockici);
			Sleep(50);
			iscrtajFiguru(pDC, var.left, var.top);
			++i;
		}
	}
	delete (pDC->SelectObject(oldBrush));
	ReleaseDC(pDC);
}

void CČovječeNeLjutiSeView::iscrtajKockuSest(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx = dx + duljinaKučiceUKockici + duljinaKučiceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx = dx - duljinaKučiceUKockici - duljinaKučiceUKockici;
		dy = dy + visinaKučiceUKockici + visinaKučiceUKockici - 5;
		++i;
	}

}

void CČovječeNeLjutiSeView::iscrtajKockuPet(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx = dx + duljinaKučiceUKockici + duljinaKučiceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx = dx - duljinaKučiceUKockici - duljinaKučiceUKockici;
		dy = dy + visinaKučiceUKockici * 4 - 10;
		++i;
	}
	dx = dx + duljinaKučiceUKockici;
	dy = dy - visinaKučiceUKockici * 4 - 1;
	pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);

}

void CČovječeNeLjutiSeView::iscrtajKockuCetri(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx = dx + duljinaKučiceUKockici + duljinaKučiceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx = dx - duljinaKučiceUKockici - duljinaKučiceUKockici;
		dy = dy + visinaKučiceUKockici + visinaKučiceUKockici - 5;
		++i;
	}
}

void CČovječeNeLjutiSeView::iscrtajKockuTri(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dy = dy + visinaKučiceUKockici + visinaKučiceUKockici - 5;
		++i;
	}
}

void CČovječeNeLjutiSeView::iscrtajKockuDva(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx = dx + duljinaKučiceUKockici + duljinaKučiceUKockici;
		dy = dy + visinaKučiceUKockici + visinaKučiceUKockici - 5;
		++i;
	}
}

void CČovječeNeLjutiSeView::iscrtajKockuJedan(CDC * pDC, double dx, double dy)
{
	pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
}

void CČovječeNeLjutiSeView::iscrtajFiguru(CDC * pDC, double dx, double dy)
{
	double početakTijelaDx = dx + duljinaKučiceUKockici;
	double početakTijelaDy = dy + visinaKučiceUKockici;
	double krajTijelaDx = (dx + duljinaKučice) - duljinaKučiceUKockici;
	double krajTijelaDy = (dy + visinaKučice) - visinaKučiceUKockici;

	double početakGlaveDx = početakTijelaDx + duljinaKučiceUKockici;
	double početakGlaveDy = početakTijelaDy + visinaKučiceUKockici;
	double krajGlaveDx = početakGlaveDx + duljinaKučiceUKockici;
	double krajGlaveDy = početakGlaveDy + visinaKučiceUKockici;
	CBrush* oldPen;
	pDC->Ellipse(početakTijelaDx, početakTijelaDy, krajTijelaDx, krajTijelaDy);
	CBrush brush1;
	brush1.CreateSolidBrush(RGB(204, 0, 204));
	oldPen=pDC->SelectObject(&brush1);
	pDC->Ellipse(početakGlaveDx, početakGlaveDy, krajGlaveDx, krajGlaveDy);
	pDC->SelectObject(oldPen);
	DeleteObject(brush1);
}

CBrush*  CČovječeNeLjutiSeView::vratiBrush(Igrač trenutniIgrač)
{
	switch (trenutniIgrač.vratiBoju()) {
	case Boja::CRVENA:
		return new CBrush(RGB(255, 0, 0));
	case Boja::PLAVA:
		return new CBrush(RGB(0, 0, 255));
	case Boja::ZELENA:
		return new CBrush(RGB(0, 255, 0));
	case Boja::ZUTA:
		return new CBrush(RGB(255, 255, 0));
	default:
		return nullptr;
	}
}

void CČovječeNeLjutiSeView::prodiPoljaHorizontalno(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKučice;
		p.top = dy;
		p.bottom = dy + visinaKučice;
		ploča.push_back(p);
		dx = dx + duljinaKučice;
	}
}

void CČovječeNeLjutiSeView::prodiPoljaVertikalno(double dx, double dy, int brojPoljaZaProci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaProci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKučice;
		p.top = dy;
		p.bottom = dy + visinaKučice;
		ploča.push_back(p);
		dy = dy + visinaKučice;
	}
}

void CČovječeNeLjutiSeView::prodiKucicu(double dx, double dy,int indeks)
{
	RECT r;
	int i = 0;
	
	while (i < 2) {
		r.left = dx;
		r.right = dy+duljinaKučice;
		r.top = dy;
		r.bottom = dy + visinaKučice;
		kučice[indeks].push_back(r);
		poljaKučice[indeks].push_back(r);
		r.left = dx + duljinaKučice;
		r.right = dx + duljinaKučice * 2;
		kučice[indeks].push_back(r);
		poljaKučice[indeks].push_back(r);
		dy = dy + visinaKučice;
		++i;
	}
	
}

void CČovječeNeLjutiSeView::prodiPoljaVertikalnoPremaGore(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKučice;
		p.top = dy;
		p.bottom = dy + visinaKučice;
		ploča.push_back(p);
		dy = dy - visinaKučice;
	}
}

void CČovječeNeLjutiSeView::prodiPoljaHorizontalnoSDesnaNaLijevo(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKučice;
		p.top = dy;
		p.bottom = dy + visinaKučice;
		ploča.push_back(p);
		dx = dx - duljinaKučice;
	}
}

void CČovječeNeLjutiSeView::inicijalizirajVarijableCrtanja()
{
	CRect r;
	GetClientRect(&r);
	duljinaKučice =r.right / brojRedova;
	visinaKučice = r.bottom / brojRedova;
	//stupci
	cetvrtiStupac = duljinaKučice * 4;
	petiStupac = duljinaKučice * 5;
	sestiStupac = duljinaKučice * 6;
	sedmiStupac = duljinaKučice * 7;
	devetiStupac = duljinaKučice * 9;
	desetiStupac = duljinaKučice * 10;
	//redci
	cetvrtiRed = visinaKučice * 4;
	petiRed = visinaKučice * 5;
	sestiRed = visinaKučice * 6;
	sedmiRed = visinaKučice * 7;
	devetiRed = visinaKučice * 9;
	desetiRed = visinaKučice * 10;
	duljinaKučiceUKockici = duljinaKučice / 5;
	visinaKučiceUKockici = visinaKučice / 5;
}

void CČovječeNeLjutiSeView::inicijalizirajVektorPolja()
{
	prodiPoljaHorizontalno(0, cetvrtiRed, 5);
	prodiPoljaVertikalnoPremaGore(cetvrtiStupac, cetvrtiRed-visinaKučice, 4);
	ploča.push_back(CRect(petiStupac, 0, sestiStupac, visinaKučice));
	prodiPoljaVertikalno(sestiStupac, 0, 4);
	prodiPoljaHorizontalno(sestiStupac, cetvrtiRed, 5);
	ploča.push_back(CRect(desetiStupac, petiRed, duljinaKučice * 11, sestiRed));
	prodiPoljaHorizontalnoSDesnaNaLijevo(desetiStupac, sestiRed, 5);
	prodiPoljaVertikalno(sestiStupac, sedmiRed , 4);
	ploča.push_back(CRect(petiStupac, desetiRed, sestiStupac, visinaKučice * 11));
	prodiPoljaVertikalnoPremaGore(cetvrtiStupac, desetiRed, 4);
	prodiPoljaHorizontalnoSDesnaNaLijevo(cetvrtiStupac, sestiRed, 4);
	ploča.push_back(CRect(0, sestiRed, duljinaKučice, sedmiRed));
}

void CČovječeNeLjutiSeView::inicijalizirajKučicu(Boja b)
{
	double dx, dy;
	int indeks=0;
	switch (b) {
	case Boja::CRVENA:
		dx = 0;
		dy = 0;
		indeks = 0;
		break;
	case Boja::PLAVA:
		dx = devetiStupac;
		dy = 0;
		indeks = 1;
		break;
	case Boja::ZELENA:
		dx = devetiStupac;
		dy = devetiRed;
		indeks = 2;
		break;
	case Boja::ZUTA:
		dx = 0;
		dy = devetiRed;
		indeks = 3;
		break;
	}
	std::vector<RECT> vec;
	kučice.push_back(vec);
	poljaKučice.push_back(vec);
	prodiKucicu(dx, dy,indeks);
}

void CČovječeNeLjutiSeView::inicijalizirajCiljeve(Boja b)
{
}

void CČovječeNeLjutiSeView::osvjeziPolje(RECT r,int izbrisi)
{
	r.left += duljinaKučiceUKockici;
	r.top += visinaKučiceUKockici;
	r.right -= duljinaKučiceUKockici;
	r.bottom -= visinaKučiceUKockici;
	InvalidateRect(&r, izbrisi);
}

void CČovječeNeLjutiSeView::postaviFiguruNaPocetnoPolje()
{
	bool poljeJeZauzeto = false;
	RECT poljeFigure = ploča.at(trenutniIgrac.vratiPočetnoPolje());
	if(trenutniIgrac.brojFiguraNaPolju>0){
		for( auto r : figureNaPolju[igra->indeksIgrača]) {
			if (r == poljeFigure)
				poljeJeZauzeto = true;
		}
	}
	if (!poljeJeZauzeto) {
		kučice[igra->indeksIgrača].pop_back();
		figureNaPolju[igra->indeksIgrača].push_back(poljeFigure);
		igra->pomakniFiguruNaPočetnoPolje(&igra->igrači[igra->indeksIgrača]);
		trenutniIgrac = igra->igrači[igra->indeksIgrača];
		figura = &trenutniIgrac.figureNaPolju.back();
	}
	Invalidate();
}
void CČovječeNeLjutiSeView::pomakniFiguru()
{
	std::vector<Figura> vec = trenutniIgrac.figureNaPolju;
	auto it = std::find(vec.begin(), vec.end(),*figura);
	int index;
	if (it != vec.end())
		index = std::distance(vec.begin(), it);
	RECT poljeNaKojemJeFigura = figureNaPolju[igra->indeksIgrača].at(index);
	int staroPoljeUCiljuFigure = figura->poljeUKući;
	if (igra->pomakniFiguru(&igra->igrači[igra->indeksIgrača], figura, brojSKocke)) {
		if (igra->poljeJeZauzeto) {
			figureNaPolju[igra->indeksIgracaNaZauzetomPolju].erase(figureNaPolju[igra->indeksIgracaNaZauzetomPolju].begin() + igra->indeksZauzetogPolja - 1);
			kučice[igra->indeksIgracaNaZauzetomPolju].push_back(poljaKučice[igra->indeksIgracaNaZauzetomPolju].at(kučice[igra->indeksIgracaNaZauzetomPolju].size() + 1));
			igra->vratiPromjeneNakonZauzetoPolja();
		}
		trenutniIgrac = igra->igrači[igra->indeksIgrača];
		if (staroPoljeUCiljuFigure > figura->poljeUKući) {
		//TODO stavi figuru u cilj
		}
		if (trenutniIgrac.zadnjeSlobodnoMjestoUKući == 0) {
		//protresi cilj igrača
		//makni ga iz igre
			igra->igrači.erase(igra->igrači.begin() + igra->indeksIgrača);
		//ako je u igri samo jedan igrač on je izgubio i kraj igre
		}
		//if ako je u cilju makni figuru s igre i nacrtaj u cilju 
		auto itPolja = std::next(ploča.begin(), figura->vratiTrenutnoPolje());
		if (itPolja != ploča.end()) {
			figureNaPolju[igra->indeksIgrača].at(index)= *itPolja;
		}
		Invalidate();
	}
	else {
		protresiDostupneFigure();
		return;
	}
}

void CČovječeNeLjutiSeView::OnDraw(CDC* pDC)
{
	CČovječeNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen* oldPen;
	CBrush* oldBrush;
	CBrush crnaPozadina(RGB(0, 0, 0));
	CPen crnaOlovka(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = pDC->SelectObject(&crnaOlovka);
	pDC->Rectangle(petiStupac, petiRed, sestiStupac, sestiRed);
	oldBrush = pDC->SelectObject(&crnaPozadina);
	if (kockaSeOkreće) {
		switch (brojSKocke)
		{
		case 1:
			iscrtajKockuJedan(pDC, petiStupac + duljinaKučiceUKockici * 2, petiRed + visinaKučiceUKockici * 2);
			break;
		case 2:
			iscrtajKockuDva(pDC, petiStupac + duljinaKučiceUKockici, petiRed + visinaKučiceUKockici);
			break;
		case 3:
			iscrtajKockuTri(pDC, petiStupac + duljinaKučiceUKockici * 2, petiRed + 5);
			break;
		case 4:
			iscrtajKockuCetri(pDC, petiStupac + duljinaKučiceUKockici, petiRed + visinaKučiceUKockici);
			break;
		case 5:
			iscrtajKockuPet(pDC, petiStupac + duljinaKučiceUKockici, petiRed + 5);
			break;
		case 6:
			iscrtajKockuSest(pDC, petiStupac + duljinaKučiceUKockici, petiRed + 5);
			break;
		default:
			break;
		}	
	}
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	iscrtajPolje(pDC, 0, 0);
	int indexIgraca = 0;
	for (auto i : kučice) {
		for (auto r : i) {
			oldBrush = pDC->SelectObject(vratiBrush(igra->igrači[indexIgraca]));
			iscrtajFiguru(pDC, r.left, r.top);
			delete (pDC->SelectObject(oldBrush));
		}
		++indexIgraca;
	}
	indexIgraca = 0;
	for (auto i : figureNaPolju) {
		for (auto r : i) {
			if (indexIgraca < igra->igrači.size()) {
				oldBrush = pDC->SelectObject(vratiBrush(igra->igrači[indexIgraca]));
				iscrtajFiguru(pDC, r.left, r.top);
				delete (pDC->SelectObject(oldBrush));
			}
		}
		++indexIgraca;
	}
	ReleaseDC(pDC);
		
}


// CČovječeNeLjutiSeView diagnostics

#ifdef _DEBUG
void CČovječeNeLjutiSeView::AssertValid() const
{
	CView::AssertValid();
}

void CČovječeNeLjutiSeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


void CČovječeNeLjutiSeView::OnTimer(UINT_PTR nIDEvent)
{
	static int brojOkretajaKocke = 0;
		
			if (brojOkretajaKocke < 5) {
				if (!kockaSeOkreće)
					kockaSeOkreće = true;
				srand(time(NULL));
				brojSKocke = rand() % 6 + 1;
				++brojOkretajaKocke;
				InvalidateRect(CRect(petiStupac, petiRed, sestiStupac, sestiRed));
			}
			else {
				KillTimer(timer);
				kockaSeOkreće = false;
				brojOkretajaKocke = 0;
				igraj();
			}
}

void CČovječeNeLjutiSeView::OnLButtonDown(UINT nFlags, CPoint point)
{

	if (brojBacanjaKocke > 0||brojSKocke==6) {
			if (point.x > duljinaKučice * 5 && point.x < duljinaKučice * 6) {
				if (point.y > visinaKučice * 5 && point.y < visinaKučice * 6) {
					--brojBacanjaKocke;
					timer = SetTimer(1, 500, 0);
				}
				
			}
	}
	


}

void CČovječeNeLjutiSeView::OnFileNewDvaIgrača()
{
	igra = new Igra(2);
	trenutniIgrac = igra->prviIgrač();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgrače())
	{
		inicijalizirajKučicu(igrac.vratiBoju());
			switch (igrac.vratiBoju()) {
				case Boja::CRVENA: 
					figureNaPolju.push_back(vec);
					poljaCiljeva.push_back(vec);
					break; 
				case Boja::PLAVA:	
					figureNaPolju.push_back(vec);
					poljaCiljeva.push_back(vec);
					break;
				default:
					break;
			}
		
		}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
	}

void CČovječeNeLjutiSeView::OnFileNewTriIgrača()
{
	igra = new Igra(3);
	trenutniIgrac = igra->prviIgrač();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgrače())
	{
		inicijalizirajKučicu(igrac.vratiBoju());
		switch (igrac.vratiBoju()) {
		case Boja::CRVENA:
			figureNaPolju.push_back(vec);
			poljaCiljeva.push_back(vec);
			break;
		case Boja::PLAVA:
			figureNaPolju.push_back(vec);
			poljaCiljeva.push_back(vec);
			break;
		case Boja::ZELENA:
			figureNaPolju.push_back(vec);
			poljaCiljeva.push_back(vec);
			break;
		default:
			break;
		}
		
	}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
}

void CČovječeNeLjutiSeView::OnFileNewCetriIgrača()
{
	igra = new Igra(4);
	trenutniIgrac = igra->prviIgrač();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgrače())
	{
		inicijalizirajKučicu(igrac.vratiBoju());
		switch (igrac.vratiBoju()) {
		case Boja::CRVENA:
			figureNaPolju.push_back(vec);
			poljaCiljeva.push_back(vec);
			break;
		case Boja::PLAVA:
			figureNaPolju.push_back(vec);
			poljaCiljeva.push_back(vec);
			break;
		case Boja::ZELENA:
			figureNaPolju.push_back(vec);
			poljaCiljeva.push_back(vec);
			break;
		case Boja::ZUTA:
			figureNaPolju.push_back(vec);
			poljaCiljeva.push_back(vec);
			break;
		default:
			break;
		}
	}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
}

void CČovječeNeLjutiSeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	bool postaviNaPocetnoPolje = false;
	if (brojSKocke == 6) {
		for (auto var : kučice[igra->indeksIgrača])
		{
			if (var.left <= point.x&&var.right >= point.x)
				if (var.top <= point.y&&var.bottom >= point.y) {
					postaviNaPocetnoPolje = true;
				}
		}
	}
	if (trenutniIgrac.brojFiguraNaPolju > 0) {
		RECT r;
		for  (auto var : figureNaPolju[igra->indeksIgrača])
		{
			if (var.left <= point.x && point.x <= var.right)
				if (var.top <= point.y&&point.y <= var.bottom) {
					figuraJeOdabrana = true;
					r = var;
				}
		}
		std::vector<RECT> vec = figureNaPolju[igra->indeksIgrača];
		if (figuraJeOdabrana) {
			auto it = std::find(vec.begin(), vec.end(), r);
			if (it != vec.end()) {
				int index = std::distance(vec.begin(), it);
				figura = &igra->igrači[igra->indeksIgrača].figureNaPolju[index];
			}
		}
	}
		if (postaviNaPocetnoPolje)
		{
			postaviFiguruNaPocetnoPolje();
			brojBacanjaKocke = 1;
		}
	igraj();
}



CČovječeNeLjutiSeDoc* CČovječeNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CČovječeNeLjutiSeDoc)));
	return (CČovječeNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG
