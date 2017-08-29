
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

void C�ovje�eNeLjutiSeView::iscrtajPolje(CDC* pDC, double dx, double dy, RECT r)
{
	
	CPen * oldPen;
	CBrush * oldBrush;
	CPen crvenaOlovka(PS_SOLID, 7, RGB(255, 0, 0));
	CPen plavaOlovka(PS_SOLID, 7, RGB(0, 0, 255));
	CPen zelenaOlovka(PS_SOLID, 7, RGB(0, 255, 0));
	CPen zutaOlovka(PS_SOLID, 7, RGB(255, 255, 0));
	CPen crnaOlovka(PS_SOLID, 5, RGB(0, 0, 0));
	//stupci
	double cetvrtiStupac = duljinaKu�ice * 4;
	double petiStupac = duljinaKu�ice * 5;
	double sestiStupac = duljinaKu�ice * 6;
	double sedmiStupac = duljinaKu�ice * 7;
	double devetiStupac = duljinaKu�ice * 9;
	double desetiStupac = duljinaKu�ice * 10;
	//redci
	double cetvrtiRed = visinaKu�ice * 4;
	double petiRed = visinaKu�ice * 5;
	double sestiRed = visinaKu�ice * 6;
	double sedmiRed = visinaKu�ice * 7;
	double devetiRed = visinaKu�ice * 9;
	double desetiRed = visinaKu�ice * 10;

	
	
	oldPen = pDC->SelectObject(&crvenaOlovka);
	iscrtajKu�icu(pDC, 0, 0, r);
	pDC->SelectObject(oldPen);	

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKu�icu(pDC, devetiStupac, 0, r);
	pDC->SelectObject(oldPen);
	

	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKu�icu(pDC, 0, devetiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKu�icu(pDC, devetiStupac, devetiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	iscrtajCijeliRedHorizontalno(pDC,0,cetvrtiRed,r);
	iscrtajCijeliRedHorizontalno(pDC, 0, sestiRed, r);
	iscrtajCijeliRedVertikalno(pDC, cetvrtiStupac, 0, r);
	iscrtajCijeliRedVertikalno(pDC, sestiStupac, 0, r);
	pDC->Ellipse(0, sestiRed,duljinaKu�ice,sestiRed);
	pDC->Ellipse(petiStupac, desetiRed,  sestiStupac, r.bottom);
	pDC->Ellipse(desetiStupac, petiRed, r.right, sestiRed);
	pDC->Ellipse(petiStupac, 0, sestiStupac, visinaKu�ice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, cetvrtiRed, duljinaKu�ice, petiRed);
	iscrtajCiljHorizontalno(pDC, duljinaKu�ice, petiRed, r);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(desetiStupac, sestiRed, r.right, sedmiRed);
	iscrtajCiljHorizontalno(pDC, sestiStupac, petiRed, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(sestiStupac, 0, sedmiStupac, visinaKu�ice);
	iscrtajCiljVertikalno(pDC, petiStupac, visinaKu�ice, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(cetvrtiStupac, desetiRed, petiStupac, r.bottom);
	iscrtajCiljVertikalno(pDC, petiStupac, sestiRed, r);
	pDC->SelectObject(oldPen);

}

void C�ovje�eNeLjutiSeView::iscrtajKu�icu(CDC * pDC, double dx, double dy, RECT r)
{	
	int i = 1;
	while (i < 3) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		pDC->Ellipse(dx+duljinaKu�ice, dy, dx +duljinaKu�ice*2, dy + visinaKu�ice);
		dy = dy + visinaKu�ice;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajCijeliRedHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	while (dx +duljinaKu�ice< r.right) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dx += duljinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	while (dy < r.bottom) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dy += visinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dx += duljinaKu�ice;
		++i;
	}

}

void C�ovje�eNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dy += visinaKu�ice;
		++i;
	}
}

void C�ovje�eNeLjutiSeView::OnDraw(CDC* pDC)
{
	C�ovje�eNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	RECT r;
	GetClientRect(&r);
	int brojRedova = 11;
	duljinaKu�ice = r.right / brojRedova;
	visinaKu�ice = r.bottom / brojRedova;
	iscrtajPolje(pDC, 0, 0, r);
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

C�ovje�eNeLjutiSeDoc* C�ovje�eNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ovje�eNeLjutiSeDoc)));
	return (C�ovje�eNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ovje�eNeLjutiSeView message handlers
