// cook51_anuarm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;


int maxi(int a, int b)
{

	return a > b ? a : b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ios::sync_with_stdio(false);

	int t;

	

	int n, m;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> m;

		int max = -1, min = 100001;

		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			if (temp>max)
				max = temp;

			if (temp<min)
				min = temp;

		}

		int x, y;
		for (int j = 0; j < n; j++)
		{
			
			if (j < min)
				x = min - j;
			else
				x = j - min;

			if (j>max)
				y = j - max;
			else
				y = max - j;

			cout << maxi(x, y);
			cout <<" ";

		}

		cout << "\n";

	}


	return 0;
}

