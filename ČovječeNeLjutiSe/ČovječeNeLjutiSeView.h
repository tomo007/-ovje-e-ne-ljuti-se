
// �ovje�eNeLjutiSeView.h : interface of the C�ovje�eNeLjutiSeView class
//

#pragma once


class C�ovje�eNeLjutiSeView : public CView
{
protected: // create from serialization only
	C�ovje�eNeLjutiSeView();
	DECLARE_DYNCREATE(C�ovje�eNeLjutiSeView)

// Attributes
public:
	C�ovje�eNeLjutiSeDoc* GetDocument() const;

// Operations
public:
private: void iscrtajPolje(CDC* pDC,double dx, double dy, RECT r);
private: void iscrtajKu�icu(CDC* pDC, double dx, double dy, RECT r);
private: void iscrtajCijeliRedHorizontalno(CDC* pDC, double dx, double dy, RECT r);
private: void iscrtajCijeliRedVertikalno(CDC* pDC, double dx, double dy, RECT r);
private: void iscrtajCiljHorizontalno(CDC* pDC, double dx, double dy, RECT r);
private: void iscrtajCiljVertikalno(CDC* pDC, double dx, double dy, RECT r);

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~C�ovje�eNeLjutiSeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in �ovje�eNeLjutiSeView.cpp
inline C�ovje�eNeLjutiSeDoc* C�ovje�eNeLjutiSeView::GetDocument() const
   { return reinterpret_cast<C�ovje�eNeLjutiSeDoc*>(m_pDocument); }
#endif

