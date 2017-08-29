
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
END_MESSAGE_MAP()

// CÈovjeèeNeLjutiSeView construction/destruction

CÈovjeèeNeLjutiSeView::CÈovjeèeNeLjutiSeView()
{
	// TODO: add construction code here

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
	double duljinaKuèice = r.right / 11;
	double visinaKuèice = r.bottom / 11;
	CPen * oldPen;
	CBrush * oldBrush;
	CPen crvenaOlovka(PS_SOLID, 7, RGB(255, 0, 0));
	CPen plavaOlovka(PS_SOLID, 7, RGB(0, 0, 255));
	CPen zelenaOlovka(PS_SOLID, 7, RGB(0, 255, 0));
	CPen zutaOlovka(PS_SOLID, 7, RGB(255, 255, 0));
	CPen crnaOlovka(PS_SOLID, 5, RGB(0, 0, 0));
	
	
	oldPen = pDC->SelectObject(&crvenaOlovka);
	iscrtajKuèicu(pDC, 0, 0, r);
	pDC->SelectObject(oldPen);	

	oldPen = pDC->SelectObject(&plavaOlovka);
	iscrtajKuèicu(pDC, duljinaKuèice*9, 0, r);
	pDC->SelectObject(oldPen);
	

	oldPen = pDC->SelectObject(&zutaOlovka);
	iscrtajKuèicu(pDC, 0, visinaKuèice*9, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zelenaOlovka);
	iscrtajKuèicu(pDC, duljinaKuèice*9, visinaKuèice*9, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crnaOlovka);
	iscrtajCijeliRedHorizontalno(pDC,0,4*visinaKuèice,r);
	iscrtajCijeliRedHorizontalno(pDC, 0, 6 * visinaKuèice, r);
	iscrtajCijeliRedVertikalno(pDC, 4 * duljinaKuèice, 0, r);
	iscrtajCijeliRedVertikalno(pDC, 6 * duljinaKuèice, 0, r);
	pDC->Ellipse(0, visinaKuèice*5,duljinaKuèice,visinaKuèice*6);
	pDC->Ellipse(duljinaKuèice * 5, visinaKuèice * 10,  duljinaKuèice * 6, r.bottom);
	pDC->Ellipse(duljinaKuèice*10, visinaKuèice * 5, r.right, visinaKuèice*6);
	pDC->Ellipse(duljinaKuèice * 5, 0, duljinaKuèice * 6, visinaKuèice);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&crvenaOlovka);
	pDC->Ellipse(0, visinaKuèice * 4, duljinaKuèice, visinaKuèice * 5);
	iscrtajCiljHorizontalno(pDC, duljinaKuèice, visinaKuèice * 5, r);
	pDC->SelectObject(oldPen);


	oldPen = pDC->SelectObject(&zelenaOlovka);
	pDC->Ellipse(duljinaKuèice * 10, visinaKuèice * 6, r.right, visinaKuèice * 7);
	iscrtajCiljHorizontalno(pDC, duljinaKuèice*6, visinaKuèice * 5, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&plavaOlovka);
	pDC->Ellipse(duljinaKuèice * 6, 0, duljinaKuèice * 7, visinaKuèice);
	iscrtajCiljVertikalno(pDC, duljinaKuèice * 5, visinaKuèice, r);
	pDC->SelectObject(oldPen);

	oldPen = pDC->SelectObject(&zutaOlovka);
	pDC->Ellipse(duljinaKuèice * 4, visinaKuèice * 10, duljinaKuèice * 5, r.bottom);
	iscrtajCiljVertikalno(pDC, duljinaKuèice * 5, visinaKuèice*6, r);
	pDC->SelectObject(oldPen);

}

void CÈovjeèeNeLjutiSeView::iscrtajKuèicu(CDC * pDC, double dx, double dy, RECT r)
{	
	double duljinaKuèice = r.right / 11;
	double visinaKuèice = r.bottom / 11;
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
	double duljinaKuèice = r.right / 11;
	double visinaKuèice = r.bottom / 11;
	while (dx +duljinaKuèice< r.right) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dx += duljinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajCijeliRedVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKuèice = r.right / 11;
	double visinaKuèice = r.bottom / 11;
	while (dy < r.bottom) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dy += visinaKuèice;
	}
}

void CÈovjeèeNeLjutiSeView::iscrtajCiljHorizontalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKuèice = r.right / 11;
	double visinaKuèice = r.bottom / 11;
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dx += duljinaKuèice;
		++i;
	}

}

void CÈovjeèeNeLjutiSeView::iscrtajCiljVertikalno(CDC * pDC, double dx, double dy, RECT r)
{
	double duljinaKuèice = r.right / 11;
	double visinaKuèice = r.bottom / 11;
	int i = 0;
	while (i<4) {
		pDC->Ellipse(dx, dy, dx + duljinaKuèice, dy + visinaKuèice);
		dy += visinaKuèice;
		++i;
	}
}

void CÈovjeèeNeLjutiSeView::OnDraw(CDC* pDC)
{
	CÈovjeèeNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	RECT r;
	GetClientRect(&r);
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

CÈovjeèeNeLjutiSeDoc* CÈovjeèeNeLjutiSeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CÈovjeèeNeLjutiSeDoc)));
	return (CÈovjeèeNeLjutiSeDoc*)m_pDocument;
}
#endif //_DEBUG


// CÈovjeèeNeLjutiSeView message handlers
