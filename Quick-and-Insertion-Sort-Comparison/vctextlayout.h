#if !defined(AFX_VCTEXTLAYOUT_H__52D97EE7_57C4_4C3F_B718_1A62162B8EE6__INCLUDED_)
#define AFX_VCTEXTLAYOUT_H__52D97EE7_57C4_4C3F_B718_1A62162B8EE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CVcTextLayout wrapper class

class CVcTextLayout : public COleDispatchDriver
{
public:
	CVcTextLayout() {}		// Calls COleDispatchDriver default constructor
	CVcTextLayout(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcTextLayout(const CVcTextLayout& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetHorzAlignment();
	void SetHorzAlignment(long nNewValue);
	long GetVertAlignment();
	void SetVertAlignment(long nNewValue);
	long GetOrientation();
	void SetOrientation(long nNewValue);
	BOOL GetWordWrap();
	void SetWordWrap(BOOL bNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCTEXTLAYOUT_H__52D97EE7_57C4_4C3F_B718_1A62162B8EE6__INCLUDED_)
