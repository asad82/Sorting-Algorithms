// SortComparisonView.cpp : implementation of the CSortComparisonView class
//
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website				 : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali


#include "stdafx.h"
#include "SortComparison.h"

#include "SortComparisonDoc.h"
#include "SortComparisonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonView

IMPLEMENT_DYNCREATE(CSortComparisonView, CFormView)

BEGIN_MESSAGE_MAP(CSortComparisonView, CFormView)
	//{{AFX_MSG_MAP(CSortComparisonView)
	ON_BN_CLICKED(IDC_SORT_BUTN, OnSortButn)
	ON_BN_CLICKED(IDC_CLEAR_BUTN, OnClearButn)
	ON_BN_CLICKED(IDC_COMPGRAPH_BUTN, OnCompgraphButn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonView construction/destruction

CSortComparisonView::CSortComparisonView()
	: CFormView(CSortComparisonView::IDD)
	, m_RadioSort(0)
{
	//{{AFX_DATA_INIT(CSortComparisonView)
	m_DataLength = 0;
	m_MaxValue = 0;
	m_MinValue = 0;
	m_RadioSort = 0;
	m_ClockSpeed = 0;
	m_InstructionsPMS = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	quickIndex=0;
	insertionIndex=0;
	cellIncrementI=7;
	cellIncrementQ=7;

}

CSortComparisonView::~CSortComparisonView()
{
}

void CSortComparisonView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSortComparisonView)
	DDX_Text(pDX, IDC_DATALENGTH, m_DataLength);
	DDX_Text(pDX, IDC_RANGE_MAX, m_MaxValue);
	DDX_Text(pDX, IDC_RANGE_MIN, m_MinValue);
	DDX_Radio(pDX, IDC_SORTTYPE, m_RadioSort);
	DDX_Control(pDX, IDC_MSCHART1, m_DisplayChart);
	DDX_Control(pDX, IDC_MSFLEXGRID1, m_FlexGrid);
	DDX_Control(pDX, IDC_MSCHART_ORIGINALDATA, m_DisplayChartOrg);
	DDX_Text(pDX, IDC_CLOCKSPEED, m_ClockSpeed);
	DDX_Text(pDX, IDC_INSTRUCTIONS, m_InstructionsPMS);
	//}}AFX_DATA_MAP
	DDX_Radio(pDX, IDC_SORTTYPE, m_RadioSort);
}
//	DDX_Control(pDX, IDC_LIST1, m_List);

BOOL CSortComparisonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSortComparisonView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	LabelFlexGrid();
	
	CRect Rect;

	// place where chart will be displayed
	Rect.top=310;
	Rect.left=10;
	Rect.right=405;
	Rect.bottom=550;

	// setting properties chart 
	m_Chart2d.SetChartTitle("Comparison Chart");
	m_Chart2d.SetChartLabel("N","Time");
	m_Chart2d.SetGridXYNumber(5,2);
	m_Chart2d.SetAxisStyle(1);
	m_Chart2d.SetRange(0,100000,0,30000);
	m_Chart2d.SetAxisStyle(0);
	m_Chart2d.mpSerie[0].m_plotColor = RGB(0,125,255);
	m_Chart2d.mpSerie[1].m_plotColor = RGB(255,0,0);

	m_Chart2d.m_BGColor = RGB(255,255,0);
	m_Chart2d.SetGridXYNumber(10,10);

	// Create chart .
	m_Chart2d.Create(WS_CHILD|WS_VISIBLE,Rect,this,IDC_CHART2D);



}

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonView diagnostics

#ifdef _DEBUG
void CSortComparisonView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSortComparisonView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSortComparisonDoc* CSortComparisonView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSortComparisonDoc)));
	return (CSortComparisonDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSortComparisonView message handlers

void CSortComparisonView::OnSortButn() 
{
	// TODO: Add your control notification handler code here
	SYSTEMTIME st;
	VARIANT variant_Data;

	UpdateData(TRUE);
	long instructionTemp=(m_ClockSpeed*100000)/1000;
	m_InstructionsPMS=instructionTemp;
	// allocate memory
	randomData=new int[m_DataLength];
	srand((unsigned)time(NULL));

	// generate the random data
	for(int i=0;i<m_DataLength;i++)
		randomData[i]= m_MinValue + (rand()%(m_MaxValue-m_MinValue));

	HRESULT hr;
	//create an array bound
	SAFEARRAYBOUND rgsabound[1];
	rgsabound[0].lLbound = 0;		// one column array
	rgsabound[0].cElements = m_DataLength;	//and has datalength elements.
	
	//create the array
	SAFEARRAY FAR* pMySafeArray;
	pMySafeArray = SafeArrayCreate(VT_I4, 1, rgsabound); //create the array of 4byte integers, one dimension
														 //with the bounds stored in rgsabound.
	
	//assign the reference (pointer)
	int* pData;
	hr = SafeArrayAccessData(  pMySafeArray, (void**)&pData); //Get a pointer to the data.
	
	
	//copy the data from random array to the new one.
	memcpy(pData, randomData, (4*m_DataLength));
	
	
	//To put the SafeArray in a Variant
	variant_Data.parray = pMySafeArray;
	variant_Data.vt = VT_ARRAY|VT_I4; // state it's an array and what type it holds.

	// display the graph
	m_DisplayChartOrg.SetChartData(variant_Data);
	UpdateData(FALSE);

	// capture the system time at the start of the sorting
	GetSystemTime(&st);
	long sTMillisecond=st.wMilliseconds;
	long sTSecond=st.wSecond;
	long sTMinute=st.wMinute;

	// based on user selection call respective function
	if(m_RadioSort==0)
		InsertionSort();
	else if(m_RadioSort==1)
		QuickSort(0,m_DataLength-1);


	// capture the system time at the end of the sorting
	GetSystemTime(&st);
	long eTMillisecond=st.wMilliseconds;
	long eTSecond=st.wSecond;
	long eTMinute=st.wMinute;

	// perform subtraction to compute the actual time
	eTMillisecond-=sTMillisecond;
	eTSecond-=sTSecond;
	eTMinute-=sTMinute;

	eTSecond*=1000;
	eTMinute=(eTMinute*60)*1000;

	totalTime=eTMillisecond+eTSecond+eTMinute;
	// display the sorted data to the user (graph)

	//create an array bound
	SAFEARRAYBOUND rgsabound1[1];
	rgsabound1[0].lLbound = 0;		// only one column
	rgsabound1[0].cElements = m_DataLength;	//and has datalength elements.
	
	//create the array
	SAFEARRAY FAR* pMySafeArray1;
	pMySafeArray1 = SafeArrayCreate(VT_I4, 1, rgsabound1); //create the array of 4byte integers, one dimension
														 //with the bounds stored in rgsabound.

	int* pData2;
	hr = SafeArrayAccessData(  pMySafeArray1, (void**)&pData2); //Get a pointer to the data.
	
	
	//copy the data from our old array to the new one.
	memcpy(pData2, randomData, (4*m_DataLength));

//	for( i=0;i<m_DataLength;i++)
//		pData2[i]=randomData[i];

	variant_Data.parray = pMySafeArray1;
	variant_Data.vt = VT_ARRAY|VT_I4; // tells what type of data array will hold

	m_DisplayChart.SetChartData(variant_Data);
	ProcessAlgoTime();
	AddTimeToFlexGrid();
	UpdateData(FALSE);
	// release memory
	delete [] randomData;
}// end of function


//*********************** Insertion Sort *****************************//

void CSortComparisonView::InsertionSort()
{

int marker1=1;
int marker2=0,number,temp,set=0;

	while(marker1<m_DataLength)
	{
		if(randomData[marker1]<randomData[marker1-1])
			{ 
			  temp=randomData[marker1];
			  marker2=marker1-1;
			  set=1;
			} // end of if

		while(randomData[marker2]>temp && marker2>=0 && set==1)
			{      
			   number=randomData[marker2];
			   randomData[marker2]=randomData[marker2+1];
			   randomData[marker2+1]=number;          
			   marker2--;
			}// end of inner while
		
		set=0;
		marker1++;
	} // end of outer while




}// end of function

//******************* End of Insertion Sort *************************//


void CSortComparisonView::QuickSort(int lowerb,int upperb)
{

	if(lowerb >= upperb)
		return;	// array is sorted just return back.

	j=Partition(lowerb,upperb);
	QuickSort(lowerb,j-1);
	QuickSort(j+1,upperb);

}


int CSortComparisonView::Partition(int lowerb, int upperb)
{
	int a,down,temp,up;
	
	// pick the first element as the pivot
	a=randomData[lowerb];
	
	up=upperb;
	down=lowerb;

	while(down < up)
	{
		// move forward from start
		while(randomData[down] <= a && down < upperb)
			down++;
		// move backward from end
		while(randomData[up] > a)
			up--;

		if(down < up)
		{
			temp = randomData[down];
			randomData[down]= randomData[up];
			randomData[up]=temp;
		}
	}// end of outer while

	randomData[lowerb]=randomData[up];
	randomData[up]=a;
	return up;

}// end of function


void CSortComparisonView::LabelFlexGrid()
{

	m_FlexGrid.SetTextArray(0,"S.No");
	m_FlexGrid.SetTextArray(1,"Length(N)");
	m_FlexGrid.SetTextArray(2,"InserSort ");
	m_FlexGrid.SetTextArray(3,"Tot.Instr");
	m_FlexGrid.SetTextArray(4,"Nlog(N)");
	m_FlexGrid.SetTextArray(5,"QuickSort ");
	m_FlexGrid.SetTextArray(6,"Tot.Instr ");


}

void CSortComparisonView::OnClearButn() 
{
	// TODO: Add your control notification handler code here
	

	quickIndex=0;insertionIndex=0;
	cellIncrementI=7;
	cellIncrementQ=7;
	m_Chart2d.ClearChart();
}


void CSortComparisonView::ProcessAlgoTime()
{

	if(m_RadioSort==0)
	{
		if(insertionIndex<10)
		{	
			insertionSTime[insertionIndex]=(int)totalTime;
			dataLength[insertionIndex++]=m_DataLength;
		}
	}
	else if(m_RadioSort==1)
	{
		if(quickIndex<10)
		{	
			quickSTime[quickIndex]=(int)totalTime;
			dataLength[quickIndex++]=m_DataLength;
		}
	}

}// end of function




void CSortComparisonView::AddTimeToFlexGrid()
{
CString str;
	if(m_RadioSort==0)
	{
		if((insertionIndex-1) < 10)
		{
			str.Format("%d",insertionSTime[insertionIndex-1]*m_InstructionsPMS);
			m_FlexGrid.SetTextArray(3+cellIncrementI,str);

			str.Format("%d",insertionSTime[insertionIndex-1]);
			m_FlexGrid.SetTextArray(2+cellIncrementI,str);
			str.Format("%d",(cellIncrementI/7));
			m_FlexGrid.SetTextArray(0+cellIncrementI,str);
			str.Format("%d",m_DataLength);
			m_FlexGrid.SetTextArray(1+cellIncrementI,str);
			cellIncrementI+=7;

		}
	}

	else if(m_RadioSort==1)
	{
		if((quickIndex-1) < 10)
		{

			str.Format("%d",quickSTime[quickIndex-1]*m_InstructionsPMS);
			m_FlexGrid.SetTextArray(6+cellIncrementI,str);
			
			str.Format("%2.0f",m_DataLength*log(m_DataLength));
			m_FlexGrid.SetTextArray(4+cellIncrementQ,str);

			str.Format("%d",quickSTime[quickIndex-1]);
			m_FlexGrid.SetTextArray(5+cellIncrementQ,str);
			str.Format("%d",(cellIncrementQ/7));
			m_FlexGrid.SetTextArray(0+cellIncrementQ,str);
			str.Format("%d",m_DataLength);
			m_FlexGrid.SetTextArray(1+cellIncrementQ,str);
			cellIncrementQ+=7;

		}
	}


}

void CSortComparisonView::PlotComparisionGraph()
{

	m_Chart2d.nSerieCount=2;

	if ( !m_Chart2d.AllocSerie(insertionIndex) ) 
	{
		AfxMessageBox("Error allocating chart series") ;
        return ;
	}


	for(int i=0;i<insertionIndex;i++)
	{	
		m_Chart2d.SetXYValue(dataLength[i],insertionSTime[i],i,0);
		m_Chart2d.SetXYValue(dataLength[i],quickSTime[i],i,1);
	}



	m_Chart2d.Invalidate();

}// end of function

void CSortComparisonView::OnCompgraphButn() 
{
	// TODO: Add your control notification handler code here
	PlotComparisionGraph();
}



/*
	insertionSTime[0]=50;
	insertionSTime[1]=90;
	insertionSTime[2]=160;
	insertionSTime[3]=210;
	insertionSTime[4]=300;
	insertionSTime[5]=1000;
	insertionSTime[6]=1500;
	insertionSTime[7]=3000;
	insertionIndex=9;
	dataLength[0]=10;
	dataLength[1]=100;
	dataLength[2]=1000;
	dataLength[3]=20000;
	dataLength[4]=30000;
	dataLength[5]=40000;
	dataLength[6]=50000;
	dataLength[7]=100000;
*/
