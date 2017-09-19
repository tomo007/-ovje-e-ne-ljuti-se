
// CovjeceNeLjutiSeView.h : interface of the CCovjeceNeLjutiSeView class
//

#pragma once
#include <vector>
#include "Igra.h"


class CCovjeCeNeLjutiSeView : public CView
{
protected: // create from serialization only
	CCovjeCeNeLjutiSeView();
	DECLARE_DYNCREATE(CCovjeCeNeLjutiSeView)

// Attributes
public:
	CCovjeceNeLjutiSeDoc* GetDocument() const;

//clanovi igre
private: Igra* igra;
		 Igrac trenutniIgrac;
		 Figura* figura;
		 bool figuraJeOdabrana = false;
		 int brojSKocke = 0;
		 int brojBacanjaKocke;
		 bool kockaSeOkrece = false;
		 bool bacajKocku;
private: void igraj();
//crtanje polja
private: double duljinaKucice;
		 double visinaKucice;
		 double duljinaKuciceUKockici;
		 double visinaKuciceUKockici;
		 UINT_PTR timer;
		 std::vector<std::vector<RECT>> kucice;
		 std::vector<std::vector<RECT>> poljaKucice;
		 std::vector<std::vector<RECT>> figureNaPolju;
		 std::vector<std::vector<RECT>> poljaCiljeva;
		 std::vector<std::vector<RECT>> ciljevi;
		 std::vector<RECT>  ploca;
//olovke i ispune
private: int brojRedova = 11;
		 double cetvrtiStupac;
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
private: void iscrtajPolje(CDC* pDC,double dx, double dy);
		 void iscrtajKucicu(CDC* pDC, double dx, double dy);
		 void iscrtajCijeliRedHorizontalno(CDC* pDC, double dx, double dy);
		 void iscrtajCijeliRedVertikalno(CDC* pDC, double dx, double dy);
		 void iscrtajCiljHorizontalno(CDC* pDC, double dx, double dy);
		 void iscrtajCiljVertikalno(CDC* pDC, double dx, double dy);
		 void protresiDostupneFigure();
		 void protresiKocku();
		 void protresiKucicuIgraca();
//crtanje kocke
private: void iscrtajKockuSest(CDC* pDC, double dx, double dy);
		 void iscrtajKockuPet(CDC* pDC, double dx, double dy);
		 void iscrtajKockuCetri(CDC* pDC, double dx, double dy);
		 void iscrtajKockuTri(CDC* pDC, double dx, double dy);
		 void iscrtajKockuDva(CDC* pDC, double dx, double dy);
		 void iscrtajKockuJedan(CDC* pDC, double dx, double dy);
//crtanje pijuna
private: void iscrtajFiguru(CDC* pDC, double dx, double dy);
		 CBrush* vratiBrush(Igrac trenutniIgrac);
//popunjavanje polja
private: void prodiPoljaHorizontalno(double dx, double dy, int brojPoljaZaPoci);
		 void prodiPoljaVertikalno(double dx, double dy, int brojPoljaZaPoci);
		 void prodiKucicu(double dx, double dy,int index);
		 void prodiCiljVertikalno(int index);
		 void prodiCiljHorizontalno(int index);
		 void prodiCiljVertikalnoOdGorePremaDolje(int index);
		 void prodiCiljHorizontalnoSDesnaNaLijevo(int index);
		 void prodiPoljaVertikalnoPremaGore(double dx, double dy, int brojPoljaZaPoci);
		 void prodiPoljaHorizontalnoSDesnaNaLijevo(double dx, double dy, int brojPoljaZaPoci);
//inicijalizacija varijabli
private: void inicijalizirajVarijableCrtanja();
		 void inicijalizirajVektorPolja();
		 void inicijalizirajKucicu(Boja b);
		 void inicijalizirajCiljeve(Boja b);
		 void isprazniKontenjereProsleIgre();
		 void osvjeziPolje(RECT r,int izbrisi);
//azuriranje polja
		 void postaviFiguruNaPocetnoPolje();
		 void pomakniFiguru();
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CCovjeCeNeLjutiSeView();

	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;


protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileNewDvaIgraca();
	afx_msg void OnFileNewTriIgraca();
	afx_msg void OnFileNewCetriIgraca();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in CovjeceNeLjutiSeView.cpp
inline CCovjeceNeLjutiSeDoc* CCovjeCeNeLjutiSeView::GetDocument() const
   { return reinterpret_cast<CCovjeceNeLjutiSeDoc*>(m_pDocument); }
#endif

