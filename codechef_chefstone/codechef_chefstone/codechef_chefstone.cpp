// codechef_chefstone.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long int t, n, k, max, arr[100000], profit,x;

	cin >> t;

	while (t--)
	{
		cin >> n >> k;

		max = 0;

		for (unsigned long long int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		for (unsigned long long int i = 0; i < n; i++)
		{
			cin >> profit;

			if (arr[i] <= k)
			{
				x = floor(k / arr[i])*profit;
				if (max < x)
					max = x;
			}

		}

		cout << max << "\n";
	}
	

	return 0;
}

