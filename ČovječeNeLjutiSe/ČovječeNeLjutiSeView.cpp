

	// ÈovjeèeNeLjutiSeView.cpp : implementation of the CÈovjeèeNeLjutiSeView class
	//

#include "stdafx.h"
	// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
	// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ÈovjeèeNeLjutiSe.h"
#endif

#include "ÈovjeèeNeLjutiSeDoc.h"
#include "ÈovjeèeNeLjutiSeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


	// CÈovjeèeNeLjutiSeView

	IMPLEMENT_DYNCREATE(CÈovjeèeNeLjutiSeView, CView)

BEGIN_MESSAGE_MAP(CÈovjeèeNeLjutiSeView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_DVA_IGRACA, &CÈovjeèeNeLjutiSeView::OnFileNewDvaIgraèa)
	ON_COMMAND(ID_TRI_IGRACA, &CÈovjeèeNeLjutiSeView::OnFileNewTriIgraèa)
	ON_COMMAND(ID_CETRI_IGRACA, &CÈovjeèeNeLjutiSeView::OnFileNewCetriIgraèa)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK(UINT nFlags, CPoint point)
END_MESSAGE_MAP()

// CÈovjeèeNeLjutiSeView construction/destruction
bool operator==(const RECT& a, const RECT& b) {
	return a.left == b.left && a.right == b.right && a.top == b.top &&
		a.bottom == b.bottom;
};


CÈovjeèeNeLjutiSeView::CÈovjeèeNeLjutiSeView()
{


}



CÈovjeèeNeLjutiSeView::~CÈovjeèeNeLjutiSeView()
{
	delete igra;
}


BOOL CÈovjeèeNeLjutiSeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CÈovjeèeNeLjutiSeView drawing
void CÈovjeèeNeLjutiSeView::igraj()
{
	if (trenutniIgrac.brojFiguraNaPolju <= 0 && brojSKocke == 6) {
		postaviFiguruNaPocetnoPolje();
		brojBacanjaKocke = 1;
	}
	if (brojSKocke != 6 && trenutniIgrac.brojFiguraNaPolju <= 0) {
		if (brojBacanjaKocke <= 0) {
			trenutniIgrac = igra->promjenaIgraèa(&trenutniIgrac);
			brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
			protresiKucicuIgraca();
			protresiKocku();
			return;
		}
		protresiKocku();
		return;
	}
	protresiDostupneFigure();
	if (brojSKocke == 6 || trenutniIgrac.brojFiguraNaPolju > 0) {
		if (figuraJeOdabrana) {
			figuraJeOdabrana = false;
			pomakniFiguru();
			if (brojSKocke == 6) {
				protresiKocku();
				return;
			}
		}
	}	
}

void CÈovjeèeNeLjutiSeView::iscrtajPolje(CDC* pDC, double dx, double dy)
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
	iscrtajKuèicu(pDC, 0, 0);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKuèicu(pDC, devetiStupac, 0);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKuèicu(pDC, 0, devetiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKuèicu(pDC, devetiStupac, devetiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	iscrtajCijeliRedHorizontalno(pDC, 0, cetvrtiRed);
	iscrtajCijeliRedHorizontalno(pDC, 0, sestiRed);
	iscrtajCijeliRedVertikalno(pDC, cetvrtiStupac, 0);
	iscrtajCijeliRedVertikalno(pDC, sestiStupac, 0);
	pDC->Ellipse(0, petiRed, duljinaKuèice, sestiRed);
	pDC->Ellipse(petiStupac, desetiRed, sestiStupac,desetiRed+visinaKuèice);
	pDC->Ellipse(desetiStupac, petiRed, desetiStupac+duljinaKuèice, sestiRed);
	pDC->Ellipse(petiStupac, 0, sestiStupac, visinaKuèice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, cetvrtiRed, duljinaKuèice, petiRed);
	iscrtajCiljHorizontalno(pDC, duljinaKuèice, petiRed);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(desetiStupac, sestiRed, desetiStupac+duljinaKuèice, sedmiRed);
	iscrtajCiljHorizontalno(pDC, sestiStupac, petiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(sestiStupac, 0, sedmiStupac, visinaKuèice);
	iscrtajCiljVertikalno(pDC, petiStupac, visinaKuèice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(cetvrtiStupac, desetiRed, petiStupac, desetiRed+visinaKuèice);
	iscrtajCiljVertikalno(pDC, petiStupac, sestiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	pDC->Rectangle(petiStupac, petiRed, sestiStupac, sestiRed);
	pDC->SelectObject(oldPen);

	DeleteObject(crnaPozadina);
	DeleteObject(crvenaPozadina);
	DeleteObject(zelenaPozadina);
	DeleteObject(zutaPozadina);
	DeleteObject(plavaPozadina);
	DeleteObject(crvenaOlovka);
	DeleteObject(zelenaOlovka);
	DeleteObject(zutaOlovka);
	DeleteObject(plavaOlovka);
	DeleteObject(crnaOlovka);
}

void CÈovjeèeNeLjutiSeView::iscrtajKuèicu(CDC * pDC, double dx, double dy)
{
	int i = 1;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		pDC->Ellipse(dx + duljinaKuèice, dy, dx + duljinaKuèice * 2, dy + visinaKuèice);
		dy = dy + visinaKuèice;
		++i;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajCijeliRedHorizontalno(CDC * pDC, double dx, double dy)
{
	while (dx < duljinaKuèice*brojRedova) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dx += duljinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy)
{
	while (dy < visinaKuèice*brojRedova) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dy += visinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dx += duljinaKuèice;
		++i;
	}

}

void CÈovjeèeNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dy += visinaKuèice;
		++i;
	}
}

void CÈovjeèeNeLjutiSeView::protresiDostupneFigure()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	if (brojSKocke == 6) {
		for each (RECT var in kuèice[igra->indeksIgraèa])
		{
			int i = 0;
			while (i < 2) {
				iscrtajFiguru(pDC, var.left, var.top - visinaKuèiceUKockici);
				Sleep(50);
				osvjeziPolje(var, 1);
				iscrtajFiguru(pDC, var.left, var.top);
				InvalidateRect(&var, 0);
				++i;
			}
		}
	}
	if (figureNaPolju[igra->indeksIgraèa].size() > 0) {
		for each (RECT var in figureNaPolju[igra->indeksIgraèa])
		{
			int i = 0;
			while (i < 2) {
				iscrtajFiguru(pDC, var.left, var.top - visinaKuèiceUKockici);
				Sleep(50);
				iscrtajFiguru(pDC, var.left, var.top);
				++i;
			}
		}
	}
	pDC->SelectObject(oldBrush);	
}

void CÈovjeèeNeLjutiSeView::protresiKocku()
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
		InvalidateRect(&r, true);
		Sleep(50);
		switch (brojSKocke)
		{
		case 1:
			iscrtajKockuJedan(pDC, petiStupac + duljinaKuèiceUKockici * 2, petiRed + visinaKuèiceUKockici * 2);
			break;
		case 2:
			iscrtajKockuDva(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + visinaKuèiceUKockici);
			break;
		case 3:
			iscrtajKockuTri(pDC, petiStupac + duljinaKuèiceUKockici * 2, petiRed + 5);
			break;
		case 4:
			iscrtajKockuCetri(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + visinaKuèiceUKockici);
			break;
		case 5:
			iscrtajKockuPet(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + 5);
			break;
		case 6:
			iscrtajKockuSest(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + 5);
			break;
		default:
			iscrtajKockuPet(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + 5);
			break;
		}
		InvalidateRect(&r, false);
		if (brojSKocke < 1 || brojSKocke>6)
			InvalidateRect(&r, 1);
		++i;
	}
	DeleteObject(crnaPozadina);
	pDC->SelectObject(oldBrush);
}

void CÈovjeèeNeLjutiSeView::protresiKucicuIgraca()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush;
	oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	for each (RECT var in kuèice[igra->indeksIgraèa])
	{
		int i = 0;
		while (i < 2) {
			iscrtajFiguru(pDC, var.left, var.top - visinaKuèiceUKockici);
			Sleep(50);
			iscrtajFiguru(pDC, var.left, var.top);
			++i;
		}
	}
	pDC->SelectObject(oldBrush);
}

void CÈovjeèeNeLjutiSeView::iscrtajKockuSest(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx = dx + duljinaKuèiceUKockici + duljinaKuèiceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx = dx - duljinaKuèiceUKockici - duljinaKuèiceUKockici;
		dy = dy + visinaKuèiceUKockici + visinaKuèiceUKockici - 5;
		++i;
	}

}

void CÈovjeèeNeLjutiSeView::iscrtajKockuPet(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx = dx + duljinaKuèiceUKockici + duljinaKuèiceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx = dx - duljinaKuèiceUKockici - duljinaKuèiceUKockici;
		dy = dy + visinaKuèiceUKockici * 4 - 10;
		++i;
	}
	dx = dx + duljinaKuèiceUKockici;
	dy = dy - visinaKuèiceUKockici * 4 - 1;
	pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);

}

void CÈovjeèeNeLjutiSeView::iscrtajKockuCetri(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx = dx + duljinaKuèiceUKockici + duljinaKuèiceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx = dx - duljinaKuèiceUKockici - duljinaKuèiceUKockici;
		dy = dy + visinaKuèiceUKockici + visinaKuèiceUKockici - 5;
		++i;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajKockuTri(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dy = dy + visinaKuèiceUKockici + visinaKuèiceUKockici - 5;
		++i;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajKockuDva(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx = dx + duljinaKuèiceUKockici + duljinaKuèiceUKockici;
		dy = dy + visinaKuèiceUKockici + visinaKuèiceUKockici - 5;
		++i;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajKockuJedan(CDC * pDC, double dx, double dy)
{
	pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
}

void CÈovjeèeNeLjutiSeView::iscrtajFiguru(CDC * pDC, double dx, double dy)
{
	double poèetakTijelaDx = dx + duljinaKuèiceUKockici;
	double poèetakTijelaDy = dy + visinaKuèiceUKockici;
	double krajTijelaDx = (dx + duljinaKuèice) - duljinaKuèiceUKockici;
	double krajTijelaDy = (dy + visinaKuèice) - visinaKuèiceUKockici;

	double poèetakGlaveDx = poèetakTijelaDx + duljinaKuèiceUKockici;
	double poèetakGlaveDy = poèetakTijelaDy + visinaKuèiceUKockici;
	double krajGlaveDx = poèetakGlaveDx + duljinaKuèiceUKockici;
	double krajGlaveDy = poèetakGlaveDy + visinaKuèiceUKockici;
	CBrush* oldPen;
	pDC->Ellipse(poèetakTijelaDx, poèetakTijelaDy, krajTijelaDx, krajTijelaDy);
	CBrush brush1;
	brush1.CreateSolidBrush(RGB(204, 0, 204));
	oldPen=pDC->SelectObject(&brush1);
	pDC->Ellipse(poèetakGlaveDx, poèetakGlaveDy, krajGlaveDx, krajGlaveDy);
	pDC->SelectObject(oldPen);
}

CBrush*  CÈovjeèeNeLjutiSeView::vratiBrush(Igraè trenutniIgraè)
{
	switch (trenutniIgraè.vratiBoju()) {
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

void CÈovjeèeNeLjutiSeView::prodiPoljaHorizontalno(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKuèice;
		p.top = dy;
		p.bottom = dy + visinaKuèice;
		ploèa.push_back(p);
		dx = dx + duljinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::prodiPoljaVertikalno(double dx, double dy, int brojPoljaZaProci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaProci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKuèice;
		p.top = dy;
		p.bottom = dy + visinaKuèice;
		ploèa.push_back(p);
		dy = dy + visinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::prodiKucicu(double dx, double dy,int indeks)
{
	RECT r;
	int i = 0;
	
	while (i < 2) {
		r.left = dx;
		r.right = dy+duljinaKuèice;
		r.top = dy;
		r.bottom = dy + visinaKuèice;
		kuèice[indeks].push_back(r);;
		r.left = dx + duljinaKuèice;
		r.right = dx + duljinaKuèice * 2;
		kuèice[indeks].push_back(r);
		dy = dy + visinaKuèice;
		++i;
	}
	
}

void CÈovjeèeNeLjutiSeView::prodiPoljaVertikalnoPremaGore(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKuèice;
		p.top = dy;
		p.bottom = dy + visinaKuèice;
		ploèa.push_back(p);
		dy = dy - visinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::prodiPoljaHorizontalnoSDesnaNaLijevo(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKuèice;
		p.top = dy;
		p.bottom = dy + visinaKuèice;
		ploèa.push_back(p);
		dx = dx - duljinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::inicijalizirajVarijableCrtanja()
{
	CRect r;
	GetClientRect(&r);
	duljinaKuèice =r.right / brojRedova;
	visinaKuèice = r.bottom / brojRedova;
	//stupci
	cetvrtiStupac = duljinaKuèice * 4;
	petiStupac = duljinaKuèice * 5;
	sestiStupac = duljinaKuèice * 6;
	sedmiStupac = duljinaKuèice * 7;
	devetiStupac = duljinaKuèice * 9;
	desetiStupac = duljinaKuèice * 10;
	//redci
	cetvrtiRed = visinaKuèice * 4;
	petiRed = visinaKuèice * 5;
	sestiRed = visinaKuèice * 6;
	sedmiRed = visinaKuèice * 7;
	devetiRed = visinaKuèice * 9;
	desetiRed = visinaKuèice * 10;
	duljinaKuèiceUKockici = duljinaKuèice / 5;
	visinaKuèiceUKockici = visinaKuèice / 5;
}

void CÈovjeèeNeLjutiSeView::inicijalizirajVektorPolja()
{
	prodiPoljaHorizontalno(0, cetvrtiRed, 5);
	prodiPoljaVertikalnoPremaGore(cetvrtiStupac, cetvrtiRed-visinaKuèice, 4);
	ploèa.push_back(CRect(petiStupac, 0, sestiStupac, visinaKuèice));
	prodiPoljaVertikalno(sestiStupac, 0, 4);
	prodiPoljaHorizontalno(sestiStupac, cetvrtiRed, 5);
	ploèa.push_back(CRect(desetiStupac, petiRed, duljinaKuèice * 11, sestiRed));
	prodiPoljaHorizontalnoSDesnaNaLijevo(desetiStupac, sestiRed, 5);
	prodiPoljaVertikalno(sestiStupac, sedmiRed , 4);
	ploèa.push_back(CRect(petiStupac, desetiRed, sestiStupac, visinaKuèice * 11));
	prodiPoljaVertikalnoPremaGore(cetvrtiStupac, desetiRed, 4);
	prodiPoljaHorizontalnoSDesnaNaLijevo(cetvrtiStupac, sestiRed, 4);
	ploèa.push_back(CRect(0, sestiRed, duljinaKuèice, sedmiRed));
}

void CÈovjeèeNeLjutiSeView::inicijalizirajKuèicu(Boja b)
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
	kuèice.push_back(vec);
	prodiKucicu(dx, dy,indeks);
}

void CÈovjeèeNeLjutiSeView::osvjeziPolje(RECT r,int izbrisi)
{
	r.left += duljinaKuèiceUKockici;
	r.top += visinaKuèiceUKockici;
	r.right -= duljinaKuèiceUKockici;
	r.bottom -= visinaKuèiceUKockici;
	InvalidateRect(&r, izbrisi);
}

void CÈovjeèeNeLjutiSeView::postaviFiguruNaPocetnoPolje()
{
	bool poljeJeZauzeto = false;
	RECT poljeFigure = ploèa.at(trenutniIgrac.vratiPoèetnoPolje());
	if(trenutniIgrac.brojFiguraNaPolju>0){
		for( auto r : figureNaPolju[igra->indeksIgraèa]) {
			if (r == poljeFigure)
				poljeJeZauzeto = true;
		}
	}
	if (!poljeJeZauzeto) {
		kuèice[igra->indeksIgraèa].pop_back();
		figureNaPolju[igra->indeksIgraèa].push_back(poljeFigure);
		igra->pomakniFiguruNaPoèetnoPolje(&igra->igraèi[igra->indeksIgraèa]);
		trenutniIgrac = igra->igraèi[igra->indeksIgraèa];
		figura = &trenutniIgrac.figureNaPolju.back();
	}
}
void CÈovjeèeNeLjutiSeView::pomakniFiguru()
{
	int staroPolje = figura->trenutnoPolje.front();
	std::vector<Figura> vec = trenutniIgrac.figureNaPolju;
	auto it = std::find(vec.begin(), vec.end(),*figura);
	int index;
	if (it != vec.end())
		index = std::distance(vec.begin(), it);
	RECT poljeNaKojemJeFigura = figureNaPolju[igra->indeksIgraèa].at(index);
	if (!igra->pomakniFiguru(&trenutniIgrac, figura, brojSKocke)) {
		if (trenutniIgrac.zadnjeSlobodnoMjestoUKuæi == 0) {
		//protresi cilj igraèa
		//makni ga iz igre
			igra->igraèi.erase(igra->igraèi.begin() + igra->indeksIgraèa);
		//ako je u igri samo jedan igraè on je izgubio i kraj igre
		}
		//if ako je u cilju makni figuru s igre i nacrtaj u cilju 
		auto itPolja = std::next(ploèa.begin(), figura->trenutnoPolje.front());
		if (itPolja != ploèa.end()) {
			figureNaPolju[igra->indeksIgraèa].at(index)= *itPolja;
			osvjeziPolje(poljeNaKojemJeFigura, 1);
			iscrtajFiguru(this->GetDC(),itPolja->left,itPolja->top);
			osvjeziPolje(*itPolja,0);
		}
	}
}

void CÈovjeèeNeLjutiSeView::OnDraw(CDC* pDC)
{
	CÈovjeèeNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen* oldPen;
	CBrush* oldBrush;
	CPen crnaOlovka(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = pDC->SelectObject(&crnaOlovka);
	if (kockaSeOkreæe) {
		switch (brojSKocke)
		{
		case 1:
			iscrtajKockuJedan(pDC, petiStupac + duljinaKuèiceUKockici * 2, petiRed + visinaKuèiceUKockici * 2);
			break;
		case 2:
			iscrtajKockuDva(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + visinaKuèiceUKockici);
			break;
		case 3:
			iscrtajKockuTri(pDC, petiStupac + duljinaKuèiceUKockici * 2, petiRed + 5);
			break;
		case 4:
			iscrtajKockuCetri(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + visinaKuèiceUKockici);
			break;
		case 5:
			iscrtajKockuPet(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + 5);
			break;
		case 6:
			iscrtajKockuSest(pDC, petiStupac + duljinaKuèiceUKockici, petiRed + 5);
			break;
		default:
			break;
		}

		pDC->SelectObject(oldPen);
	}
	iscrtajPolje(pDC, 0, 0);
	int indexIgraca = 0;
	for (auto i : kuèice) {
		for (auto r : i) {
			oldBrush = pDC->SelectObject(vratiBrush(igra->igraèi[indexIgraca]));
			iscrtajFiguru(pDC, r.left, r.top);
			pDC->SelectObject(oldBrush);
		}
		++indexIgraca;
	}
	for (auto i : figureNaPolju) {
		for (auto r : i) {
			oldBrush = pDC->SelectObject(vratiBrush(igra->igraèi[indexIgraca]));
			iscrtajFiguru(pDC, r.left, r.top);
			pDC->SelectObject(oldBrush);
		}
		++indexIgraca;
	}
}
	// TODO: add draw code for native data here



// CÈovjeèeNeLjutiSeView diagnostics

#ifdef _DEBUG
void CÈovjeèeNeLjutiSeView::AssertValid() const
{
	CView::AssertValid();
}

void CÈovjeèeNeLjutiSeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


void CÈovjeèeNeLjutiSeView::OnTimer(UINT_PTR nIDEvent)
{
	static int brojOkretajaKocke = 0;
		
			if (brojOkretajaKocke < 5) {
				if (!kockaSeOkreæe)
					kockaSeOkreæe = true;
				srand(time(NULL));
				brojSKocke = rand() % 6 + 1;
				++brojOkretajaKocke;
				InvalidateRect(CRect(petiStupac,petiRed,sestiStupac,sestiRed),1);
			}
			else {
				KillTimer(timer);
				kockaSeOkreæe = false;
				brojOkretajaKocke = 0;
				igraj();
			}
}

void CÈovjeèeNeLjutiSeView::OnLButtonDown(UINT nFlags, CPoint point)
{

	if (brojBacanjaKocke > 0||brojSKocke==6) {
			if (point.x > duljinaKuèice * 5 && point.x < duljinaKuèice * 6) {
				if (point.y > visinaKuèice * 5 && point.y < visinaKuèice * 6) {
					--brojBacanjaKocke;
					timer = SetTimer(1, 500, 0);
				}
				
			}
	}
	


}

void CÈovjeèeNeLjutiSeView::OnFileNewDvaIgraèa()
{
	igra = new Igra(2);
	trenutniIgrac = igra->prviIgraè();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for each (Igraè igrac in igra->vratiIgraèe())
	{
		inicijalizirajKuèicu(igrac.vratiBoju());
			switch (igrac.vratiBoju()) {
				case Boja::CRVENA: 
					figureNaPolju.push_back(vec);
					ciljevi.push_back(vec);
					break; 
				case Boja::PLAVA:	
					figureNaPolju.push_back(vec);
					ciljevi.push_back(vec);
					break;
				default:
					break;
			}
		
		}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
	}

void CÈovjeèeNeLjutiSeView::OnFileNewTriIgraèa()
{
	igra = new Igra(3);
	trenutniIgrac = igra->prviIgraè();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for each (Igraè igrac in igra->vratiIgraèe())
	{
		inicijalizirajKuèicu(igrac.vratiBoju());
		switch (igrac.vratiBoju()) {
		case Boja::CRVENA:
			figureNaPolju.push_back(vec);
			ciljevi.push_back(vec);
			break;
		case Boja::PLAVA:
			figureNaPolju.push_back(vec);
			ciljevi.push_back(vec);
			break;
		case Boja::ZELENA:
			figureNaPolju.push_back(vec);
			ciljevi.push_back(vec);
			break;
		default:
			break;
		}
		
	}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
}

void CÈovjeèeNeLjutiSeView::OnFileNewCetriIgraèa()
{
	igra = new Igra(4);
	trenutniIgrac = igra->prviIgraè();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for each (Igraè igrac in igra->vratiIgraèe())
	{
		inicijalizirajKuèicu(igrac.vratiBoju());
		switch (igrac.vratiBoju()) {
		case Boja::CRVENA:
			figureNaPolju.push_back(vec);
			ciljevi.push_back(vec);
			break;
		case Boja::PLAVA:
			figureNaPolju.push_back(vec);
			ciljevi.push_back(vec);
			break;
		case Boja::ZELENA:
			figureNaPolju.push_back(vec);
			ciljevi.push_back(vec);
			break;
		case Boja::ZUTA:
			figureNaPolju.push_back(vec);
			ciljevi.push_back(vec);
			break;
		default:
			break;
		}
	}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
}

void CÈovjeèeNeLjutiSeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	bool postaviNaPocetnoPolje = false;
	if (brojSKocke == 6) {
		for (auto var : kuèice[igra->indeksIgraèa])
		{
			if (var.left <= point.x&&var.right >= point.x)
				if (var.top <= point.y&&var.bottom >= point.y) {
					postaviNaPocetnoPolje = true;
				}
		}
	}
	if (trenutniIgrac.brojFiguraNaPolju > 0) {
		RECT r;
		for  (auto var : figureNaPolju[igra->indeksIgraèa])
		{
			if (var.left <= point.x && point.x <= var.right)
				if (var.top <= point.y&&point.y <= var.bottom) {
					figuraJeOdabrana = true;
					r = var;
				}
		}
		std::vector<RECT> vec = figureNaPolju[igra->indeksIgraèa];
		if (figuraJeOdabrana) {
			auto it = std::find(vec.begin(), vec.end(), r);
			if (it != vec.end()) {
				int index = std::distance(vec.begin(), it);
				figura = &trenutniIgrac.figureNaPolju[index];
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



CÈovjeèeNeLjutiSeDoc* CÈovjeèeNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CÈovjeèeNeLjutiSeDoc)));
	return (CÈovjeèeNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG
