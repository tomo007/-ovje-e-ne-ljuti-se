
// �ovje�eNeLjutiSe.h : main header file for the �ovje�eNeLjutiSe application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// C�ovje�eNeLjutiSeApp:
// See �ovje�eNeLjutiSe.cpp for the implementation of this class
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
