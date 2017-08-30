
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
//crtanje polja
private: double duljinaKu�ice;
private: double visinaKu�ice;
private: double duljinaKu�iceUKockici;
private: double visinaKu�iceUKockici;
private: UINT_PTR timer;
private: int i = 0;
private: void iscrtajPolje(CDC* pDC,double dx, double dy, RECT r);
private: void iscrtajKu�icu(CDC* pDC, double dx, double dy, RECT r);
private: void iscrtajCijeliRedHorizontalno(CDC* pDC, double dx, double dy, RECT r);
private: void iscrtajCijeliRedVertikalno(CDC* pDC, double dx, double dy, RECT r);
private: void iscrtajCiljHorizontalno(CDC* pDC, double dx, double dy, RECT r);
private: void iscrtajCiljVertikalno(CDC* pDC, double dx, double dy, RECT r);
//crtanje kocke
private: void iscrtajKockuSest(CDC* pDC, double dx, double dy);
private: void iscrtajKockuPet(CDC* pDC, double dx, double dy);
private: void iscrtajKockuCetri(CDC* pDC, double dx, double dy);
private: void iscrtajKockuTri(CDC* pDC, double dx, double dy);
private: void iscrtajKockuDva(CDC* pDC, double dx, double dy);
private: void iscrtajKockuJedan(CDC* pDC, double dx, double dy);
//crtanje pijuna
private: void iscrtajFiguru(CDC* pDC, double dx, double dy);
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~C�ovje�eNeLjutiSeView();

	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;


protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnFileNew();
};

#ifndef _DEBUG  // debug version in �ovje�eNeLjutiSeView.cpp
inline C�ovje�eNeLjutiSeDoc* C�ovje�eNeLjutiSeView::GetDocument() const
   { return reinterpret_cast<C�ovje�eNeLjutiSeDoc*>(m_pDocument); }
#endif

