
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
	// TODO: add construction code here

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
	double duljinaKu�ice = r.right / 11;
	double visinaKu�ice = r.bottom / 11;
	CPen * oldPen;
	CBrush * oldBrush;
	CPen crvenaOlovka(PS_SOLID, 7, RGB(255, 0, 0));
	CPen plavaOlovka(PS_SOLID, 7, RGB(0, 0, 255));
	CPen zelenaOlovka(PS_SOLID, 7, RGB(0, 255, 0));
	CPen zutaOlovka(PS_SOLID, 7, RGB(255, 255, 0));
	CPen crnaOlovka(PS_SOLID, 5, RGB(0, 0, 0));
	
	
	oldPen = pDC->SelectObject(&crvenaOlovka);
	iscrtajKu�icu(pDC, 0, 0, r);
	pDC->SelectObject(oldPen);	

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKu�icu(pDC, duljinaKu�ice*9, 0, r);
	pDC->SelectObject(oldPen);
	

	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKu�icu(pDC, 0, visinaKu�ice*9, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKu�icu(pDC, duljinaKu�ice*9, visinaKu�ice*9, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	iscrtajCijeliRedHorizontalno(pDC,0,4*visinaKu�ice,r);
	iscrtajCijeliRedHorizontalno(pDC, 0, 6 * visinaKu�ice, r);
	iscrtajCijeliRedVertikalno(pDC, 4 * duljinaKu�ice, 0, r);
	iscrtajCijeliRedVertikalno(pDC, 6 * duljinaKu�ice, 0, r);
	pDC->Ellipse(0, visinaKu�ice*5,duljinaKu�ice,visinaKu�ice*6);
	pDC->Ellipse(duljinaKu�ice * 5, visinaKu�ice * 10,  duljinaKu�ice * 6, r.bottom);
	pDC->Ellipse(duljinaKu�ice*10, visinaKu�ice * 5, r.right, visinaKu�ice*6);
	pDC->Ellipse(duljinaKu�ice * 5, 0, duljinaKu�ice * 6, visinaKu�ice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, visinaKu�ice * 4, duljinaKu�ice, visinaKu�ice * 5);
	iscrtajCiljHorizontalno(pDC, duljinaKu�ice, visinaKu�ice * 5, r);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(duljinaKu�ice * 10, visinaKu�ice * 6, r.right, visinaKu�ice * 7);
	iscrtajCiljHorizontalno(pDC, duljinaKu�ice*6, visinaKu�ice * 5, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(duljinaKu�ice * 6, 0, duljinaKu�ice * 7, visinaKu�ice);
	iscrtajCiljVertikalno(pDC, duljinaKu�ice * 5, visinaKu�ice, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(duljinaKu�ice * 4, visinaKu�ice * 10, duljinaKu�ice * 5, r.bottom);
	iscrtajCiljVertikalno(pDC, duljinaKu�ice * 5, visinaKu�ice*6, r);
	pDC->SelectObject(oldPen);

}

void C�ovje�eNeLjutiSeView::iscrtajKu�icu(CDC * pDC, double dx, double dy, RECT r)
{	
	double duljinaKu�ice = r.right / 11;
	double visinaKu�ice = r.bottom / 11;
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
	double duljinaKu�ice = r.right / 11;
	double visinaKu�ice = r.bottom / 11;
	while (dx +duljinaKu�ice< r.right) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dx += duljinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKu�ice = r.right / 11;
	double visinaKu�ice = r.bottom / 11;
	while (dy < r.bottom) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dy += visinaKu�ice;
	}
}

void C�ovje�eNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKu�ice = r.right / 11;
	double visinaKu�ice = r.bottom / 11;
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKu�ice, dy + visinaKu�ice);
		dx += duljinaKu�ice;
		++i;
	}

}

void C�ovje�eNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKu�ice = r.right / 11;
	double visinaKu�ice = r.bottom / 11;
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
