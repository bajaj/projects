// range_min_query.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "math.h"

#include "iostream"

using namespace std;


void process(int **m, int *arr, int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		m[i][0] = i;
	}

	for (j = 1; 1 << j <= n; j++)
	{
		for (i = 0; i + (1 << j) - 1 < n; i++)
		{

			if (arr[m[i][j - 1]] < arr[m[i + (1 << (j - 1))][j - 1]])
				m[i][j] = m[i][j - 1];

			else
				m[i][j] = m[i + (1 << (j - 1))][j - 1];

		}


	}


}


int _tmain(int argc, _TCHAR* argv[])
{

	int n;

	cout << "enter no of elements in an array";

	cin >> n;

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

	}

	int logn = (int)log2(n);

	int** amm = new int*[n];

	for (int i = 0; i < n; i++)
	{
		amm[i] = new int[logn];
	}


	process(amm, arr, n);

	int i, j;

	cout << "\n" << "enter the range for rmq";

	cin >> i >> j;

	int k = (int)log2(j - 1 + 1);

	int ans;

	if (arr[amm[i][k]] < arr[amm[j - (1 << k) + 1][k]])
		ans = arr[amm[i][k]];

	else
		ans = arr[amm[j - (1 << k) + 1][k]];


	cout << "\n" << "answer is " << ans;

	return 0;
}

