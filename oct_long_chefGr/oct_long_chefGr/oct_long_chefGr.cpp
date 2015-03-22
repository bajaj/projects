// oct_long_chefGr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	short t, n, arr[100];
	int m;

	cin >> t;

	for (short i = 0; i < t; i++)
	{
		cin >> n >> m;

		short maxi = 0;
		
		
		cin >> arr[0];
		maxi = arr[0];


		for (short j = 1; j < n; j++)
		{
			cin >> arr[j];

			if (arr[j]>maxi)
			  maxi = arr[j];	   

		}

		int sum = 0;
		for (short j = 0; j < n; j++)
			sum += (maxi - arr[j]);

		if (sum == 0)
		{
			if (m%n == 0)
				cout << "Yes";
			else
				cout << "No";
		}
		else
		{

			if (m == 0)
				cout << "No";
			else if (m > sum)
			{
				m = m - sum;
				if (m%n == 0)
					cout << "Yes";
				else
					cout << "No";
			}
			else if (m==sum)
				cout << "Yes";
			else
			cout << "No";
		}
		cout << "\n";


	}
		


	return 0;
}

