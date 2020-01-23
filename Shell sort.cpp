/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		     : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#include <iostream.h>
#include <conio.h>

void main()
{
	clrscr();
	const int size = 20;
	int array[size];
	int s = 0, choice, i = 0, temp;
	do
	{
		clrscr();
		cout << "\n Press 1 To Insert a Number.\n Press To To Sort And Display The List.";
		cout << "\n Enter Your choice=";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\n Enter Any Number=";
			cin >> array[i];
			i++;
		}
		else if (choice == 2)
		{
			for (int R = 5; R >= 1; R--)
			{
				s = 0;
				for (int l = 0; l <= i - R; l++)
				{
					for (int k = s; k <= i; k += R)
					{
						if (k + R <= i)
						{
							if (array[k] > array[k + R])
							{
								temp = array[k];
								array[k] = array[k + R];
								array[k + R] = temp;
							}
						}
					}
					s++;
				}
			}

			for (int u = 0; u < i; u++)
			{
				cout << "\n the Sorted Array Is=" << array[u];
			}
			getch();

		}

	} while (choice != 0);
}


