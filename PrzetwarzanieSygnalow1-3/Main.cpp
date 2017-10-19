#include "stdafx.h"
#include <stdio.h>
#include<cmath>
#include<vector>

//zmienne globalne, dzialaja w calym kodziku
double end, begin,jump;
int tab[3];
int n;
double *results;


//liczy wartosc funkcji
double function( double x)
{
	double y;

	y = ((tab[0]*x*x) - (tab[1]*x) - tab[2]) / (pow(x, 3) - (tab[3]*x));
	
	return y;
}
//sprawdza czy mianownik = 0
bool denomcheck(double x)
{
	if (((pow(x, 3) - (tab[3]*x)) == 0))
	{
		return false;
	}
	else
		return true;
}
//pobiera dane dot przedzialu dla funkcji i przeskok
void getdata()
{
	printf("Podaj lewy koniec przedzialu: ");
	scanf("%lf", &begin);
	printf("Podaj prawy koniec przedzialu: ");
	scanf("%lf", &end);
	printf("Podaj przeskok funkcji: ");
	scanf("%lf", &jump);
}
// pobiera wspolczynniki
void getfactor()
{
	printf("Podaj wspolczynnik a : ");
	scanf("%d", &tab[0]);
	printf("Podaj wspolczynnik b: ");
	scanf("%d", &tab[1]);
	printf("Podaj wspolczynnik c: ");
	scanf("%d", &tab[2]);
	printf("Podaj wspolczynnik d: ");
	scanf("%d", &tab[3]);
}
//wpisanie wynikow do dynamicznej tablicy
double *toarray(double x,int n)
{
	double * results = new double[n];
	for (int j = 0; j < n; j++)
	{
		results[j] = function( x);
		x += jump;
	}
	return results;
}

void showarr(double arr[],int n,double x)
{
	for(int i=0;i<n;i++)
	{
		printf("Wynik dla x=" "%.2lf", x);
		if (denomcheck(x) == true && function(x)<INT_MAX)
		{
			printf(" | y=%.2lf \n", arr[i]);
		}
		else
			printf(" | MIANOWNIK = 0!!! \n");
		x += jump;
	} 
	delete[] arr;
}

int main()
{
	double x;
	//wywolanie funkcji
	getfactor();
	getdata();
	
	x = begin;

	n = (end - begin) / jump;

	toarray(x,n);

	showarr(toarray(x, n), n, x);
	
    return 0;
}