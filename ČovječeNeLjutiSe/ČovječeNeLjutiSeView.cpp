
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
	ON_COMMAND(ID_FILE_NEW, &CÈovjeèeNeLjutiSeView::OnFileNew)
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

void CÈovjeèeNeLjutiSeView::iscrtajPolje(CDC* pDC, double dx, double dy, RECT r)
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

	//stupci
	double cetvrtiStupac = duljinaKuèice * 4;
	double petiStupac = duljinaKuèice * 5;
	double sestiStupac = duljinaKuèice * 6;
	double sedmiStupac = duljinaKuèice * 7;
	double devetiStupac = duljinaKuèice * 9;
	double desetiStupac = duljinaKuèice * 10;
	//redci
	double cetvrtiRed = visinaKuèice * 4;
	double petiRed = visinaKuèice * 5;
	double sestiRed = visinaKuèice * 6;
	double sedmiRed = visinaKuèice * 7;
	double devetiRed = visinaKuèice * 9;
	double desetiRed = visinaKuèice * 10;

	
	timer = SetTimer(1, 200, 0);
	oldPen = pDC->SelectObject(&crvenaOlovka);
	iscrtajKuèicu(pDC, 0, 0, r);
	pDC->SelectObject(oldPen);	

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKuèicu(pDC, devetiStupac, 0, r);
	pDC->SelectObject(oldPen);
	

	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKuèicu(pDC, 0, devetiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKuèicu(pDC, devetiStupac, devetiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	
	iscrtajCijeliRedHorizontalno(pDC,0,cetvrtiRed,r);
	iscrtajCijeliRedHorizontalno(pDC, 0, sestiRed, r);
	iscrtajCijeliRedVertikalno(pDC, cetvrtiStupac, 0, r);
	iscrtajCijeliRedVertikalno(pDC, sestiStupac, 0, r);
	pDC->Ellipse(0, petiRed, duljinaKuèice, sestiRed);
	pDC->Ellipse(petiStupac, desetiRed,  sestiStupac, r.bottom);
	pDC->Ellipse(desetiStupac, petiRed, r.right, sestiRed);
	pDC->Ellipse(petiStupac, 0, sestiStupac, visinaKuèice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, cetvrtiRed, duljinaKuèice, petiRed);
	iscrtajCiljHorizontalno(pDC, duljinaKuèice, petiRed, r);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(desetiStupac, sestiRed, r.right, sedmiRed);
	iscrtajCiljHorizontalno(pDC, sestiStupac, petiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(sestiStupac, 0, sedmiStupac, visinaKuèice);
	iscrtajCiljVertikalno(pDC, petiStupac, visinaKuèice, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(cetvrtiStupac, desetiRed, petiStupac, r.bottom);
	iscrtajCiljVertikalno(pDC, petiStupac, sestiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	pDC->Rectangle(petiStupac, petiRed, sestiStupac, sestiRed);
	pDC->SelectObject(oldPen);
	
	pDC->SelectObject(&crvenaPozadina);
	iscrtajFiguru(pDC,0,0);
	pDC->SelectObject(&crnaPozadina);
	switch (i)
	{
	case 1:
		iscrtajKockuJedan(pDC,petiStupac+duljinaKuèiceUKockici*2,petiRed+visinaKuèiceUKockici*2);
		break;
	case 2:
		iscrtajKockuDva(pDC, petiStupac + duljinaKuèiceUKockici, petiRed+visinaKuèiceUKockici);
		break;
	case 3:
		iscrtajKockuTri(pDC, petiStupac + duljinaKuèiceUKockici*2, petiRed + 5);
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

}

void CÈovjeèeNeLjutiSeView::iscrtajKuèicu(CDC * pDC, double dx, double dy, RECT r)
{	
	int i = 1;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		pDC->Ellipse(dx+duljinaKuèice, dy, dx +duljinaKuèice*2, dy + visinaKuèice);
		dy = dy + visinaKuèice;
		++i;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajCijeliRedHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	while (dx +duljinaKuèice< r.right) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dx += duljinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	while (dy < r.bottom) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dy += visinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dx += duljinaKuèice;
		++i;
	}

}

void CÈovjeèeNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dy += visinaKuèice;
		++i;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajKockuSest(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx = dx + duljinaKuèiceUKockici + duljinaKuèiceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKuèiceUKockici, dy + visinaKuèiceUKockici);
		dx=dx- duljinaKuèiceUKockici - duljinaKuèiceUKockici;
		dy = dy + visinaKuèiceUKockici + visinaKuèiceUKockici-5;
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
		dy = dy + visinaKuèiceUKockici *4 - 10;
		++i;
	}
	dx = dx + duljinaKuèiceUKockici;
	dy = dy - visinaKuèiceUKockici*4-1;
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

	pDC->Ellipse(poèetakTijelaDx, poèetakTijelaDy, krajTijelaDx, krajTijelaDy);
	CBrush brush1;   
	brush1.CreateSolidBrush(RGB(204, 0, 204));
	pDC->SelectObject(&brush1);
	pDC->Ellipse(poèetakGlaveDx, poèetakGlaveDy, krajGlaveDx, krajGlaveDy);
}

void CÈovjeèeNeLjutiSeView::OnDraw(CDC* pDC)
{
	CÈovjeèeNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	RECT r;
	GetClientRect(&r);
	int brojRedova = 11;
	duljinaKuèice = r.right / brojRedova;
	visinaKuèice = r.bottom / brojRedova;
	duljinaKuèiceUKockici = duljinaKuèice / 5;
	visinaKuèiceUKockici = visinaKuèice / 5;
	iscrtajPolje(pDC, 0, 0, r);
	
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
	srand(time(NULL));
	i= rand() % 6 + 1;
	InvalidateRect(CRect(duljinaKuèice*5,visinaKuèice*5,duljinaKuèice*6,visinaKuèice*6));
	
}

void CÈovjeèeNeLjutiSeView::OnFileNew()
{
	timer= timer = SetTimer(1, 500, 0);
}


CÈovjeèeNeLjutiSeDoc* CÈovjeèeNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CÈovjeèeNeLjutiSeDoc)));
	return (CÈovjeèeNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG


// CÈovjeèeNeLjutiSeView message handlers
