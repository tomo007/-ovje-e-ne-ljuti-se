
// ÈovjeèeNeLjutiSeView.h : interface of the CÈovjeèeNeLjutiSeView class
//

#pragma once


class CÈovjeèeNeLjutiSeView : public CView
{
protected: // create from serialization only
	CÈovjeèeNeLjutiSeView();
	DECLARE_DYNCREATE(CÈovjeèeNeLjutiSeView)

// Attributes
public:
	CÈovjeèeNeLjutiSeDoc* GetDocument() const;

// Operations
//crtanje polja
private: double duljinaKuèice;
private: double visinaKuèice;
private: double duljinaKuèiceUKockici;
private: double visinaKuèiceUKockici;
private: UINT_PTR timer;
private: int i = 0;
private: void iscrtajPolje(CDC* pDC,double dx, double dy, RECT r);
private: void iscrtajKuèicu(CDC* pDC, double dx, double dy, RECT r);
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
	virtual ~CÈovjeèeNeLjutiSeView();

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

#ifndef _DEBUG  // debug version in ÈovjeèeNeLjutiSeView.cpp
inline CÈovjeèeNeLjutiSeDoc* CÈovjeèeNeLjutiSeView::GetDocument() const
   { return reinterpret_cast<CÈovjeèeNeLjutiSeDoc*>(m_pDocument); }
#endif

