
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

void C�ovje�eNeLjutiSeView::OnDraw(CDC* /*pDC*/)
{
	C�ovje�eNeLjutiSeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

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
