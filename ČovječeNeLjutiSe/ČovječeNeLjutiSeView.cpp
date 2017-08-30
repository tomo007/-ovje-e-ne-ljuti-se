
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
	ON_COMMAND(ID_FILE_NEW, &CČovječeNeLjutiSeView::OnFileNew)
END_MESSAGE_MAP()

// CČovječeNeLjutiSeView construction/destruction

CČovječeNeLjutiSeView::CČovječeNeLjutiSeView()
{
	

}

CČovječeNeLjutiSeView::~CČovječeNeLjutiSeView()
{
}

BOOL CČovječeNeLjutiSeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CČovječeNeLjutiSeView drawing

void CČovječeNeLjutiSeView::iscrtajPolje(CDC* pDC, double dx, double dy, RECT r)
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
	double cetvrtiStupac = duljinaKučice * 4;
	double petiStupac = duljinaKučice * 5;
	double sestiStupac = duljinaKučice * 6;
	double sedmiStupac = duljinaKučice * 7;
	double devetiStupac = duljinaKučice * 9;
	double desetiStupac = duljinaKučice * 10;
	//redci
	double cetvrtiRed = visinaKučice * 4;
	double petiRed = visinaKučice * 5;
	double sestiRed = visinaKučice * 6;
	double sedmiRed = visinaKučice * 7;
	double devetiRed = visinaKučice * 9;
	double desetiRed = visinaKučice * 10;

	
	timer = SetTimer(1, 200, 0);
	oldPen = pDC->SelectObject(&crvenaOlovka);
	iscrtajKučicu(pDC, 0, 0, r);
	pDC->SelectObject(oldPen);	

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKučicu(pDC, devetiStupac, 0, r);
	pDC->SelectObject(oldPen);
	

	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKučicu(pDC, 0, devetiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKučicu(pDC, devetiStupac, devetiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	
	iscrtajCijeliRedHorizontalno(pDC,0,cetvrtiRed,r);
	iscrtajCijeliRedHorizontalno(pDC, 0, sestiRed, r);
	iscrtajCijeliRedVertikalno(pDC, cetvrtiStupac, 0, r);
	iscrtajCijeliRedVertikalno(pDC, sestiStupac, 0, r);
	pDC->Ellipse(0, petiRed, duljinaKučice, sestiRed);
	pDC->Ellipse(petiStupac, desetiRed,  sestiStupac, r.bottom);
	pDC->Ellipse(desetiStupac, petiRed, r.right, sestiRed);
	pDC->Ellipse(petiStupac, 0, sestiStupac, visinaKučice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, cetvrtiRed, duljinaKučice, petiRed);
	iscrtajCiljHorizontalno(pDC, duljinaKučice, petiRed, r);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(desetiStupac, sestiRed, r.right, sedmiRed);
	iscrtajCiljHorizontalno(pDC, sestiStupac, petiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(sestiStupac, 0, sedmiStupac, visinaKučice);
	iscrtajCiljVertikalno(pDC, petiStupac, visinaKučice, r);
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
		iscrtajKockuJedan(pDC,petiStupac+duljinaKučiceUKockici*2,petiRed+visinaKučiceUKockici*2);
		break;
	case 2:
		iscrtajKockuDva(pDC, petiStupac + duljinaKučiceUKockici, petiRed+visinaKučiceUKockici);
		break;
	case 3:
		iscrtajKockuTri(pDC, petiStupac + duljinaKučiceUKockici*2, petiRed + 5);
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

void CČovječeNeLjutiSeView::iscrtajKučicu(CDC * pDC, double dx, double dy, RECT r)
{	
	int i = 1;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		pDC->Ellipse(dx+duljinaKučice, dy, dx +duljinaKučice*2, dy + visinaKučice);
		dy = dy + visinaKučice;
		++i;
	}
}

void CČovječeNeLjutiSeView::iscrtajCijeliRedHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	while (dx +duljinaKučice< r.right) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dx += duljinaKučice;
	}
}

void CČovječeNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	while (dy < r.bottom) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dy += visinaKučice;
	}
}

void CČovječeNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dx += duljinaKučice;
		++i;
	}

}

void CČovječeNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dy += visinaKučice;
		++i;
	}
}

void CČovječeNeLjutiSeView::iscrtajKockuSest(CDC * pDC, double dx, double dy)
{
	int i = 0;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx = dx + duljinaKučiceUKockici + duljinaKučiceUKockici;
		pDC->Ellipse(dx, dy, dx + duljinaKučiceUKockici, dy + visinaKučiceUKockici);
		dx=dx- duljinaKučiceUKockici - duljinaKučiceUKockici;
		dy = dy + visinaKučiceUKockici + visinaKučiceUKockici-5;
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
		dy = dy + visinaKučiceUKockici *4 - 10;
		++i;
	}
	dx = dx + duljinaKučiceUKockici;
	dy = dy - visinaKučiceUKockici*4-1;
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

	pDC->Ellipse(početakTijelaDx, početakTijelaDy, krajTijelaDx, krajTijelaDy);
	CBrush brush1;   
	brush1.CreateSolidBrush(RGB(204, 0, 204));
	pDC->SelectObject(&brush1);
	pDC->Ellipse(početakGlaveDx, početakGlaveDy, krajGlaveDx, krajGlaveDy);
}

void CČovječeNeLjutiSeView::OnDraw(CDC* pDC)
{
	CČovječeNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	RECT r;
	GetClientRect(&r);
	int brojRedova = 11;
	duljinaKučice = r.right / brojRedova;
	visinaKučice = r.bottom / brojRedova;
	duljinaKučiceUKockici = duljinaKučice / 5;
	visinaKučiceUKockici = visinaKučice / 5;
	iscrtajPolje(pDC, 0, 0, r);
	
	// TODO: add draw code for native data here
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
	srand(time(NULL));
	i= rand() % 6 + 1;
	InvalidateRect(CRect(duljinaKučice*5,visinaKučice*5,duljinaKučice*6,visinaKučice*6));
	
}

void CČovječeNeLjutiSeView::OnFileNew()
{
	timer= timer = SetTimer(1, 500, 0);
}


CČovječeNeLjutiSeDoc* CČovječeNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CČovječeNeLjutiSeDoc)));
	return (CČovječeNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG


// CČovječeNeLjutiSeView message handlers
