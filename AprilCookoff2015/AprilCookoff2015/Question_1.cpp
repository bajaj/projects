// AprilCookoff2015.cpp : Defines the entry point for the console application.
//
//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
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
#define rdarr(a,n) REP(i,n) cin >> a[i];

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

LL dp[2001][2001];

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	/*DRT()
	{
		LL n;
		cin >> n;
		LL arr[50001];
		LL sum = 0;

		REP(i, n)
		{
			cin >> arr[i];
			sum += arr[i];
		}

		sum = sum / (n - 1);

		REP(i, n)
		{
			cout << sum - arr[i]<<" ";
		}

		cout << "\n";
	}*/

	/*DRT()
	{
		int n, m, k;
		int arr1[101], arr2[101];

		cin >> n >> m >> k;

		REP(i, m)
		{
			cin >> arr1[i];
		}
		REP(i, k)
		{
			cin >> arr2[i];
		}

		int ptr1 = 0, ptr2 = 0;
		int both = 0, none = 0;

		FOR(i, 1, n)
		{
			if (ptr1 < m && ptr2 < k)
			{
				if (i == arr1[ptr1] && i == arr2[ptr2])
				{
					both++;
					ptr1++;
					ptr2++;
				}
				else if (i == arr1[ptr1])
					ptr1++;
				
				else if (i == arr2[ptr2])
					ptr2++;
				else
					none++;
			}
			else if (ptr1 < m)
			{
				if (i != arr1[ptr1])
					none++;
				else
					ptr1++;
			}
			else if (ptr2 < k)
			{
				if (i != arr2[ptr2])
					none++;
				else
					ptr2++;
			}
			else
				none++;

		}

		cout << both << " " << none;
		cout << "\n";


	}
	*/

	LL n, q, arr[2001],l,r;
	

	cin >> n >> q;

	REP(i, n)
	{
		cin >> arr[i];
	}

	
	REP(i, n)
	{
		REP(j, n)
		{
			if (j == 0)
			{
				if (arr[i] > arr[j])
					dp[i][j] = 1;
				else
				dp[i][j] = 0;
				continue;
			}
			if (i == j)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = dp[i][j - 1];

				if (arr[j] < arr[i])
					dp[i][j] += 1;
			}

		}
	}

	REP(k, q)
	{
		cin >> l >> r;

		l = l - 1; r = r - 1;

		LL sum = 0;

		for (int i = l + 2; i < r - 1; i++)
		{
			LL a = min(dp[i][i - 1] - dp[i][l], dp[l][i - 1]);
			LL b = min(dp[i][r - 1], dp[r][r-1]-dp[i][i+1]);

			sum += (a*b);
		}

		cout << sum << "\n";
	}




	return 0;
}

