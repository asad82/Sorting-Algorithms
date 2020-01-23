// SortComparison.h : main header file for the SORTCOMPARISON application
//

#if !defined(AFX_SORTCOMPARISON_H__E564E9BA_7729_4F25_99AD_3FA883657E1D__INCLUDED_)
#define AFX_SORTCOMPARISON_H__E564E9BA_7729_4F25_99AD_3FA883657E1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonApp:
// See SortComparison.cpp for the implementation of this class
//

class CSortComparisonApp : public CWinApp
{
public:
	CSortComparisonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortComparisonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSortComparisonApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTCOMPARISON_H__E564E9BA_7729_4F25_99AD_3FA883657E1D__INCLUDED_)
