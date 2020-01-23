// SortComparisonDoc.cpp : implementation of the CSortComparisonDoc class
//

#include "stdafx.h"
#include "SortComparison.h"

#include "SortComparisonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonDoc

IMPLEMENT_DYNCREATE(CSortComparisonDoc, CDocument)

BEGIN_MESSAGE_MAP(CSortComparisonDoc, CDocument)
	//{{AFX_MSG_MAP(CSortComparisonDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonDoc construction/destruction

CSortComparisonDoc::CSortComparisonDoc()
{
	// TODO: add one-time construction code here

}

CSortComparisonDoc::~CSortComparisonDoc()
{
}

BOOL CSortComparisonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSortComparisonDoc serialization

void CSortComparisonDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonDoc diagnostics

#ifdef _DEBUG
void CSortComparisonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSortComparisonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonDoc commands
