// SortComparisonDoc.h : interface of the CSortComparisonDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SORTCOMPARISONDOC_H__87AADF31_3D87_41AB_B715_BB8C0A7849EC__INCLUDED_)
#define AFX_SORTCOMPARISONDOC_H__87AADF31_3D87_41AB_B715_BB8C0A7849EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSortComparisonDoc : public CDocument
{
protected: // create from serialization only
	CSortComparisonDoc();
	DECLARE_DYNCREATE(CSortComparisonDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortComparisonDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSortComparisonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSortComparisonDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTCOMPARISONDOC_H__87AADF31_3D87_41AB_B715_BB8C0A7849EC__INCLUDED_)
