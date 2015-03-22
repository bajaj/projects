// oct_long_fatchef.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	std::ios::sync_with_stdio(false);

	unsigned int n,t, m;

	short arr[100000] = { 0 };

	char x;

	cin >> t;
	

	for (int k = 0; k < t; k++)
	{
		cin >> n;
		cin >> m;

		for (int i = 0; i < m; i++)
		{
			int temp;
			cin >> x;
			cin >> temp;
			arr[temp-1] = int(x);
		}

		short previous = 1;

		int prev_index = 0;
		unsigned long long int product = 1;


		for (int i = 0; i < n; i++)
		{

			if (arr[i] != 0)
			{
				if (previous != 1 && previous!=arr[i])
				{
					product = (product*(i - prev_index)) % 1000000009;
				}

				previous = arr[i];
				prev_index = i;
				arr[i] = 0;
			}


		}

		cout << product;
		cout << "\n";


	}

	

	return 0;
}

