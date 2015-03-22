// CLPREM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "algorithm"

using namespace std;

unsigned long getsum(unsigned long n)
{
	return (n*(n + 1)) / 2;

}


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long long arr[100002], sumtill, sum[100001],k,n;

	int t;

	cin >> t;

	while (t--)
	{
		arr[0] = 0;
		sum[0] = 0;

		cin >>n>>k;

		for (int i = 1; i <= k; i++)
		{
			cin >> arr[i];
		}

		sort(arr + 1, arr + k + 1);

		int i;
		for (i= 1; i <= k; i++)
		{
			sumtill = getsum(arr[i] - 1);

			sumtill -= sum[i - 1];
			sum[i] = sum[i - 1] + arr[i];

			if (sumtill >= arr[i]);
			else
				break;

		}

		if (i > k)
		{
			sumtill = getsum(n)-sum[k];
		}

		if (sumtill % 2 == 0)
		{
			cout << "Chef";
		}
		else
			cout << "Mom";

		cout << "\n";
	}


	return 0;
}

