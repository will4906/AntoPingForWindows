// AntoPing.h : main header file for the ANTOPING application
//

#if !defined(AFX_ANTOPING_H__2C69EEC8_BD4B_4E25_BD95_08E75755EF91__INCLUDED_)
#define AFX_ANTOPING_H__2C69EEC8_BD4B_4E25_BD95_08E75755EF91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAntoPingApp:
// See AntoPing.cpp for the implementation of this class
//

class CAntoPingApp : public CWinApp
{
public:
	CAntoPingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAntoPingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAntoPingApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANTOPING_H__2C69EEC8_BD4B_4E25_BD95_08E75755EF91__INCLUDED_)
