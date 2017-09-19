
// CovjeceNeLjutiSe.h : main header file for the CovjeceNeLjutiSe application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCovjeceNeLjutiSeApp:
// See CovjeceNeLjutiSe.cpp for the implementation of this class
//

class CCovjeceNeLjutiSeApp : public CWinApp
{
public:
	CCovjeceNeLjutiSeApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCovjeceNeLjutiSeApp theApp;
