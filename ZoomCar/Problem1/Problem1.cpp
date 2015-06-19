// Problem1.cpp : Defines the entry point for the console application.
//

// CHPLGNS.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

// Common memset settings
//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr); // to clear array of integers

typedef long long int LL;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// vector<vii> AdjList;    // graph representation


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

LL fact[100001];
int arr[100001];

#define M 1000000007

int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	fact[0] = 1;

	FOR(i, 1, 100000)
	{
		fact[i] = (fact[i - 1] * i) % M;
	}

	LL sum = 1, m, mx;
	LL ans = 0;
	LL n;

	cin >> n;

	cin >> m;

	LL m2= m;

	while (--m >= 0)
		cin >> arr[m];

	sort(arr, arr + m2);

	int count = 1;

	FOR(i,1,m2-1)
	{
		if (arr[i] == arr[i - 1])
			count++;
		else
		{
			sum *= fact[count];
			count = 1;
		}
	}
		
	sum += m2 - 1;


	REP(i,(n-1))       // faculty
	{
		
		cin >> m;
		m2 = m;
		while (--m >= 0)
			cin >> arr[m];

		sort(arr, arr + m2);

		count = 1;
		LL sum2 = 1;
		FOR(i, 1, m2 - 1)
		{
			if (arr[i] == arr[i - 1])
				count++;
			else
			{
				sum2 *= fact[count];
				count = 1;
			}

		}
		sum2 += m2 - 1;

		ans = fact[sum + sum2];
		
		ans = (ans/fact[sum]);
		ans = (ans/fact[sum2]);

		sum += sum2;

		
	}
	
/*	ans = fact[sum];

	REP(i, n)
	{
		ans = (ans / fact[arr[i]]);
	}*/

	cout << ans;

	return 0;
}

