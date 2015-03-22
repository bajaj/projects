// cook51_anuwta.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	ios::sync_with_stdio(false);

	int t,n;


	cin >> t;
	
	unsigned int sumarr[100001];

	for (int i = 1; i < 100001; i++)
	{
		int l = 0;
		int h = i;

		unsigned int sum = 0;

		while (true)
		{
			if (l == h)
			{
				sum += 1;
				break;
			}

			if (h == (l + 1))
			{
				sum += 2;
				break;
			}

			if (i % 2 != 0)
				sum += 1;
			sum += ((h - l) * 2);

			h--;
			l++;

		}


		sumarr[i] = sum;

	}

	for (int i = 0; i < t; i++)
	{
	
	 cin >> n;

		

	cout << sumarr[n];
	cout << "\n";

	}



	return 0;
}

