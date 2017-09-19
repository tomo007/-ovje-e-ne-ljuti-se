

	// �ovje�eNeLjutiSeView.cpp : implementation of the C�ovje�eNeLjutiSeView class
	//

#include "stdafx.h"
	// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
	// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "�ovje�eNeLjutiSe.h"
#endif

#include "�ovje�eNeLjutiSeDoc.h"
#include "�ovje�eNeLjutiSeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


	// C�ovje�eNeLjutiSeView

	IMPLEMENT_DYNCREATE(C�ovje�eNeLjutiSeView, CView)

BEGIN_MESSAGE_MAP(C�ovje�eNeLjutiSeView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_DVA_IGRACA, &C�ovje�eNeLjutiSeView::OnFileNewDvaIgra�a)
	ON_COMMAND(ID_TRI_IGRACA, &C�ovje�eNeLjutiSeView::OnFileNewTriIgra�a)
	ON_COMMAND(ID_CETRI_IGRACA, &C�ovje�eNeLjutiSeView::OnFileNewCetriIgra�a)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK(UINT nFlags, CPoint point)
END_MESSAGE_MAP()

// C�ovje�eNeLjutiSeView construction/destruction
bool operator==(const RECT& a, const RECT& b) {
	return a.left == b.left && a.right == b.right && a.top == b.top &&
		a.bottom == b.bottom;
};


C�ovje�eNeLjutiSeView::C�ovje�eNeLjutiSeView()
{
	igra = nullptr;

}



C�ovje�eNeLjutiSeView::~C�ovje�eNeLjutiSeView()
{
	
		delete igra;
}


BOOL C�ovje�eNeLjutiSeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// C�ovje�eNeLjutiSeView drawing
void C�ovje�eNeLjutiSeView::igraj()
{
	if (trenutniIgrac.brojFiguraNaPolju <= 0 && brojSKocke == 6) {
		postaviFiguruNaPocetnoPolje();
	}
	if (brojSKocke != 6 && trenutniIgrac.brojFiguraNaPolju <= 0) {
		if (brojBacanjaKocke <= 0) {
			trenutniIgrac = igra->promjenaIgra�a(&trenutniIgrac);
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
				trenutniIgrac = igra->promjenaIgra�a(&trenutniIgrac);
				brojBacanjaKocke = igra->brojBacanjaKocke(trenutniIgrac);
				Invalidate();
				protresiKucicuIgraca();
			}
		}
	}	
}

void C�ovje�eNeLjutiSeView::iscrtajPolje(CDC* pDC, double dx, double dy)
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
	iscrtajKu�icu(pDC, 0, 0);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKu�icu(pDC, devetiStupac, 0);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKu�icu(pDC, 0, devetiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKu�icu(pDC, devetiStupac, devetiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	iscrtajCijeliRedHorizontalno(pDC, 0, cetvrtiRed);
	iscrtajCijeliRedHorizontalno(pDC, 0, sestiRed);
	iscrtajCijeliRedVertikalno(pDC, cetvrtiStupac, 0);
	iscrtajCijeliRedVertikalno(pDC, sestiStupac, 0);
	pDC->Ellipse(0, petiRed, duljinaKu�ice, sestiRed);
	pDC->Ellipse(petiStupac, desetiRed, sestiStupac,desetiRed+visinaKu�ice);
	pDC->Ellipse(desetiStupac, petiRed, desetiStupac+duljinaKu�ice, sestiRed);
	pDC->Ellipse(petiStupac, 0, sestiStupac, visinaKu�ice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, cetvrtiRed, duljinaKu�ice, petiRed);
	iscrtajCiljHorizontalno(pDC, duljinaKu�ice, petiRed);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(desetiStupac, sestiRed, desetiStupac+duljinaKu�ice, sedmiRed);
	iscrtajCiljHorizontalno(pDC, sestiStupac, petiRed);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(sestiStupac, 0, sedmiStupac, visinaKu�ice);
	iscrtajCiljVertikalno(pDC, petiStupac, visinaKu�ice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(cetvrtiStupac, desetiRed, petiStupac, desetiRed+visinaKu�ice);
	iscrtajCiljVertikalno(pDC, petiStupac, sestiRed);
	pDC->SelectObject(oldPen);

}

void C�ovje�eNeLjutiSeView::iscrtajKu�icu(CDC * pDC, double dx, double dy)
{
	int i = 1;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		pDC->Ellipse(dx + duljinaKu�ice, dy, dx + duljinaKu�ice * 2, dy + visinaKu�ice);
		dy = dy + visinaKu�ice;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajCijeliRedHorizontalno(CDC * pDC, double dx, double dy)
{
	while (dx < duljinaKu�ice*brojRedova) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dx += duljinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy)
{
	while (dy < visinaKu�ice*brojRedova) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dy += visinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dx += duljinaKu�ice;
		++i;
	}

}

void C�ovje�eNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dy += visinaKu�ice;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::protresiDostupneFigure()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	if (brojSKocke == 6) {
		if (trenutniIgrac.figureNaPolju.size() == 4||trenutniIgrac.ku�a.size()==4) {
			for (auto var : ku�ice[igra->indeksIgra�a])
			{
				int i = 0;
				while (i < 4) {
					iscrtajFiguru(pDC, var.left, var.top - visinaKu�iceUKockici);
					Sleep(50);
					iscrtajFiguru(pDC, var.left, var.top);
					++i;
				}
			}
		}
	}
	if (figureNaPolju[igra->indeksIgra�a].size() > 0) {
		for (auto var : figureNaPolju[igra->indeksIgra�a])
		{
			int i = 0;
			while (i < 2) {
				iscrtajFiguru(pDC, var.left, var.top - visinaKu�iceUKockici);
				Sleep(50);
				iscrtajFiguru(pDC, var.left, var.top);
				++i;
			}
		}
	}
	if (ciljevi[igra->indeksIgra�a].size() > 0) {
		for (auto var : ciljevi[igra->indeksIgra�a])
		{
			int i = 0;
			while (i < 2) {
				iscrtajFiguru(pDC, var.left, var.top - visinaKu�iceUKockici);
				Sleep(50);
				iscrtajFiguru(pDC, var.left, var.top);
				++i;
			}
		}
	}
	delete (pDC->SelectObject(oldBrush));
	ReleaseDC(pDC);
}

void C�ovje�eNeLjutiSeView::protresiKocku()
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
			iscrtajKockuJedan(pDC, petiStupac + duljinaKu�iceUKockici * 2, petiRed + visinaKu�iceUKockici * 2);
			break;
		case 2:
			iscrtajKockuDva(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + visinaKu�iceUKockici);
			break;
		case 3:
			iscrtajKockuTri(pDC, petiStupac + duljinaKu�iceUKockici * 2, petiRed + 5);
			break;
		case 4:
			iscrtajKockuCetri(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + visinaKu�iceUKockici);
			break;
		case 5:
			iscrtajKockuPet(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + 5);
			break;
		case 6:
			iscrtajKockuSest(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + 5);
			break;
		default:
			iscrtajKockuPet(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + 5);
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

void C�ovje�eNeLjutiSeView::protresiKucicuIgraca()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush;
	oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	for(auto var : ku�ice[igra->indeksIgra�a])
	{
		int i = 0;
		while (i < 2) {
			iscrtajFiguru(pDC, var.left, var.top - visinaKu�iceUKockici);
			Sleep(50);
			iscrtajFiguru(pDC, var.left, var.top);
			++i;
		}
	}
	delete (pDC->SelectObject(oldBrush));
	ReleaseDC(pDC);
}

void C�ovje�eNeLjutiSeView::iscrtajKockuSest(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
		dx = dx + duljinaKu�iceUKockici + duljinaKu�iceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
		dx = dx - duljinaKu�iceUKockici - duljinaKu�iceUKockici;
		dy = dy + visinaKu�iceUKockici + visinaKu�iceUKockici - 5;
		++i;
	}

}

void C�ovje�eNeLjutiSeView::iscrtajKockuPet(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
		dx = dx + duljinaKu�iceUKockici + duljinaKu�iceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
		dx = dx - duljinaKu�iceUKockici - duljinaKu�iceUKockici;
		dy = dy + visinaKu�iceUKockici * 4 - 10;
		++i;
	}
	dx = dx + duljinaKu�iceUKockici;
	dy = dy - visinaKu�iceUKockici * 4 - 1;
	pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);

}

void C�ovje�eNeLjutiSeView::iscrtajKockuCetri(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
		dx = dx + duljinaKu�iceUKockici + duljinaKu�iceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
		dx = dx - duljinaKu�iceUKockici - duljinaKu�iceUKockici;
		dy = dy + visinaKu�iceUKockici + visinaKu�iceUKockici - 5;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajKockuTri(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
		dy = dy + visinaKu�iceUKockici + visinaKu�iceUKockici - 5;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajKockuDva(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 2) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
		dx = dx + duljinaKu�iceUKockici + duljinaKu�iceUKockici;
		dy = dy + visinaKu�iceUKockici + visinaKu�iceUKockici - 5;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajKockuJedan(CDC * pDC, double dx, double dy)
{
	pDC->Ellipse(dx, dy, dx + duljinaKu�iceUKockici, dy + visinaKu�iceUKockici);
}

void C�ovje�eNeLjutiSeView::iscrtajFiguru(CDC * pDC, double dx, double dy)
{
	double po�etakTijelaDx = dx + duljinaKu�iceUKockici;
	double po�etakTijelaDy = dy + visinaKu�iceUKockici;
	double krajTijelaDx = (dx + duljinaKu�ice) - duljinaKu�iceUKockici;
	double krajTijelaDy = (dy + visinaKu�ice) - visinaKu�iceUKockici;

	double po�etakGlaveDx = po�etakTijelaDx + duljinaKu�iceUKockici;
	double po�etakGlaveDy = po�etakTijelaDy + visinaKu�iceUKockici;
	double krajGlaveDx = po�etakGlaveDx + duljinaKu�iceUKockici;
	double krajGlaveDy = po�etakGlaveDy + visinaKu�iceUKockici;
	CBrush* oldPen;
	pDC->Ellipse(po�etakTijelaDx, po�etakTijelaDy, krajTijelaDx, krajTijelaDy);
	CBrush brush1;
	brush1.CreateSolidBrush(RGB(204, 0, 204));
	oldPen=pDC->SelectObject(&brush1);
	pDC->Ellipse(po�etakGlaveDx, po�etakGlaveDy, krajGlaveDx, krajGlaveDy);
	pDC->SelectObject(oldPen);
	DeleteObject(brush1);
}

CBrush*  C�ovje�eNeLjutiSeView::vratiBrush(Igra� trenutniIgra�)
{
	switch (trenutniIgra�.vratiBoju()) {
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

void C�ovje�eNeLjutiSeView::prodiPoljaHorizontalno(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKu�ice;
		p.top = dy;
		p.bottom = dy + visinaKu�ice;
		plo�a.push_back(p);
		dx = dx + duljinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::prodiPoljaVertikalno(double dx, double dy, int brojPoljaZaProci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaProci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKu�ice;
		p.top = dy;
		p.bottom = dy + visinaKu�ice;
		plo�a.push_back(p);
		dy = dy + visinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::prodiKucicu(double dx, double dy,int indeks)
{
	RECT r;
	int i = 0;
	
	while (i < 2) {
		r.left = dx;
		r.right = dx+duljinaKu�ice;
		r.top = dy;
		r.bottom = dy + visinaKu�ice;
		ku�ice[indeks].push_back(r);
		poljaKu�ice[indeks].push_back(r);
		r.left = dx + duljinaKu�ice;
		r.right = dx + duljinaKu�ice * 2;
		ku�ice[indeks].push_back(r);
		poljaKu�ice[indeks].push_back(r);
		dy = dy + visinaKu�ice;
		++i;
	}
	
}

void C�ovje�eNeLjutiSeView::prodiCiljVertikalno(int index)
{
	double dx = petiStupac;
	double dy = devetiRed;
	int i = 0;
	while (i<4) {
		poljaCiljeva[index].push_back(CRect(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice));
		dy -= visinaKu�ice;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::prodiCiljHorizontalno(int index)
{
	double dx = duljinaKu�ice;
	double dy = petiRed;
	int i = 0;
	while (i<4) {
		poljaCiljeva[index].push_back(CRect(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice));
		dx += duljinaKu�ice;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::prodiCiljVertikalnoOdGorePremaDolje(int index)
{
	double dx = petiStupac;
	double dy = 0;
	int i = 0;
	while (i<4) {
		poljaCiljeva[index].push_back(CRect(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice));
		dy += visinaKu�ice;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::prodiCiljHorizontalnoSDesnaNaLijevo(int index)
{
	double dx = devetiStupac;
	double dy = petiRed;
	int i = 0;
	while (i<4) {
		poljaCiljeva[index].push_back(CRect(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice));
		dx -= duljinaKu�ice;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::prodiPoljaVertikalnoPremaGore(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKu�ice;
		p.top = dy;
		p.bottom = dy + visinaKu�ice;
		plo�a.push_back(p);
		dy = dy - visinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::prodiPoljaHorizontalnoSDesnaNaLijevo(double dx, double dy, int brojPoljaZaPoci)
{
	RECT p;
	for (int i = 0; i < brojPoljaZaPoci; ++i) {
		p.left = dx;
		p.right = dx + duljinaKu�ice;
		p.top = dy;
		p.bottom = dy + visinaKu�ice;
		plo�a.push_back(p);
		dx = dx - duljinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::inicijalizirajVarijableCrtanja()
{
	CRect r;
	GetClientRect(&r);
	duljinaKu�ice =r.right / brojRedova;
	visinaKu�ice = r.bottom / brojRedova;
	//stupci
	cetvrtiStupac = duljinaKu�ice * 4;
	petiStupac = duljinaKu�ice * 5;
	sestiStupac = duljinaKu�ice * 6;
	sedmiStupac = duljinaKu�ice * 7;
	devetiStupac = duljinaKu�ice * 9;
	desetiStupac = duljinaKu�ice * 10;
	//redci
	cetvrtiRed = visinaKu�ice * 4;
	petiRed = visinaKu�ice * 5;
	sestiRed = visinaKu�ice * 6;
	sedmiRed = visinaKu�ice * 7;
	devetiRed = visinaKu�ice * 9;
	desetiRed = visinaKu�ice * 10;
	duljinaKu�iceUKockici = duljinaKu�ice / 5;
	visinaKu�iceUKockici = visinaKu�ice / 5;
}

void C�ovje�eNeLjutiSeView::inicijalizirajVektorPolja()
{
	prodiPoljaHorizontalno(0, cetvrtiRed, 5);
	prodiPoljaVertikalnoPremaGore(cetvrtiStupac, cetvrtiRed-visinaKu�ice, 4);
	plo�a.push_back(CRect(petiStupac, 0, sestiStupac, visinaKu�ice));
	prodiPoljaVertikalno(sestiStupac, 0, 4);
	prodiPoljaHorizontalno(sestiStupac, cetvrtiRed, 5);
	plo�a.push_back(CRect(desetiStupac, petiRed, duljinaKu�ice * 11, sestiRed));
	prodiPoljaHorizontalnoSDesnaNaLijevo(desetiStupac, sestiRed, 5);
	prodiPoljaVertikalno(sestiStupac, sedmiRed , 4);
	plo�a.push_back(CRect(petiStupac, desetiRed, sestiStupac, visinaKu�ice * 11));
	prodiPoljaVertikalnoPremaGore(cetvrtiStupac, desetiRed, 4);
	prodiPoljaHorizontalnoSDesnaNaLijevo(cetvrtiStupac, sestiRed, 4);
	plo�a.push_back(CRect(0, sestiRed, duljinaKu�ice, sedmiRed));
}

void C�ovje�eNeLjutiSeView::inicijalizirajKu�icu(Boja b)
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
	ku�ice.push_back(vec);
	poljaKu�ice.push_back(vec);
	prodiKucicu(dx, dy,indeks);
}

void C�ovje�eNeLjutiSeView::inicijalizirajCiljeve(Boja b)
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

void C�ovje�eNeLjutiSeView::isprazniKontenjereProsleIgre()
{
	ku�ice.clear();
	ciljevi.clear();
	poljaCiljeva.clear();
	poljaKu�ice.clear();
	figureNaPolju.clear();
	plo�a.clear();
}

void C�ovje�eNeLjutiSeView::osvjeziPolje(RECT r,int izbrisi)
{
	r.left += duljinaKu�iceUKockici;
	r.top += visinaKu�iceUKockici;
	r.right -= duljinaKu�iceUKockici;
	r.bottom -= visinaKu�iceUKockici;
	InvalidateRect(&r, izbrisi);
}

void C�ovje�eNeLjutiSeView::postaviFiguruNaPocetnoPolje()
{
	bool poljeJeZauzeto = false;
	RECT poljeFigure = plo�a.at(trenutniIgrac.vratiPo�etnoPolje());
	if(trenutniIgrac.brojFiguraNaPolju>0){
		for( auto r : figureNaPolju[igra->indeksIgra�a]) {
			if (r == poljeFigure)
				poljeJeZauzeto = true;
		}
	}
	if (!poljeJeZauzeto) {
		if (ku�ice[igra->indeksIgra�a].size() > 1) {
			ku�ice[igra->indeksIgra�a].pop_back();
		}
		else {
			ku�ice[igra->indeksIgra�a].clear();
		}
			figureNaPolju[igra->indeksIgra�a].push_back(poljeFigure);
			igra->pomakniFiguruNaPo�etnoPolje(&igra->igra�i[igra->indeksIgra�a]);
			trenutniIgrac = igra->igra�i[igra->indeksIgra�a];
			figura = &trenutniIgrac.figureNaPolju.back();
	}
	Invalidate();
}
void C�ovje�eNeLjutiSeView::pomakniFiguru()
{
	std::vector<Figura> vec = trenutniIgrac.figureNaPolju;
	auto it = std::find(vec.begin(), vec.end(),*figura);
	int index;
	if (it != vec.end())
		index = std::distance(vec.begin(), it);

	RECT poljeNaKojemJeFigura = figureNaPolju[igra->indeksIgra�a].at(index);
	int staroPoljeUCiljuFigure = figura->poljeUKu�i;

	if (igra->pomakniFiguru(&igra->igra�i[igra->indeksIgra�a], figura, brojSKocke)) {
		if (igra->poljeJeZauzeto) {
			figureNaPolju[igra->indeksIgracaNaZauzetomPolju].erase(std::next(figureNaPolju[igra->indeksIgracaNaZauzetomPolju].begin(),igra->indeksZauzetogPolja));
			ku�ice[igra->indeksIgracaNaZauzetomPolju].push_back(poljaKu�ice[igra->indeksIgracaNaZauzetomPolju][(ku�ice[igra->indeksIgracaNaZauzetomPolju].size())]);
			igra->vratiPromjeneNakonZauzetoPolja();
		}
		trenutniIgrac = igra->igra�i[igra->indeksIgra�a];
		if (trenutniIgrac.zadnjeSlobodnoMjestoUKu�i == 0) {
		//protresi cilj igra�a
		//makni ga iz igre
			igra->igra�i.erase(igra->igra�i.begin() + igra->indeksIgra�a);
		//ako je u igri samo jedan igra� on je izgubio i kraj igre
		}if (staroPoljeUCiljuFigure < figura->poljeUKu�i) {
			if (figureNaPolju[igra->indeksIgra�a].size() > 1) {
				figureNaPolju[igra->indeksIgra�a].erase(std::next(figureNaPolju[igra->indeksIgracaNaZauzetomPolju].begin(), index));
			}
			else {
				figureNaPolju[igra->indeksIgra�a].clear();
			}
			if(figura->poljeUKu�i>3)
				figura->poljeUKu�i=3;
			ciljevi[igra->indeksIgra�a].push_back(poljaCiljeva[igra->indeksIgra�a][figura->poljeUKu�i]);
		}
		else {
			auto itPolja = std::next(plo�a.begin(), figura->vratiTrenutnoPolje());
			if (itPolja != plo�a.end()) {
				figureNaPolju[igra->indeksIgra�a].at(index) = *itPolja;
			}
		}
		Invalidate();
	}
	else {
		protresiDostupneFigure();
		return;
	}
}

void C�ovje�eNeLjutiSeView::OnDraw(CDC* pDC)
{
	C�ovje�eNeLjutiSeDoc* pDoc = GetDocument();
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
	if (kockaSeOkre�e) {
		switch (brojSKocke)
		{
		case 1:
			iscrtajKockuJedan(pDC, petiStupac + duljinaKu�iceUKockici * 2, petiRed + visinaKu�iceUKockici * 2);
			break;
		case 2:
			iscrtajKockuDva(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + visinaKu�iceUKockici);
			break;
		case 3:
			iscrtajKockuTri(pDC, petiStupac + duljinaKu�iceUKockici * 2, petiRed + 5);
			break;
		case 4:
			iscrtajKockuCetri(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + visinaKu�iceUKockici);
			break;
		case 5:
			iscrtajKockuPet(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + 5);
			break;
		case 6:
			iscrtajKockuSest(pDC, petiStupac + duljinaKu�iceUKockici, petiRed + 5);
			break;
		default:
			break;
		}	
	}
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	iscrtajPolje(pDC, 0, 0);
	int indexIgraca = 0;
	for (auto i : ku�ice) {
		for (auto r : i) {
			oldBrush = pDC->SelectObject(vratiBrush(igra->igra�i[indexIgraca]));
			iscrtajFiguru(pDC, r.left, r.top);
			delete (pDC->SelectObject(oldBrush));
		}
		++indexIgraca;
	}
	indexIgraca = 0;
	for (auto i : figureNaPolju) {
		for (auto r : i) {
			if (indexIgraca < igra->igra�i.size()) {
				oldBrush = pDC->SelectObject(vratiBrush(igra->igra�i[indexIgraca]));
				iscrtajFiguru(pDC, r.left, r.top);
				delete (pDC->SelectObject(oldBrush));
			}
		}
		++indexIgraca;
	}
	indexIgraca = 0;
	for (auto i : ciljevi) {
		for (auto r : i) {
			if (indexIgraca < igra->igra�i.size()) {
				oldBrush = pDC->SelectObject(vratiBrush(igra->igra�i[indexIgraca]));
				iscrtajFiguru(pDC, r.left, r.top);
				delete (pDC->SelectObject(oldBrush));
			}
		}
		++indexIgraca;
	}
	ReleaseDC(pDC);
		
}


// C�ovje�eNeLjutiSeView diagnostics

#ifdef _DEBUG
void C�ovje�eNeLjutiSeView::AssertValid() const
{
	CView::AssertValid();
}

void C�ovje�eNeLjutiSeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


void C�ovje�eNeLjutiSeView::OnTimer(UINT_PTR nIDEvent)
{
	static int brojOkretajaKocke = 0;
		
			if (brojOkretajaKocke < 5) {
				if (!kockaSeOkre�e)
					kockaSeOkre�e = true;
				srand(time(NULL));
				brojSKocke = rand() % 6 + 1;
				++brojOkretajaKocke;
				InvalidateRect(CRect(petiStupac, petiRed, sestiStupac, sestiRed));
			}
			else {
				KillTimer(timer);
				kockaSeOkre�e = false;
				brojOkretajaKocke = 0;
				igraj();
			}
}

void C�ovje�eNeLjutiSeView::OnLButtonDown(UINT nFlags, CPoint point)
{

	if (brojBacanjaKocke > 0||brojSKocke==6) {
		if (!kockaSeOkre�e) {
			if (point.x > duljinaKu�ice * 5 && point.x < duljinaKu�ice * 6) {
				if (point.y > visinaKu�ice * 5 && point.y < visinaKu�ice * 6) {
					--brojBacanjaKocke;
					timer = SetTimer(1, 500, 0);
				}

			}
		}
	}
	


}

void C�ovje�eNeLjutiSeView::OnFileNewDvaIgra�a()
{
	igra = new Igra(2);
	if (poljaKu�ice.size() > 0)
		isprazniKontenjereProsleIgre();
	trenutniIgrac = igra->prviIgra�();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgra�e())
	{
		inicijalizirajKu�icu(igrac.vratiBoju());
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

void C�ovje�eNeLjutiSeView::OnFileNewTriIgra�a()
{
	igra = new Igra(3);
	if (poljaKu�ice.size() > 0)
		isprazniKontenjereProsleIgre();
	trenutniIgrac = igra->prviIgra�();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgra�e())
	{
		inicijalizirajKu�icu(igrac.vratiBoju());
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

void C�ovje�eNeLjutiSeView::OnFileNewCetriIgra�a()
{
	igra = new Igra(4);
	if (poljaKu�ice.size() > 0)
		isprazniKontenjereProsleIgre();
	trenutniIgrac = igra->prviIgra�();
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	std::vector<RECT> vec;
	for (auto igrac : igra->vratiIgra�e())
	{
		inicijalizirajKu�icu(igrac.vratiBoju());
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

void C�ovje�eNeLjutiSeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	bool postaviNaPocetnoPolje = false;
	if (brojSKocke == 6) {
		if (trenutniIgrac.brojFiguraUKu�ici > 0) {
			for (auto var : ku�ice[igra->indeksIgra�a])
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
		for  (auto var : figureNaPolju[igra->indeksIgra�a])
		{
			if (var.left <= point.x && point.x <= var.right)
				if (var.top <= point.y&&point.y <= var.bottom) {
					figuraJeOdabrana = true;
					r = var;
				}
		}
		std::vector<RECT> vec = figureNaPolju[igra->indeksIgra�a];
		if (figuraJeOdabrana) {
			auto it = std::find(vec.begin(), vec.end(), r);
			if (it != vec.end()) {
				int index = std::distance(vec.begin(), it);
				figura = &igra->igra�i[igra->indeksIgra�a].figureNaPolju[index];
			}
		}
	}
	if (trenutniIgrac.brojFiguraUCilju > 0) {
		RECT r;
		for (auto var : ciljevi[igra->indeksIgra�a])
		{
			if (var.left <= point.x && point.x <= var.right)
				if (var.top <= point.y&&point.y <= var.bottom) {
					figuraJeOdabrana = true;
					r = var;
				}
		}
		std::vector<RECT> vec = poljaCiljeva[igra->indeksIgra�a];
		if (figuraJeOdabrana) {
			auto it = std::find(vec.begin(), vec.end(), r);
			if (it != vec.end()) {
				int index = std::distance(vec.begin(), it);
				figura = igra->igra�i[igra->indeksIgra�a].ku�a[index];
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



C�ovje�eNeLjutiSeDoc* C�ovje�eNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ovje�eNeLjutiSeDoc)));
	return (C�ovje�eNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG
