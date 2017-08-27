
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
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CÈovjeèeNeLjutiSeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ÈovjeèeNeLjutiSeView.cpp
inline CÈovjeèeNeLjutiSeDoc* CÈovjeèeNeLjutiSeView::GetDocument() const
   { return reinterpret_cast<CÈovjeèeNeLjutiSeDoc*>(m_pDocument); }
#endif

