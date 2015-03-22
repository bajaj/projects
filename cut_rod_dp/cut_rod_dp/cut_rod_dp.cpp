// cut_rod_dp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;


int max(int a, int b)
{
	return a > b ? a : b;

}

int cutrod(int* prices, int n)
{
	int* val=new int[n + 1];
	val[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		val[i] = prices[i];
		
		int maxval = -1;

		
		for (int j = 0; j <= i/2; j++)
		{
			maxval = max(maxval, val[j] + val[i - j]);

		}
		val[i] = maxval;

	}

	int ans = val[n];

	delete[] val;
	
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cin >> n;

	int* prices = new int[n+1];

	prices[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> prices[i];

	}

	cout << "\n" << "max value is"<<cutrod(prices,n);



	return 0;
}

