// Partition_Problem.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

typedef long long int LL;


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)


#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a, int b)
{
	return a>b ? a : b;
}

short dp[1001];

bool partition(int arr[], LL sum, int n,int k)
{
	FOR(j, 0, k)
		dp[j] = 0;

	dp[0] = 1;

	FOR(i, 1, n)
	{
		for (int j = k - arr[i]; j >= 0;j--)
		{
			if (dp[j])
			{
				if (j + arr[i] <= k)
					dp[j + arr[i]] = 1;
			}

		}

		if (dp[k])
			return true;
	}

	return dp[k];
}


int main()
{
	//inp_s; cinnull;

    #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, arr[1000],k;
	DRT()
	{
		cin>>n>>k;

		LL sum = 0;
		FOR(i,1,n)
		{
			cin >> arr[i];
			sum += arr[i];
		}

		if (partition(arr, sum, n, k))
			cout << 1;
		else
			cout << 0;
		cout << "\n";
	}


	return 0;
}