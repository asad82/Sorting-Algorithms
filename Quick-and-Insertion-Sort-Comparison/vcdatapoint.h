#if !defined(AFX_VCDATAPOINT_H__A7C61428_6D87_4635_B657_E4605DECD25F__INCLUDED_)
#define AFX_VCDATAPOINT_H__A7C61428_6D87_4635_B657_E4605DECD25F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CVcDataPointLabel;
class CVcBrush;
class CVcPen;
class CVcMarker;

/////////////////////////////////////////////////////////////////////////////
// CVcDataPoint wrapper class

class CVcDataPoint : public COleDispatchDriver
{
public:
	CVcDataPoint() {}		// Calls COleDispatchDriver default constructor
	CVcDataPoint(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcDataPoint(const CVcDataPoint& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CVcDataPointLabel GetDataPointLabel();
	CVcBrush GetBrush();
	CVcPen GetEdgePen();
	CVcMarker GetMarker();
	float GetOffset();
	void SetOffset(float newValue);
	void ResetCustom();
	void Select();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCDATAPOINT_H__A7C61428_6D87_4635_B657_E4605DECD25F__INCLUDED_)
