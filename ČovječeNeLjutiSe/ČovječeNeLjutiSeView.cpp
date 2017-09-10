

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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CÈovjeèeNeLjutiSeView construction/destruction

CÈovjeèeNeLjutiSeView::CÈovjeèeNeLjutiSeView()
{


}



CÈovjeèeNeLjutiSeView::~CÈovjeèeNeLjutiSeView()
{
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
	trenutniIgrac = igra->promjenaIgraèa(&trenutniIgrac);
	pDC->SelectObject(oldBrush);
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

void CÈovjeèeNeLjutiSeView::potresiDostupneFigure()
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
				iscrtajFiguru(pDC, var.left, var.top);
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

void CÈovjeèeNeLjutiSeView::prodiKucicu(double dx, double dy)
{
	RECT r;
	int i = 0;
	std::vector<RECT> vec;
	while (i < 2) {
		r.left = dx;
		r.right = dy+duljinaKuèice;
		r.top = dy;
		r.bottom = dy + visinaKuèice;
		vec.push_back(r);
		r.left = dx + duljinaKuèice;
		r.right = dx + duljinaKuèice * 2;
		vec.push_back(r);
		dy = dy + visinaKuèice;
		++i;
	}
	kuèice.push_back(vec);
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
	prodiPoljaHorizontalno(0, petiRed, 5);
	prodiPoljaVertikalnoPremaGore(petiStupac, cetvrtiRed, 4);
	ploèa.push_back(CRect(petiStupac, 0, sestiStupac, visinaKuèice));
	prodiPoljaVertikalno(sestiStupac, 0, 4);
	prodiPoljaHorizontalno(sestiRed, petiRed, 5);
	ploèa.push_back(CRect(desetiStupac, sestiRed, duljinaKuèice * 11, sedmiRed));
	prodiPoljaHorizontalnoSDesnaNaLijevo(desetiStupac, sedmiRed, 5);
	prodiPoljaVertikalnoPremaGore(sestiStupac, sedmiRed + visinaKuèice, 4);
	ploèa.push_back(CRect(petiStupac, desetiRed, sestiStupac, visinaKuèice * 11));
	prodiPoljaVertikalno(petiStupac, desetiRed, 4);
	prodiPoljaHorizontalnoSDesnaNaLijevo(cetvrtiRed, sedmiRed, 4);
	ploèa.push_back(CRect(0, sestiRed, duljinaKuèice, sedmiRed));
}

void CÈovjeèeNeLjutiSeView::inicijalizirajKuèicu(Boja b)
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

void CÈovjeèeNeLjutiSeView::osvjeziPolje(RECT r,int izbrisi)
{
	r.left += duljinaKuèiceUKockici;
	r.top += visinaKuèiceUKockici;
	r.right -= duljinaKuèiceUKockici;
	r.bottom -= visinaKuèiceUKockici;
	InvalidateRect(&r, izbrisi);
}

void CÈovjeèeNeLjutiSeView::postaviFiguruNaPocetnoPolje(CDC* pDC,Igraè trenutniIgraè)
{
	osvjeziPolje(kuèice[igra->indeksIgraèa].back(), 1);
	kuèice[igra->indeksIgraèa].pop_back();
	RECT poljeFigure = ploèa.at(trenutniIgraè.vratiPoèetnoPolje());
	figureNaPolju[igra->indeksIgraèa].push_back(poljeFigure);
	iscrtajFiguru(pDC, poljeFigure.left, poljeFigure.top);
	osvjeziPolje(poljeFigure, 0);
	igra->pomakniFiguruNaPoèetnoPolje(trenutniIgraè);
	figura = trenutniIgraè.figureNaPolju.back();
}

void CÈovjeèeNeLjutiSeView::odaberiFiguru()
{
	while (!figuraJeOdabrana);
}

void CÈovjeèeNeLjutiSeView::pomakniFiguru(Figura fig)
{
	std::vector<Figura> vec = trenutniIgrac.figureNaPolju;
	auto it = std::find(vec.begin(), vec.end(), fig);
	int index;
	if (it != vec.end())
		index = std::distance(vec.begin(), it);
	RECT poljeNaKojemJeFigura = figureNaPolju[igra->indeksIgraèa].at(index);
	if (igra->pomakniFiguru(&trenutniIgrac, &fig, brojSKocke)) {
		auto itPolja = std::next(std::find(ploèa.begin(), ploèa.end(), poljeNaKojemJeFigura), brojSKocke);
		if (itPolja != ploèa.end()) {
			figureNaPolju[igra->indeksIgraèa].at(index)= *itPolja;
			osvjeziPolje(poljeNaKojemJeFigura, 1);
			osvjeziPolje(*itPolja,0);
		}
	}
}
void CÈovjeèeNeLjutiSeView::kockaSeVrti()
{
	while (bacajKocku);
}
void CÈovjeèeNeLjutiSeView::OnDraw(CDC* pDC)
{
	CÈovjeèeNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush* oldBrush;
	CBrush crnaPozadina(RGB(0, 0, 0));
	oldBrush=pDC->SelectObject(&crnaPozadina);
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
		pDC->SelectObject(oldBrush);
	}
	

	// TODO: add draw code for native data here
}


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
		InvalidateRect(CRect(duljinaKuèice * 5, visinaKuèice * 5, duljinaKuèice * 6, visinaKuèice * 6));
	}
	else {
		KillTimer(timer);
		igraj();
		kockaSeOkreæe = false;
		brojOkretajaKocke = 0;
		
	}


}

void CÈovjeèeNeLjutiSeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	POINT p;
	GetCursorPos(&p);
	if (bacajKocku) {
		if (point.x > duljinaKuèice * 5 && point.x < duljinaKuèice * 6) {
			if (point.y > visinaKuèice * 5 && point.y < visinaKuèice * 6)
				timer = SetTimer(1, 1000, 0);
			bacajKocku = false;
		}
	}
	


}

void CÈovjeèeNeLjutiSeView::OnFileNewDvaIgraèa()
{
	
	CBrush* oldBrush;
	CBrush plavaPozadina(RGB(51, 51, 255));
	CBrush crvenaPozadina(RGB(255, 0, 0));
	CDC* pDC = this->GetDC();
	igra = new Igra(2);
	trenutniIgrac = igra->prviIgraè();
	int indeks = 0;
	bacajKocku = true;
	inicijalizirajVarijableCrtanja();
	inicijalizirajVektorPolja();
	iscrtajPolje(pDC, 0, 0);
	std::vector<RECT> vec;
	for each (Igraè igrac in igra->vratiIgraèe())
	{
		inicijalizirajKuèicu(igrac.vratiBoju());
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
			for each(RECT r in kuèice[indeks]) {
				iscrtajFiguru(pDC, r.left, r.top);
			}
			pDC->SelectObject(oldBrush);
		}
		
	}

void CÈovjeèeNeLjutiSeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	POINT p;
	GetCursorPos(&p);
	if (brojSKocke == 6) {
		for each (RECT var in kuèice[igra->indeksIgraèa])
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
	for each (RECT var in figureNaPolju[igra->indeksIgraèa])
	{
		if (var.left >= p.x&&var.right <= p.x)
			if (var.top >= p.y&&var.bottom <= p.y) {
				figuraJeOdabrana = true;
				r = var;
			}
	}
	std::vector<RECT> vec = figureNaPolju[igra->indeksIgraèa];
	if (figuraJeOdabrana) {
		auto it = std::find(vec.begin(), vec.end(), r);
		if (it != vec.end()) {
			int index = std::distance(vec.begin(), it);
			figura = trenutniIgrac.figureNaPolju[index];
		}
	}
}



CÈovjeèeNeLjutiSeDoc* CÈovjeèeNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CÈovjeèeNeLjutiSeDoc)));
	return (CÈovjeèeNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG
