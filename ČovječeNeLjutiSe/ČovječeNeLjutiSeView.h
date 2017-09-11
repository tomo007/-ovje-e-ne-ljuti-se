
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
		 Igrač trenutniIgrac;
		 Figura figura;
		 bool figuraJeOdabrana = false;
		 int brojSKocke = 0;
		 bool kockaSeOkreće = false;
		 bool bacajKocku;
private: void igraj();
//crtanje polja
private: double duljinaKučice;
		 double visinaKučice;
		 double duljinaKučiceUKockici;
		 double visinaKučiceUKockici;
		 UINT_PTR timer;
		 std::vector<std::vector<RECT>> kučice;
		 std::vector<std::vector<RECT>> figureNaPolju;
		 std::vector<std::vector<RECT>> ciljevi;
		 std::vector<RECT>  ploča;
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
		 void iscrtajKučicu(CDC* pDC, double dx, double dy);
		 void iscrtajCijeliRedHorizontalno(CDC* pDC, double dx, double dy);
		 void iscrtajCijeliRedVertikalno(CDC* pDC, double dx, double dy);
		 void iscrtajCiljHorizontalno(CDC* pDC, double dx, double dy);
		 void iscrtajCiljVertikalno(CDC* pDC, double dx, double dy);
		 void protresiDostupneFigure();
		 void protresiKocku();
//crtanje kocke
private: void iscrtajKockuSest(CDC* pDC, double dx, double dy);
		 void iscrtajKockuPet(CDC* pDC, double dx, double dy);
		 void iscrtajKockuCetri(CDC* pDC, double dx, double dy);
		 void iscrtajKockuTri(CDC* pDC, double dx, double dy);
		 void iscrtajKockuDva(CDC* pDC, double dx, double dy);
		 void iscrtajKockuJedan(CDC* pDC, double dx, double dy);
//crtanje pijuna
private: void iscrtajFiguru(CDC* pDC, double dx, double dy);
		 CBrush* vratiBrush(Igrač trenutniIgrač);
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
		 void osvjeziPolje(RECT r,int izbrisi);
//azuriranje polja
		 void postaviFiguruNaPocetnoPolje(CDC* pDC, Igrač trenutniIgrač);
		 void odaberiFiguru();
		 void pomakniFiguru(Figura fig);
		 void kockaSeVrti();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileNewDvaIgrača();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in ČovječeNeLjutiSeView.cpp
inline CČovječeNeLjutiSeDoc* CČovječeNeLjutiSeView::GetDocument() const
   { return reinterpret_cast<CČovječeNeLjutiSeDoc*>(m_pDocument); }
#endif

