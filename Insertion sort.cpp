/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		     : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali
// This is a demonstration version
// for a more flexible version of this code refer to "Quick-and-Insertion-Sort-Comparison"
// file SortComparisonView.cpp has a function named insertion sort which is generic and flexible

# include <iostream.h>
# include <conio.h>

void main()
{
	const int length = 10;
	int array[length];
	int marker1 = 1;
	int marker2 = 0, number, temp;

	for (int i = 0; i < length; i++)
	{
		cout << "\n Enter Value " << i << "=";
		cin >> array[i];
	}
	while (marker1 < length)
	{
		if (array[marker1] < array[marker1 - 1])
		{
			temp = array[marker1];
			marker2 = marker1 - 1;
		}
		while (array[marker2] > temp && marker2 > 0)
		{
			number = array[marker2];
			array[marker2] = array[marker2 + 1];
			array[marker2 + 1] = number;

			marker2--;
		}
		marker1++;
	}

	for (int k = 0; k < length; k++)
	{
		cout << "\n The Sorted Array Is" << k << "=" << array[k];
	}

	getch();
}
