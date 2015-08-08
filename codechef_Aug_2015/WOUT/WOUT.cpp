// GRGUY.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// codechef_Aug_2015.cpp : Defines the entry point for the console application.
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

typedef unsigned long long LL;

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

int arr[1000006];

void maxSumSubarray(int k,int n,int& start,int& end)
{
	long long currsum = 0,maxsum=0;

	REP(i, k)
	{
		currsum += arr[i];
		start = 0;
		end = k - 1;
	}
	maxsum = currsum;
	
	FOR(i,k,n-1)
	{
		currsum += arr[i]-arr[i-k];
		
		if (currsum >= maxsum)
		{
			maxsum = currsum;
			start = i - k + 1;
			end = i;
		}
	}
	
}


int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	DRT()
	{
		int n, h;
		cin >> n >> h;
		memset(arr, 0, (n+1)*sizeof(int));

		REP(i, n)
		{
			int a, b;
			cin >> a >> b;

			arr[a] += 1;
			arr[b + 1] -= 1;
		}

		REP(i, n)
		{
			if (i)
				arr[i] += arr[i - 1];
		}

		int start, end;
		long long ans = 0;
		maxSumSubarray(h, n, start, end);
		
		FOR(i, start, end)
			ans += n - arr[i];
		

		cout <<ans<<"\n";

	}

	return 0;
}



