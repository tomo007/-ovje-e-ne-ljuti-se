
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
END_MESSAGE_MAP()

// CČovječeNeLjutiSeView construction/destruction

CČovječeNeLjutiSeView::CČovječeNeLjutiSeView()
{
	// TODO: add construction code here

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
	double duljinaKučice = r.right / 11;
	double visinaKučice = r.bottom / 11;
	CPen * oldPen;
	CBrush * oldBrush;
	CPen crvenaOlovka(PS_SOLID, 7, RGB(255, 0, 0));
	CPen plavaOlovka(PS_SOLID, 7, RGB(0, 0, 255));
	CPen zelenaOlovka(PS_SOLID, 7, RGB(0, 255, 0));
	CPen zutaOlovka(PS_SOLID, 7, RGB(255, 255, 0));
	CPen crnaOlovka(PS_SOLID, 5, RGB(0, 0, 0));
	
	
	oldPen = pDC->SelectObject(&crvenaOlovka);
	iscrtajKučicu(pDC, 0, 0, r);
	pDC->SelectObject(oldPen);	

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKučicu(pDC, duljinaKučice*9, 0, r);
	pDC->SelectObject(oldPen);
	

	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKučicu(pDC, 0, visinaKučice*9, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKučicu(pDC, duljinaKučice*9, visinaKučice*9, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	iscrtajCijeliRedHorizontalno(pDC,0,4*visinaKučice,r);
	iscrtajCijeliRedHorizontalno(pDC, 0, 6 * visinaKučice, r);
	iscrtajCijeliRedVertikalno(pDC, 4 * duljinaKučice, 0, r);
	iscrtajCijeliRedVertikalno(pDC, 6 * duljinaKučice, 0, r);
	pDC->Ellipse(0, visinaKučice*5,duljinaKučice,visinaKučice*6);
	pDC->Ellipse(duljinaKučice * 5, visinaKučice * 10,  duljinaKučice * 6, r.bottom);
	pDC->Ellipse(duljinaKučice*10, visinaKučice * 5, r.right, visinaKučice*6);
	pDC->Ellipse(duljinaKučice * 5, 0, duljinaKučice * 6, visinaKučice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, visinaKučice * 4, duljinaKučice, visinaKučice * 5);
	iscrtajCiljHorizontalno(pDC, duljinaKučice, visinaKučice * 5, r);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(duljinaKučice * 10, visinaKučice * 6, r.right, visinaKučice * 7);
	iscrtajCiljHorizontalno(pDC, duljinaKučice*6, visinaKučice * 5, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(duljinaKučice * 6, 0, duljinaKučice * 7, visinaKučice);
	iscrtajCiljVertikalno(pDC, duljinaKučice * 5, visinaKučice, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(duljinaKučice * 4, visinaKučice * 10, duljinaKučice * 5, r.bottom);
	iscrtajCiljVertikalno(pDC, duljinaKučice * 5, visinaKučice*6, r);
	pDC->SelectObject(oldPen);

}

void CČovječeNeLjutiSeView::iscrtajKučicu(CDC * pDC, double dx, double dy, RECT r)
{	
	double duljinaKučice = r.right / 11;
	double visinaKučice = r.bottom / 11;
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
	double duljinaKučice = r.right / 11;
	double visinaKučice = r.bottom / 11;
	while (dx +duljinaKučice< r.right) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dx += duljinaKučice;
	}
}

void CČovječeNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKučice = r.right / 11;
	double visinaKučice = r.bottom / 11;
	while (dy < r.bottom) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dy += visinaKučice;
	}
}

void CČovječeNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKučice = r.right / 11;
	double visinaKučice = r.bottom / 11;
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dx += duljinaKučice;
		++i;
	}

}

void CČovječeNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKučice = r.right / 11;
	double visinaKučice = r.bottom / 11;
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKučice, dy + visinaKučice);
		dy += visinaKučice;
		++i;
	}
}

void CČovječeNeLjutiSeView::OnDraw(CDC* pDC)
{
	CČovječeNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	RECT r;
	GetClientRect(&r);
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

CČovječeNeLjutiSeDoc* CČovječeNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CČovječeNeLjutiSeDoc)));
	return (CČovječeNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG


// CČovječeNeLjutiSeView message handlers
