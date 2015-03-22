// dp_minimum_steps_to_one.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;

int min(int a, int b)
{

	return a > b ? b : a;

}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cin >> n;

	int *dp = new int[n + 1];

	dp[1] = 0;

	for (int i = 2; i <= n; i++)
	{

		dp[i] = 1 + dp[i - 1];

		if (i % 2 == 0)
			dp[i] = min(dp[i], 1 + dp[i / 2]);

		if (i % 3 == 0)
			dp[i] = min(dp[i], 1 + dp[i / 3]);



	}


	cout << "\n" << dp[n];

	return 0;
}

