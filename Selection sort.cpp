/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website				 : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void main()
{
	const int size = 10;
	int array[size];
	int marker = size;
	int temp = 0, max = 0, m = 0;
	int preserve = 0, count = 0;

	for (int i = 0; i < size; i++)
	{
		cout << "\n Enter Value " << i << "=";
		cin >> array[i];
	}

	while (marker > 0)
	{
		max = array[0];
		for (int j = 0; j < marker; j++)
			if (max <= array[j])
			{
				max = array[j];
				preserve = j; count++;
			}

		if (count > 0)
		{
			count = 0;
			temp = array[marker - 1];
			array[marker - 1] = max;
			array[preserve] = temp;
		}

		marker--;

	}

	for (int k = 0; k < size; k++)
	{
		cout << "\n The Sorted Array Is" << k << "=" << array[k];
	}

	getch();
}