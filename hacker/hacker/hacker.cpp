// hacker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
using namespace std;


int gorb(int hh, int mm, int ss, int arr[50], int no)
{
	int x=0, y=0;

	for (int i = 0; i < no; i++)
	{

		if ((hh % arr[i]) == 0 && (mm % arr[i]) == 0 && (ss % arr[i]) == 0) //bad
		{
			x = 1;

		}

		if ((hh % arr[i] != 0 || hh==0) && (mm % arr[i] != 0 || mm==0) && (ss % arr[i] != 0 || ss==0))   //good
		{
			y = 1;
		}

		if (x && y)
		{
			return 2;
		}


	}
	
	if (x == 0 && y == 0)
	{
		return 3;
	}
	if (y == 1)
		return 1;
	if (x==1)
		return 0;


}


int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;

	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}

	return a;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int prime[50], t;

	int n, x = 0;

	for (int i = 2; i <= 59; i++)
	{
		int j;
		for (j = 2; j <= i - 1; j++)
		{
			if (i%j == 0)
				break;
		}
		if (i == j)
		{
			prime[x] = i;
			x++;
		}
	}

	int arr[25][60][60][2] = {};

	arr[24][0][0][0] = 0;
	arr[24][0][0][1] = 0;
		
	int nhh, nmm, nss;
	
	for (int hh = 23; hh >= 0; hh--)
	{
		nhh = hh;
		for (int mm = 59; mm >= 0; mm--)
		{
			nmm = mm;
			for (int ss = 59; ss >= 0; ss--)
			{
				nss = ss;
				nmm = mm;
				nhh = hh;

				nss++;
				if (nss == 60)
				{
					nss = 0;
					nmm++;

					if (nmm == 60)
					{
						nmm = 0;
						nhh++;
					}

				}


				int temp = gorb(hh, mm, ss, prime, x);

				if (temp==0)
				{
					
					arr[hh][mm][ss][0] = 1;
					arr[hh][mm][ss][1] =0;
				}
				else if (temp == 1)
				{
					arr[hh][mm][ss][0] = 0;
					arr[hh][mm][ss][1] = 1;
				}
				else if (temp==2)
				{
					arr[hh][mm][ss][0] = 1;
					arr[hh][mm][ss][1] = 1;

				}

				else
				{
					if (hh == 23)
					{
						cout << " Nothing " << hh << ":" << mm << ":" << ss;
						cout << "\n";
					}

				}
				arr[hh][mm][ss][0] += arr[nhh][nmm][nss][0];
				arr[hh][mm][ss][1] += arr[nhh][nmm][nss][1];

				


			}



		}



	}

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> nhh >> nmm >> nss;

		int a = arr[nhh][nmm][nss][0];
		int b = arr[nhh][nmm][nss][1];

		int g = gcd(a, b);

		if (g != 0)
		{

			cout << a  << ":" << b ;
		}
		else
		{
			cout << a << ":" << b;
		}

		cout << "\n";


	}

	return 0;
}






