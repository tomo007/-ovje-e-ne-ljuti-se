
// ČovječeNeLjutiSeView.h : interface of the CČovječeNeLjutiSeView class
//

#pragma once
#include <vector>
#include "Igra.h"


class CČovječeNeLjutiSeView : public CView
{
protected: // create from serialization only
	CČovječeNeLjutiSeView();
	DECLARE_DYNCREATE(CČovječeNeLjutiSeView)

// Attributes
public:
	CČovječeNeLjutiSeDoc* GetDocument() const;

//članovi igre
private: Igra* igra;
		 Igrač trenutniIgrač;
		 Figura figura;
private: void igraj();
//crtanje polja
private: double duljinaKučice;
		 double visinaKučice;
		 double duljinaKučiceUKockici;
		 double visinaKučiceUKockici;
		 UINT_PTR timer;
		 int brojSKocke = 0;
		 bool kockaSeOkreće = false;
		 std::vector<std::vector<RECT>> kučice;
		 std::vector<std::vector<RECT>> ciljevi;
		 std::vector<RECT>  ploča;
//olovke i ispune
private: double cetvrtiStupac;
		 double petiStupac;
		 double sestiStupac;
		 double sedmiStupac;
		 double devetiStupac;
		 double desetiStupac;
		 //redci
		 double cetvrtiRed;
		 double petiRed;
		 double sestiRed;
		 double sedmiRed;
		 double devetiRed;
		 double desetiRed;
//crtanje polja
private: void iscrtajPolje(CDC* pDC,double dx, double dy, RECT r);
		 void iscrtajKučicu(CDC* pDC, double dx, double dy, RECT r);
		 void iscrtajCijeliRedHorizontalno(CDC* pDC, double dx, double dy, RECT r);
		 void iscrtajCijeliRedVertikalno(CDC* pDC, double dx, double dy, RECT r);
		 void iscrtajCiljHorizontalno(CDC* pDC, double dx, double dy, RECT r);
		 void iscrtajCiljVertikalno(CDC* pDC, double dx, double dy, RECT r);
//crtanje kocke
private: void iscrtajKockuSest(CDC* pDC, double dx, double dy);
		 void iscrtajKockuPet(CDC* pDC, double dx, double dy);
		 void iscrtajKockuCetri(CDC* pDC, double dx, double dy);
		 void iscrtajKockuTri(CDC* pDC, double dx, double dy);
		 void iscrtajKockuDva(CDC* pDC, double dx, double dy);
		 void iscrtajKockuJedan(CDC* pDC, double dx, double dy);
//crtanje pijuna
private: void iscrtajFiguru(CDC* pDC, double dx, double dy);
//popunjavanje polja
private: void prodiPoljaHorizontalno(double dx, double dy, int brojPoljaZaPoci);
		 void prodiPoljaVertikalno(double dx, double dy, int brojPoljaZaPoci);
		 void prodiKucicu(double dx, double dy);
		 void prodiPoljaVertikalnoPremaGore(double dx, double dy, int brojPoljaZaPoci);
		 void prodiPoljaHorizontalnoSDesnaNaLijevo(double dx, double dy, int brojPoljaZaPoci);
//inicijalizacija varijabli
private: void inicijalizirajVarijableCrtanja();
		 void inicijalizirajVektorPolja();
		 void inicijalizirajKučicu(Boja b);
		 void osvjeziPolje(RECT r);
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CČovječeNeLjutiSeView();

	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;


protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnFileNew();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileNewDvaIgrača();
};

#ifndef _DEBUG  // debug version in ČovječeNeLjutiSeView.cpp
inline CČovječeNeLjutiSeDoc* CČovječeNeLjutiSeView::GetDocument() const
   { return reinterpret_cast<CČovječeNeLjutiSeDoc*>(m_pDocument); }
#endif

