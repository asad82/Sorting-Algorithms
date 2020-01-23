// SortComparisonView.h : interface of the CSortComparisonView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "mschart.h"
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_SORTCOMPARISONVIEW_H__82891AAF_8D87_4677_8FE1_6684DB96D3D1__INCLUDED_)
#define AFX_SORTCOMPARISONVIEW_H__82891AAF_8D87_4677_8FE1_6684DB96D3D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Chart.h"
#include "Chart3d.h"

class CSortComparisonView : public CFormView
{
protected: // create from serialization only
	CSortComparisonView();
	DECLARE_DYNCREATE(CSortComparisonView)

public:
	//{{AFX_DATA(CSortComparisonView)
	enum { IDD = IDD_SORTCOMPARISON_FORM };
	CListBox	m_List;
	int		m_DataLength;
	int		m_MaxValue;
	int		m_MinValue;
	int		m_RadioSort;
	CMSChart	m_DisplayChart;
	CMSFlexGrid	m_FlexGrid;
	CMSChart	m_DisplayChartOrg;
	long	m_ClockSpeed;
	long	m_InstructionsPMS;
	//}}AFX_DATA

// Attributes
public:
	CSortComparisonDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortComparisonView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	void QuickSort(int lb,int ub);
	void InsertionSort();
	virtual ~CSortComparisonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSortComparisonView)
	afx_msg void OnSortButn();
	afx_msg void OnClearButn();
	afx_msg void OnCompgraphButn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void PlotComparisionGraph();
	void AddTimeToFlexGrid();
	void ProcessAlgoTime();
	int Partition(int lb,int ub);
	void LabelFlexGrid();
	int *randomData;
	int j;
	long totalTime;
	int quickSTime[10],insertionSTime[10];
	int dataLength[10];
	int quickIndex,insertionIndex;
	int cellIncrementI;
	int cellIncrementQ;
    CChart m_Chart2d;
};

#ifndef _DEBUG  // debug version in SortComparisonView.cpp
inline CSortComparisonDoc* CSortComparisonView::GetDocument()
   { return (CSortComparisonDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTCOMPARISONVIEW_H__82891AAF_8D87_4677_8FE1_6684DB96D3D1__INCLUDED_)
