// meanDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
long long int pot(int x, int y)
{
	for (int i = 1; i < y; i++)
	{
		x *= x;
	}
	return x;
}
int main()
{
	int ilosc;
	int wymiar, l, przeniesienia, pionek;
	long long int srednia=0;
	scanf_s("%d", &ilosc);
	for (int i = 0; i < ilosc; i++)
	{
		scanf_s("%d%d%d%d", &wymiar, &l, &przeniesienia, &pionek);
		if (pionek == 1)
		{
			if (przeniesienia == 0)
			{
				int element = l*l*(l - 1);
				int liczba = l - 2;
				srednia += element;
				while (liczba>1)
				{
					element -= liczba*l*2;
					srednia += element;
					liczba -= 2;
				}
				if (l % 2 == 1)
				{
					element -= l * 2;
					int posredni = (srednia + element*(l / 2));
					posredni *= 2;
					element = (posredni + element);

					element /= (l - 1)*(l - 1);
					srednia += element;
				}
				srednia *= wymiar / 2.0;
				for (int j = 2; j < wymiar; j++)
				{
					srednia *= l;
				}
				int dzielnikwym=1;
				for (int j = 0; j < wymiar; j++)
				{
					dzielnikwym *= l;
				}
				if (l % 2 == 0)
					srednia /= (long long int)(l / 2)*(dzielnikwym - 1);
				else
				{
					double dzielnik = (((l - 1) / 2)) + ((double)((l - 1) / 2 * 4 + 1) / ((l - 1)*(l - 1)));//przez to jest zle
					srednia /= dzielnik*(dzielnikwym-1);
				}
			}
			else if (przeniesienia == 1)
			{
				int element;
				if (l % 2 == 1)
				{
					element = (l / 2 + 1)*(l - 1) / 2;
				}
				else
				{
					element = ((l/2)*(l - 2) / 2 + (l / 2));
				}
				element = (element + element + (l - 1)*l) / 2 * l;
				int liczba = l - 2;
				srednia += element;
				while (liczba > 0)
				{
					element -= liczba*l;
					if (liczba == 1)
						element /= 2;
					srednia += element;
					liczba -= 2;
				}
				srednia *= wymiar / 2.0;
				srednia /= (l * l-1) * (l / 2.0);
			}
			else
			{
				srednia = l / 2;
				srednia *= wymiar / 2.0;
			}
			
		}
		if (pionek == 0)
		{
			if (przeniesienia == 2)
			{
				int ilpol = pot(l,wymiar)-1;
				int kopiailpol = ilpol;
				int licznik = pot(3,wymiar)-1;
				int licznikkopia = licznik;
				int liczba = 1;
				while (ilpol > 0)
				{	
					if (ilpol<licznik)
						srednia += liczba*ilpol;
					else
					{
						srednia += liczba*licznik;
					}
					ilpol -= licznik;
					licznik += licznikkopia;
					liczba++;
				}
				srednia /= kopiailpol;
			}
			else if (przeniesienia == 0)
			{
				int element = (l*l-l)/2;
				if (l % 2 == 0)
				{
					int pierwocina = element;
					element *= l / 2;
					for (int j = 1; j < l; j++)
					{
						pierwocina += j;
						element += pierwocina*(l - j);
					}
					srednia += element / (l / 2);

					int licznik = l - 2;
					while (licznik>0)
					{
						pierwocina = l/2 * licznik;
						for (int j = l - 1; j > licznik/2 + l/2 - 1; j --)
						{
							pierwocina += j*licznik;
						}
						for (int j = 1; j < licznik; j++)
						{
							pierwocina += (licznik - j)*(licznik/2 + l/2 - j);//check it, blad dla 40
						}
						element -= pierwocina;
						srednia += element / (l / 2);
						licznik -= 2;
					}
					srednia /= (l*l - 1)*l / 2;
				}
				else
				{
					int pierwocina = element;
					element *= l;
					for (int j = 2; j < l*2; j+=2)
					{
						pierwocina += j/2;
						element += pierwocina*(l*2 - j);
					}
					srednia += element / l;

					int licznik = l - 2;
					while (licznik>0)
					{
						pierwocina = l * licznik;
						for (int j = l-2; j >= licznik; j -= 2)
						{
							pierwocina += (l + j) * licznik;
						}
						for (int j = 1; j < licznik; j++)
						{
							pierwocina += (licznik - j)*(l+licznik-j*2);
						}
						element -= pierwocina;
						if (licznik == 1)//problem z wielkoscia ostatniego rzedu, zle odlicza ostatnii element
						{
							srednia += (element) / l / 2;
						}
						else
							srednia += element / l;
						licznik -= 2;
					}
					srednia /= (l*l - 1)*l / 2.0;
				}
			}
			else
			{
				if (l % 2 == 0)
				{
					int element = ((l / 2)*(l - 2) / 2 + (l / 2));
					srednia += element*l / 2;
					for (int j = 0; j < l-1; j++)
					{
						if (j * 2 + 1 < l)
							element += j * 2 + 1;
						else
							element += l;
						srednia += element*(l - j - 1);
					}
					srednia /= (l*l-1)*l/2;
				}
				else
				{
					int element = (l / 2 + 1)*(l - 1) / 2;
					srednia += element*l;
					for (int j = 0; j < l-1; j++)
					{
						if (j * 2 + 1 < l)
							element += j * 2 + 1;
						else
							element += l;
						srednia += element*(l*2 - j*2 - 2);
					}
					srednia /= (l*l - 1)*l;
				}
			}
		}
		if (pionek == 2 && wymiar == 2)
		{
			if (przeniesienia == 0 || l % 2 == 0)
			{
				printf("Inf\n");
				continue;
			}
			if (przeniesienia == 1)
			{
				if (l == 3)
				{
					printf("1\n");
					continue;
				}
				else
				{
					printf("%d", l / 2 + 1);
					continue;
				}
			}
			else
			{
				srednia = l / 2;
			}
		}
		printf("%lld\n", srednia);
		srednia = 0;
	}
	return 0;
}