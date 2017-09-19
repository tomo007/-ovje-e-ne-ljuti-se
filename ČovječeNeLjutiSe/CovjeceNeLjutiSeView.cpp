

	// CovjeceNeLjutiSeView.cpp : implementation of the CCovjeceNeLjutiSeView class
	//

#include "stdafx.h"
	// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
	// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CovjeceNeLjutiSe.h"
#endif

#include "CovjeceNeLjutiSeDoc.h"
#include "CovjeceNeLjutiSeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


	// CCovjeceNeLjutiSeView

	IMPLEMENT_DYNCREATE(CCovjeCeNeLjutiSeView, CView)

BEGIN_MESSAGE_MAP(CCovjeCeNeLjutiSeView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_DVA_IGRACA, &CCovjeCeNeLjutiSeView::OnFileNewDvaIgraca)
	ON_COMMAND(ID_TRI_IGRACA, &CCovjeCeNeLjutiSeView::OnFileNewTriIgraca)
	ON_COMMAND(ID_CETRI_IGRACA, &CCovjeCeNeLjutiSeView::OnFileNewCetriIgraca)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK(UINT nFlags, CPoint point)
END_MESSAGE_MAP()

// CCovjeceNeLjutiSeView construction/destruction
bool operator==(const RECT& a, const RECT& b) {
	return a.left == b.left && a.right == b.right && a.top == b.top &&
		a.bottom == b.bottom;
};


CCovjeCeNeLjutiSeView::CCovjeCeNeLjutiSeView()
{
	igra = nullptr;

}



CCovjeCeNeLjutiSeView::~CCovjeCeNeLjutiSeView()
{
	
		delete igra;
}


BOOL CCovjeCeNeLjutiSeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCovjeceNeLjutiSeView drawing
void CCovjeCeNeLjutiSeView::igraj()
{
	if (trenutniIgrac.brojFiguraNaPolju <= 0 && brojSKocke == 6) {
		postaviFiguruNaPocetnoPolje();
	}
	if (brojSKocke != 6 && trenutniIgrac.brojFiguraNaPolju <= 0) {
		if (brojBacanjaKocke <= 0) {
			trenutniIgrac = igra->promjenaIgraca(&trenutniIgrac);
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
			if (pomakniFiguru()) {
				if (brojSKocke == 6) {
					brojBacanjaKocke = 1;
					return;
				}
				else {
					trenutniIgrac = igra->promjenaIgraca(&trenutniIgrac);
					brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
					Invalidate();
					protresiKucicuIgraca();
				}
			}
			else {
				protresiDostupneFigure();
			}
		}
	}
}

void CCovjeCeNeLjutiSeView::iscrtajPolje(CDC* pDC, double dx, double dy)
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
	iscrtajKucicu(pDC, 0, 0);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKucicu(pDC, devetiStupac, 0);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKucicu(pDC, 0, devetiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKucicu(pDC, devetiStupac, devetiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	iscrtajCijeliRedHorizontalno(pDC, 0, cetvrtiRed);
	iscrtajCijeliRedHorizontalno(pDC, 0, sestiRed);
	iscrtajCijeliRedVertikalno(pDC, cetvrtiStupac, 0);
	iscrtajCijeliRedVertikalno(pDC, sestiStupac, 0);
	pDC->Ellipse(0, petiRed, duljinaKucice, sestiRed);
	pDC->Ellipse(petiStupac, desetiRed, sestiStupac,desetiRed+visinaKucice);
	pDC->Ellipse(desetiStupac, petiRed, desetiStupac+duljinaKucice, sestiRed);
	pDC->Ellipse(petiStupac, 0, sestiStupac, visinaKucice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, cetvrtiRed, duljinaKucice, petiRed);
	iscrtajCiljHorizontalno(pDC, duljinaKucice, petiRed);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(desetiStupac, sestiRed, desetiStupac+duljinaKucice, sedmiRed);
	iscrtajCiljHorizontalno(pDC, sestiStupac, petiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(sestiStupac, 0, sedmiStupac, visinaKucice);
	iscrtajCiljVertikalno(pDC, petiStupac, visinaKucice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(cetvrtiStupac, desetiRed, petiStupac, desetiRed+visinaKucice);
	iscrtajCiljVertikalno(pDC, petiStupac, sestiRed);
	pDC->SelectObject(oldPen);

}

void CCovjeCeNeLjutiSeView::iscrtajKucicu(CDC * pDC, double dx, double dy)
{
	int i = 1;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKucice, dy + visinaKucice);
		pDC->Ellipse(dx + duljinaKucice, dy, dx + duljinaKucice * 2, dy + visinaKucice);
		dy = dy + visinaKucice;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::iscrtajCijeliRedHorizontalno(CDC * pDC, double dx, double dy)
{
	while (dx < duljinaKucice*brojRedova) {
		pDC->Ellipse(dx, dy, dx + duljinaKucice, dy + visinaKucice);
		dx += duljinaKucice;
	}
}

void CCovjeCeNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy)
{
	while (dy < visinaKucice*brojRedova) {
		pDC->Ellipse(dx, dy, dx + duljinaKucice, dy + visinaKucice);
		dy += visinaKucice;
	}
}

void CCovjeCeNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKucice, dy + visinaKucice);
		dx += duljinaKucice;
		++i;
	}

}

void CCovjeCeNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKucice, dy + visinaKucice);
		dy += visinaKucice;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::protresiDostupneFigure()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	if (brojSKocke == 6) {
		if (trenutniIgrac.figureNaPolju.size() == 4||trenutniIgrac.cilj.size()==4) {
			for (auto var : kucice[igra->indeksIgraca])
			{
				int i = 0;
				while (i < 4) {
					iscrtajFiguru(pDC, var.left, var.top - visinaKuciceUKockici);
					Sleep(50);
					iscrtajFiguru(pDC, var.left, var.top);
					++i;
				}
			}
		}
	}
	if (figureNaPolju[igra->indeksIgraca].size() > 0) {
		for (auto var : figureNaPolju[igra->indeksIgraca])
		{
			int i = 0;
			while (i < 2) {
				iscrtajFiguru(pDC, var.left, var.top - visinaKuciceUKockici);
				Sleep(50);
				iscrtajFiguru(pDC, var.left, var.top);
				++i;
			}
		}
	}
	if (ciljevi[igra->indeksIgraca].size() > 0) {
		for (auto var : ciljevi[igra->indeksIgraca])
		{
			int i = 0;
			while (i < 2) {
				iscrtajFiguru(pDC, var.left, var.top - visinaKuciceUKockici);
				Sleep(50);
				iscrtajFiguru(pDC, var.left, var.top);
				++i;
			}
		}
	}
	delete (pDC->SelectObject(oldBrush));
	ReleaseDC(pDC);
}

void CCovjeCeNeLjutiSeView::protresiKocku()
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
			iscrtajKockuJedan(pDC, petiStupac + duljinaKuciceUKockici * 2, petiRed + visinaKuciceUKockici * 2);
			break;
		case 2:
			iscrtajKockuDva(pDC, petiStupac + duljinaKuciceUKockici, petiRed + visinaKuciceUKockici);
			break;
		case 3:
			iscrtajKockuTri(pDC, petiStupac + duljinaKuciceUKockici * 2, petiRed + 5);
			break;
		case 4:
			iscrtajKockuCetri(pDC, petiStupac + duljinaKuciceUKockici, petiRed + visinaKuciceUKockici);
			break;
		case 5:
			iscrtajKockuPet(pDC, petiStupac + duljinaKuciceUKockici, petiRed + 5);
			break;
		case 6:
			iscrtajKockuSest(pDC, petiStupac + duljinaKuciceUKockici, petiRed + 5);
			break;
		default:
			iscrtajKockuPet(pDC, petiStupac + duljinaKuciceUKockici, petiRed + 5);
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

void CCovjeCeNeLjutiSeView::protresiKucicuIgraca()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush;
	oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	for(auto var : kucice[igra->indeksIgraca])
	{
		int i = 0;
		while (i < 2) {
			iscrtajFiguru(pDC, var.left, var.top - visinaKuciceUKockici);
			Sleep(100);
			iscrtajFiguru(pDC, var.left, var.top);
			++i;
		}
	}
	delete (pDC->SelectObject(oldBrush));
	ReleaseDC(pDC);
}

void CCovjeCeNeLjutiSeView::iscrtajKockuSest(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
		dx = dx + duljinaKuciceUKockici + duljinaKuciceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
		dx = dx - duljinaKuciceUKockici - duljinaKuciceUKockici;
		dy = dy + visinaKuciceUKockici + visinaKuciceUKockici - 5;
		++i;
	}

}

void CCovjeCeNeLjutiSeView::iscrtajKockuPet(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
		dx = dx + duljinaKuciceUKockici + duljinaKuciceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
		dx = dx - duljinaKuciceUKockici - duljinaKuciceUKockici;
		dy = dy + visinaKuciceUKockici * 4 - 10;
		++i;
	}
	dx = dx + duljinaKuciceUKockici;
	dy = dy - visinaKuciceUKockici * 4 - 1;
	pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);

}

void CCovjeCeNeLjutiSeView::iscrtajKockuCetri(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
		dx = dx + duljinaKuciceUKockici + duljinaKuciceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
		dx = dx - duljinaKuciceUKockici - duljinaKuciceUKockici;
		dy = dy + visinaKuciceUKockici + visinaKuciceUKockici - 5;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::iscrtajKockuTri(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
		dy = dy + visinaKuciceUKockici + visinaKuciceUKockici - 5;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::iscrtajKockuDva(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
		dx = dx + duljinaKuciceUKockici + duljinaKuciceUKockici;
		dy = dy + visinaKuciceUKockici + visinaKuciceUKockici - 5;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::iscrtajKockuJedan(CDC * pDC, double dx, double dy)
{
	pDC->Ellipse(dx, dy, dx + duljinaKuciceUKockici, dy + visinaKuciceUKockici);
}

void CCovjeCeNeLjutiSeView::iscrtajFiguru(CDC * pDC, double dx, double dy)
{
	double pocetakTijelaDx = dx + duljinaKuciceUKockici;
	double pocetakTijelaDy = dy + visinaKuciceUKockici;
	double krajTijelaDx = (dx + duljinaKucice) - duljinaKuciceUKockici;
	double krajTijelaDy = (dy + visinaKucice) - visinaKuciceUKockici;

	double pocetakGlaveDx = pocetakTijelaDx + duljinaKuciceUKockici;
	double pocetakGlaveDy = pocetakTijelaDy + visinaKuciceUKockici;
	double krajGlaveDx = pocetakGlaveDx + duljinaKuciceUKockici;
	double krajGlaveDy = pocetakGlaveDy + visinaKuciceUKockici;
	CBrush* oldPen;
	pDC->Ellipse(pocetakTijelaDx, pocetakTijelaDy, krajTijelaDx, krajTijelaDy);
	CBrush brush1;
	brush1.CreateSolidBrush(RGB(204, 0, 204));
	oldPen=pDC->SelectObject(&brush1);
	pDC->Ellipse(pocetakGlaveDx, pocetakGlaveDy, krajGlaveDx, krajGlaveDy);
	pDC->SelectObject(oldPen);
	DeleteObject(brush1);
}

CBrush*  CCovjeCeNeLjutiSeView::vratiBrush(Igrac trenutniIgrac)
{
	switch (trenutniIgrac.vratiBoju()) {
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

void CCovjeCeNeLjutiSeView::prodiPoljaHorizontalno(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKucice;
		p.top = dy;
		p.bottom = dy + visinaKucice;
		ploca.push_back(p);
		dx = dx + duljinaKucice;
	}
}

void CCovjeCeNeLjutiSeView::prodiPoljaVertikalno(double dx, double dy, int brojPoljaZaProci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaProci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKucice;
		p.top = dy;
		p.bottom = dy + visinaKucice;
		ploca.push_back(p);
		dy = dy + visinaKucice;
	}
}

void CCovjeCeNeLjutiSeView::prodiKucicu(double dx, double dy,int indeks)
{
	RECT r;
	int i = 0;
	
	while (i < 2) {
		r.left = dx;
		r.right = dx+duljinaKucice;
		r.top = dy;
		r.bottom = dy + visinaKucice;
		kucice[indeks].push_back(r);
		poljaKucice[indeks].push_back(r);
		r.left = dx + duljinaKucice;
		r.right = dx + duljinaKucice * 2;
		kucice[indeks].push_back(r);
		poljaKucice[indeks].push_back(r);
		dy = dy + visinaKucice;
		++i;
	}
	
}

void CCovjeCeNeLjutiSeView::prodiCiljVertikalno(int index)
{
	double dx = petiStupac;
	double dy = devetiRed;
	int i = 0;
	while (i<4) {
		poljaCiljeva[index].push_back(CRect(dx, dy, dx + duljinaKucice, dy + visinaKucice));
		dy -= visinaKucice;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::prodiCiljHorizontalno(int index)
{
	double dx = duljinaKucice;
	double dy = petiRed;
	int i = 0;
	while (i<4) {
		poljaCiljeva[index].push_back(CRect(dx, dy, dx + duljinaKucice, dy + visinaKucice));
		dx += duljinaKucice;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::prodiCiljVertikalnoOdGorePremaDolje(int index)
{
	double dx = petiStupac;
	double dy = 0;
	int i = 0;
	while (i<4) {
		poljaCiljeva[index].push_back(CRect(dx, dy, dx + duljinaKucice, dy + visinaKucice));
		dy += visinaKucice;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::prodiCiljHorizontalnoSDesnaNaLijevo(int index)
{
	double dx = devetiStupac;
	double dy = petiRed;
	int i = 0;
	while (i<4) {
		poljaCiljeva[index].push_back(CRect(dx, dy, dx + duljinaKucice, dy + visinaKucice));
		dx -= duljinaKucice;
		++i;
	}
}

void CCovjeCeNeLjutiSeView::prodiPoljaVertikalnoPremaGore(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKucice;
		p.top = dy;
		p.bottom = dy + visinaKucice;
		ploca.push_back(p);
		dy = dy - visinaKucice;
	}
}

void CCovjeCeNeLjutiSeView::prodiPoljaHorizontalnoSDesnaNaLijevo(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKucice;
		p.top = dy;
		p.bottom = dy + visinaKucice;
		ploca.push_back(p);
		dx = dx - duljinaKucice;
	}
}

void CCovjeCeNeLjutiSeView::inicijalizirajVarijableCrtanja()
{
	CRect r;
	GetClientRect(&r);
	duljinaKucice =r.right / brojRedova;
	visinaKucice = r.bottom / brojRedova;
	//stupci
	cetvrtiStupac = duljinaKucice * 4;
	petiStupac = duljinaKucice * 5;
	sestiStupac = duljinaKucice * 6;
	sedmiStupac = duljinaKucice * 7;
	devetiStupac = duljinaKucice * 9;
	desetiStupac = duljinaKucice * 10;
	//redci
	cetvrtiRed = visinaKucice * 4;
	petiRed = visinaKucice * 5;
	sestiRed = visinaKucice * 6;
	sedmiRed = visinaKucice * 7;
	devetiRed = visinaKucice * 9;
	desetiRed = visinaKucice * 10;
	duljinaKuciceUKockici = duljinaKucice / 5;
	visinaKuciceUKockici = visinaKucice / 5;
}

void CCovjeCeNeLjutiSeView::inicijalizirajVektorPolja()
{
	prodiPoljaHorizontalno(0, cetvrtiRed, 5);
	prodiPoljaVertikalnoPremaGore(cetvrtiStupac, cetvrtiRed-visinaKucice, 4);
	ploca.push_back(CRect(petiStupac, 0, sestiStupac, visinaKucice));
	prodiPoljaVertikalno(sestiStupac, 0, 4);
	prodiPoljaHorizontalno(sestiStupac, cetvrtiRed, 5);
	ploca.push_back(CRect(desetiStupac, petiRed, duljinaKucice * 11, sestiRed));
	prodiPoljaHorizontalnoSDesnaNaLijevo(desetiStupac, sestiRed, 5);
	prodiPoljaVertikalno(sestiStupac, sedmiRed , 4);
	ploca.push_back(CRect(petiStupac, desetiRed, sestiStupac, visinaKucice * 11));
	prodiPoljaVertikalnoPremaGore(cetvrtiStupac, desetiRed, 4);
	prodiPoljaHorizontalnoSDesnaNaLijevo(cetvrtiStupac, sestiRed, 4);
	ploca.push_back(CRect(0, sestiRed, duljinaKucice, sedmiRed));
}

void CCovjeCeNeLjutiSeView::inicijalizirajKucicu(Boja b)
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
	kucice.push_back(vec);
	poljaKucice.push_back(vec);
	prodiKucicu(dx, dy,indeks);
}

void CCovjeCeNeLjutiSeView::inicijalizirajCiljeve(Boja b)
{
	double dx, dy;
	std::vector<RECT> vec;
	switch (b) {
	case Boja::CRVENA:
		ciljevi.push_back(vec);
		prodiCiljHorizontalno(0);
		break;
	case Boja::PLAVA:
		ciljevi.push_back(vec);
		prodiCiljVertikalnoOdGorePremaDolje(1);
		break;
	case Boja::ZELENA:
		ciljevi.push_back(vec);
		prodiCiljHorizontalnoSDesnaNaLijevo(2);
		break;
	case Boja::ZUTA:
		ciljevi.push_back(vec);
		prodiCiljVertikalno(3);
		break;
	}
}

void CCovjeCeNeLjutiSeView::isprazniKontenjereProsleIgre()
{
	kucice.clear();
	ciljevi.clear();
	poljaCiljeva.clear();
	poljaKucice.clear();
	figureNaPolju.clear();
	ploca.clear();
}

void CCovjeCeNeLjutiSeView::osvjeziPolje(RECT r,int izbrisi)
{
	r.left += duljinaKuciceUKockici;
	r.top += visinaKuciceUKockici;
	r.right -= duljinaKuciceUKockici;
	r.bottom -= visinaKuciceUKockici;
	InvalidateRect(&r, izbrisi);
}

void CCovjeCeNeLjutiSeView::postaviFiguruNaPocetnoPolje()
{
	bool poljeJeZauzeto = false;
	RECT poljeFigure = ploca.at(trenutniIgrac.vratiPocetnoPolje());
	if(trenutniIgrac.brojFiguraNaPolju>0){
		for( auto r : figureNaPolju[igra->indeksIgraca]) {
			if (r == poljeFigure)
				poljeJeZauzeto = true;
		}
	}
	if (!poljeJeZauzeto) {
		if (kucice[igra->indeksIgraca].size() > 1) {
			kucice[igra->indeksIgraca].pop_back();
		}
		else {
			kucice[igra->indeksIgraca].clear();
		}
			figureNaPolju[igra->indeksIgraca].push_back(poljeFigure);
			igra->pomakniFiguruNaPocetnoPolje(&igra->igraci[igra->indeksIgraca]);
			trenutniIgrac = igra->igraci[igra->indeksIgraca];
			figura = &trenutniIgrac.figureNaPolju.back();
	}
	Invalidate();
}
bool CCovjeCeNeLjutiSeView::pomakniFiguru()
{
	RECT poljeNaKojemJeFigura;
	int index;
	if(figura->poljeUKuci>0){
		std::vector<Figura*> vec = trenutniIgrac.cilj;
		auto it = std::find(vec.begin(), vec.end(), figura);
		if (it != vec.end()) {
			index = std::distance(vec.begin(), it);
		}
	}
	else
	{
		std::vector<Figura> vec = trenutniIgrac.figureNaPolju;
		auto it = std::find(vec.begin(), vec.end(), *figura);
		if (it != vec.end()) {
			index = std::distance(vec.begin(), it);
		}
	}
	int staroPoljeUCiljuFigure = figura->poljeUKuci;

	if (igra->pomakniFiguru(&igra->igraci[igra->indeksIgraca], figura, brojSKocke)) {
		if (igra->poljeJeZauzeto) {
			if (figureNaPolju[igra->indeksIgracaNaZauzetomPolju].size() > 0) {
				figureNaPolju[igra->indeksIgracaNaZauzetomPolju].erase(std::next(figureNaPolju[igra->indeksIgracaNaZauzetomPolju].begin(), igra->indeksZauzetogPolja));
			}
			else {
				figureNaPolju[igra->indeksIgracaNaZauzetomPolju].clear();
			}
			kucice[igra->indeksIgracaNaZauzetomPolju].push_back(poljaKucice[igra->indeksIgracaNaZauzetomPolju].at(kucice[igra->indeksIgracaNaZauzetomPolju].size()));
			igra->vratiPromjeneNakonZauzetoPolja();
		}
		trenutniIgrac = igra->igraci[igra->indeksIgraca];
		if (trenutniIgrac.zadnjeSlobodnoMjestoUKuci == 0) {
			igra->igraci.erase(igra->igraci.begin() + igra->indeksIgraca);
		}if (staroPoljeUCiljuFigure < figura->poljeUKuci) {
			if (figureNaPolju[igra->indeksIgraca].size() > 1) {
				figureNaPolju[igra->indeksIgraca].erase(std::next(figureNaPolju[igra->indeksIgracaNaZauzetomPolju].begin(), index));
			}
			else {
				figureNaPolju[igra->indeksIgraca].clear();
			}
			if(figura->poljeUKuci>3)
				figura->poljeUKuci=3;
			ciljevi[igra->indeksIgraca].push_back(poljaCiljeva[igra->indeksIgraca][figura->poljeUKuci]);
		}
		else {
			auto itPolja = std::next(ploca.begin(), figura->vratiTrenutnoPolje());
			if (itPolja != ploca.end()) {
				figureNaPolju[igra->indeksIgraca].at(index) = *itPolja;
			}
		}
		Invalidate();
		return true;
	}
	else {
		protresiDostupneFigure();
		return false;
	}
}

void CCovjeCeNeLjutiSeView::OnDraw(CDC* pDC)
{
	CCovjeceNeLjutiSeDoc* pDoc = GetDocument();
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
	if (kockaSeOkrece) {
		switch (brojSKocke)
		{
		case 1:
			iscrtajKockuJedan(pDC, petiStupac + duljinaKuciceUKockici * 2, petiRed + visinaKuciceUKockici * 2);
			break;
		case 2:
			iscrtajKockuDva(pDC, petiStupac + duljinaKuciceUKockici, petiRed + visinaKuciceUKockici);
			break;
		case 3:
			iscrtajKockuTri(pDC, petiStupac + duljinaKuciceUKockici * 2, petiRed + 5);
			break;
		case 4:
			iscrtajKockuCetri(pDC, petiStupac + duljinaKuciceUKockici, petiRed + visinaKuciceUKockici);
			break;
		case 5:
			iscrtajKockuPet(pDC, petiStupac + duljinaKuciceUKockici, petiRed + 5);
			break;
		case 6:
			iscrtajKockuSest(pDC, petiStupac + duljinaKuciceUKockici, petiRed + 5);
			break;
		default:
			break;
		}	
	}
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	iscrtajPolje(pDC, 0, 0);
	int indexIgraca = 0;
	for (auto i : kucice) {
		for (auto r : i) {
			oldBrush = pDC->SelectObject(vratiBrush(igra->igraci[indexIgraca]));
			iscrtajFiguru(pDC, r.left, r.top);
			delete (pDC->SelectObject(oldBrush));
		}
		++indexIgraca;
	}
	indexIgraca = 0;
	for (auto i : figureNaPolju) {
		for (auto r : i) {
			if (indexIgraca < igra->igraci.size()) {
				oldBrush = pDC->SelectObject(vratiBrush(igra->igraci[indexIgraca]));
				iscrtajFiguru(pDC, r.left, r.top);
				delete (pDC->SelectObject(oldBrush));
			}
		}
		++indexIgraca;
	}
	indexIgraca = 0;
	for (auto i : ciljevi) {
		for (auto r : i) {
			if (indexIgraca < igra->igraci.size()) {
				oldBrush = pDC->SelectObject(vratiBrush(igra->igraci[indexIgraca]));
				iscrtajFiguru(pDC, r.left, r.top);
				delete (pDC->SelectObject(oldBrush));
			}
		}
		++indexIgraca;
	}
	ReleaseDC(pDC);
		
}


// CCovjeceNeLjutiSeView diagnostics


void CCovjeCeNeLjutiSeView::AssertValid() const
{
	CView::AssertValid();
}

void CCovjeCeNeLjutiSeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


void CCovjeCeNeLjutiSeView::OnTimer(UINT_PTR nIDEvent)
{
	static int brojOkretajaKocke = 0;
		
			if (brojOkretajaKocke < 5) {
				if (!kockaSeOkrece)
					kockaSeOkrece = true;
				srand(time(NULL));
				brojSKocke = rand() % 6 + 1;
				++brojOkretajaKocke;
				InvalidateRect(CRect(petiStupac, petiRed, sestiStupac, sestiRed));
			}
			else {
				KillTimer(timer);
				kockaSeOkrece = false;
				brojOkretajaKocke = 0;
				igraj();
			}
}

void CCovjeCeNeLjutiSeView::OnLButtonDown(UINT nFlags, CPoint point)
{

	if (brojBacanjaKocke > 0||brojSKocke==6) {
		if (!kockaSeOkrece) {
			if (point.x > duljinaKucice * 5 && point.x < duljinaKucice * 6) {
				if (point.y > visinaKucice * 5 && point.y < visinaKucice * 6) {
					--brojBacanjaKocke;
					timer = SetTimer(1, 500, 0);
				}

			}
		}
	}
	


}

void CCovjeCeNeLjutiSeView::OnFileNewDvaIgraca()
{
	igra = new Igra(2);
	if (poljaKucice.size() > 0)
		isprazniKontenjereProsleIgre();
	trenutniIgrac = igra->prviIgrac();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgrace())
	{
		inicijalizirajKucicu(igrac.vratiBoju());
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
			inicijalizirajCiljeve(igrac.vratiBoju());
		
		}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
	}

void CCovjeCeNeLjutiSeView::OnFileNewTriIgraca()
{
	igra = new Igra(3);
	if (poljaKucice.size() > 0)
		isprazniKontenjereProsleIgre();
	trenutniIgrac = igra->prviIgrac();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgrace())
	{
		inicijalizirajKucicu(igrac.vratiBoju());
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
		inicijalizirajCiljeve(igrac.vratiBoju());
		
	}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
}

void CCovjeCeNeLjutiSeView::OnFileNewCetriIgraca()
{
	igra = new Igra(4);
	if (poljaKucice.size() > 0)
		isprazniKontenjereProsleIgre();
	trenutniIgrac = igra->prviIgrac();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgrace())
	{
		inicijalizirajKucicu(igrac.vratiBoju());
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
		inicijalizirajCiljeve(igrac.vratiBoju());
	}
	protresiKocku();
	brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
	Invalidate();
}

void CCovjeCeNeLjutiSeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	bool postaviNaPocetnoPolje = false;
	if (brojSKocke == 6) {
		if (trenutniIgrac.brojFiguraUKucici > 0) {
			for (auto var : kucice[igra->indeksIgraca])
			{
				if (var.left <= point.x && var.right >= point.x)
					if (var.top <= point.y && var.bottom >= point.y) {
						postaviNaPocetnoPolje = true;
					}
			}
		}
	}
	if (trenutniIgrac.brojFiguraNaPolju > 0) {
		RECT r;
		for  (auto var : figureNaPolju[igra->indeksIgraca])
		{
			if (var.left <= point.x && point.x <= var.right)
				if (var.top <= point.y&&point.y <= var.bottom) {
					figuraJeOdabrana = true;
					r = var;
				}
		}
		std::vector<RECT> vec = figureNaPolju[igra->indeksIgraca];
		if (figuraJeOdabrana) {
			auto it = std::find(vec.begin(), vec.end(), r);
			if (it != vec.end()) {
				int index = std::distance(vec.begin(), it);
				figura = &igra->igraci[igra->indeksIgraca].figureNaPolju[index];
			}
		}
	}
	if (trenutniIgrac.brojFiguraUCilju > 0) {
		RECT r;
		for (auto var : ciljevi[igra->indeksIgraca])
		{
			if (var.left <= point.x && point.x <= var.right)
				if (var.top <= point.y&&point.y <= var.bottom) {
					figuraJeOdabrana = true;
					r = var;
				}
		}
		std::vector<RECT> vec = poljaCiljeva[igra->indeksIgraca];
		if (figuraJeOdabrana) {
			auto it = std::find(vec.begin(), vec.end(), r);
			if (it != vec.end()) {
				int index = std::distance(vec.begin(), it);
				figura = igra->igraci[igra->indeksIgraca].cilj[index];
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


#ifdef _DEBUG
CCovjeceNeLjutiSeDoc* CCovjeCeNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCovjeceNeLjutiSeDoc)));
	return (CCovjeceNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG
