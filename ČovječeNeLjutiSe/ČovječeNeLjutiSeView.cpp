

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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C�ovje�eNeLjutiSeView construction/destruction

C�ovje�eNeLjutiSeView::C�ovje�eNeLjutiSeView()
{


}



C�ovje�eNeLjutiSeView::~C�ovje�eNeLjutiSeView()
{
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
	CDC* pDC =this-> GetDC();
	CBrush* oldBrush;
	oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	for (int i = 1; i < igra->brojBacanjaKocke(trenutniIgrac) && brojSKocke != 6;++i) {
		bacajKocku = true;
		kockaSeVrti();
	}
	potresiDostupneFigure();
	if (brojSKocke == 6 || trenutniIgrac.brojFiguraNaPolju > 0) {
		odaberiFiguru();
		pomakniFiguru(figura);
		if (brojSKocke == 6)
			return;
	}
	trenutniIgrac = igra->promjenaIgra�a(&trenutniIgrac);
	pDC->SelectObject(oldBrush);
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

	oldPen = pDC->SelectObject(&crnaOlovka);
	pDC->Rectangle(petiStupac, petiRed, sestiStupac, sestiRed);
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

void C�ovje�eNeLjutiSeView::potresiDostupneFigure()
{
	CDC* pDC = this->GetDC();
	CBrush* oldBrush = pDC->SelectObject(vratiBrush(trenutniIgrac));
	if (brojSKocke == 6) {
		for each (RECT var in ku�ice[igra->indeksIgra�a])
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
	if (figureNaPolju[igra->indeksIgra�a].size() > 0) {
		for each (RECT var in figureNaPolju[igra->indeksIgra�a])
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
	pDC->SelectObject(oldBrush);	
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

void C�ovje�eNeLjutiSeView::prodiKucicu(double dx, double dy)
{
	RECT r;
	int i = 0;
	std::vector<RECT> vec;
	while (i < 2) {
		r.left = dx;
		r.right = dy+duljinaKu�ice;
		r.top = dy;
		r.bottom = dy + visinaKu�ice;
		vec.push_back(r);
		r.left = dx + duljinaKu�ice;
		r.right = dx + duljinaKu�ice * 2;
		vec.push_back(r);
		dy = dy + visinaKu�ice;
		++i;
	}
	ku�ice.push_back(vec);
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
	prodiPoljaHorizontalno(0, petiRed, 5);
	prodiPoljaVertikalnoPremaGore(petiStupac, cetvrtiRed, 4);
	plo�a.push_back(CRect(petiStupac, 0, sestiStupac, visinaKu�ice));
	prodiPoljaVertikalno(sestiStupac, 0, 4);
	prodiPoljaHorizontalno(sestiRed, petiRed, 5);
	plo�a.push_back(CRect(desetiStupac, sestiRed, duljinaKu�ice * 11, sedmiRed));
	prodiPoljaHorizontalnoSDesnaNaLijevo(desetiStupac, sedmiRed, 5);
	prodiPoljaVertikalnoPremaGore(sestiStupac, sedmiRed + visinaKu�ice, 4);
	plo�a.push_back(CRect(petiStupac, desetiRed, sestiStupac, visinaKu�ice * 11));
	prodiPoljaVertikalno(petiStupac, desetiRed, 4);
	prodiPoljaHorizontalnoSDesnaNaLijevo(cetvrtiRed, sedmiRed, 4);
	plo�a.push_back(CRect(0, sestiRed, duljinaKu�ice, sedmiRed));
}

void C�ovje�eNeLjutiSeView::inicijalizirajKu�icu(Boja b)
{
	double dx, dy;
	switch (b) {
	case Boja::CRVENA:
		dx = 0;
		dy = 0;
		break;
	case Boja::PLAVA:
		dx = devetiStupac;
		dy = 0;
		break;
	case Boja::ZELENA:
		dx = 0;
		dy = devetiRed;
		break;
	case Boja::ZUTA:
		dx = devetiStupac;
		dy = devetiRed;
		break;
	}
	prodiKucicu(dx, dy);
}

void C�ovje�eNeLjutiSeView::osvjeziPolje(RECT r,int izbrisi)
{
	r.left += duljinaKu�iceUKockici;
	r.top += visinaKu�iceUKockici;
	r.right -= duljinaKu�iceUKockici;
	r.bottom -= visinaKu�iceUKockici;
	InvalidateRect(&r, izbrisi);
}

void C�ovje�eNeLjutiSeView::postaviFiguruNaPocetnoPolje(CDC* pDC,Igra� trenutniIgra�)
{
	osvjeziPolje(ku�ice[igra->indeksIgra�a].back(), 1);
	ku�ice[igra->indeksIgra�a].pop_back();
	RECT poljeFigure = plo�a.at(trenutniIgra�.vratiPo�etnoPolje());
	figureNaPolju[igra->indeksIgra�a].push_back(poljeFigure);
	iscrtajFiguru(pDC, poljeFigure.left, poljeFigure.top);
	osvjeziPolje(poljeFigure, 0);
	igra->pomakniFiguruNaPo�etnoPolje(trenutniIgra�);
	figura = trenutniIgra�.figureNaPolju.back();
}

void C�ovje�eNeLjutiSeView::odaberiFiguru()
{
	while (!figuraJeOdabrana);
}

void C�ovje�eNeLjutiSeView::pomakniFiguru(Figura fig)
{
	std::vector<Figura> vec = trenutniIgrac.figureNaPolju;
	auto it = std::find(vec.begin(), vec.end(), fig);
	int index;
	if (it != vec.end())
		index = std::distance(vec.begin(), it);
	RECT poljeNaKojemJeFigura = figureNaPolju[igra->indeksIgra�a].at(index);
	if (igra->pomakniFiguru(&trenutniIgrac, &fig, brojSKocke)) {
		auto itPolja = std::next(std::find(plo�a.begin(), plo�a.end(), poljeNaKojemJeFigura), brojSKocke);
		if (itPolja != plo�a.end()) {
			figureNaPolju[igra->indeksIgra�a].at(index)= *itPolja;
			osvjeziPolje(poljeNaKojemJeFigura, 1);
			osvjeziPolje(*itPolja,0);
		}
	}
}
void C�ovje�eNeLjutiSeView::kockaSeVrti()
{
	while (bacajKocku);
}
void C�ovje�eNeLjutiSeView::OnDraw(CDC* pDC)
{
	C�ovje�eNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush* oldBrush;
	CBrush crnaPozadina(RGB(0, 0, 0));
	oldBrush=pDC->SelectObject(&crnaPozadina);
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
		pDC->SelectObject(oldBrush);
	}
	

	// TODO: add draw code for native data here
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
		InvalidateRect(CRect(duljinaKu�ice * 5, visinaKu�ice * 5, duljinaKu�ice * 6, visinaKu�ice * 6));
	}
	else {
		KillTimer(timer);
		igraj();
		kockaSeOkre�e = false;
		brojOkretajaKocke = 0;
		
	}


}

void C�ovje�eNeLjutiSeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	POINT p;
	GetCursorPos(&p);
	if (bacajKocku) {
		if (point.x > duljinaKu�ice * 5 && point.x < duljinaKu�ice * 6) {
			if (point.y > visinaKu�ice * 5 && point.y < visinaKu�ice * 6)
				timer = SetTimer(1, 1000, 0);
			bacajKocku = false;
		}
	}
	


}

void C�ovje�eNeLjutiSeView::OnFileNewDvaIgra�a()
{
	
	CBrush* oldBrush;
	CBrush plavaPozadina(RGB(51, 51, 255));
	CBrush crvenaPozadina(RGB(255, 0, 0));
	CDC* pDC = this->GetDC();
	igra = new Igra(2);
	trenutniIgrac = igra->prviIgra�();
	int indeks = 0;
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	iscrtajPolje(pDC, 0, 0);
	std::vector<RECT> vec;
	for each (Igra� igrac in igra->vratiIgra�e())
	{
		inicijalizirajKu�icu(igrac.vratiBoju());
			switch (igrac.vratiBoju()) {
				case Boja::CRVENA: 
					figureNaPolju.push_back(vec);
					ciljevi.push_back(vec);
					oldBrush=pDC->SelectObject(&crvenaPozadina);
					indeks = 0;
					break; 
				case Boja::PLAVA:	
					figureNaPolju.push_back(vec);
					ciljevi.push_back(vec);
					oldBrush = pDC->SelectObject(&plavaPozadina);
					indeks = 1;
					break;
				default:
					oldBrush = new CBrush();
					break;
			}
			for each(RECT r in ku�ice[indeks]) {
				iscrtajFiguru(pDC, r.left, r.top);
			}
			pDC->SelectObject(oldBrush);
		}
		
	}

void C�ovje�eNeLjutiSeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	POINT p;
	GetCursorPos(&p);
	if (brojSKocke == 6) {
		for each (RECT var in ku�ice[igra->indeksIgra�a])
		{
			if (var.left >= p.x&&var.right <= p.x)
				if (var.top >= p.y&&var.bottom <= p.y) {
					postaviFiguruNaPocetnoPolje(this->GetDC(), trenutniIgrac);
					figuraJeOdabrana = true;
					return;
				}
		}
	}
	RECT r;
	for each (RECT var in figureNaPolju[igra->indeksIgra�a])
	{
		if (var.left >= p.x&&var.right <= p.x)
			if (var.top >= p.y&&var.bottom <= p.y) {
				figuraJeOdabrana = true;
				r = var;
			}
	}
	std::vector<RECT> vec = figureNaPolju[igra->indeksIgra�a];
	if (figuraJeOdabrana) {
		auto it = std::find(vec.begin(), vec.end(), r);
		if (it != vec.end()) {
			int index = std::distance(vec.begin(), it);
			figura = trenutniIgrac.figureNaPolju[index];
		}
	}
}



C�ovje�eNeLjutiSeDoc* C�ovje�eNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ovje�eNeLjutiSeDoc)));
	return (C�ovje�eNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG
