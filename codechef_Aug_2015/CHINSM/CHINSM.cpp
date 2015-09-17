// CHINSM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// codechef_Aug_2015.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
//#include "stdafx.h"


#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>
#include <map>
#include <unordered_map>
#include<stack>
#include<array>

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

typedef pair<LL, LL> ii;
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
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int a[100002], has[100002], ind[100002];

int main()
{
	inp_s; cinnull;

		#pragma warning (disable : 4996)
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;

	FOR(i, 1, n)
		cin >> a[i];

	ind[n] = n + 1;;
	int elemgEk = n + 1;
	int minIndex = n + 1;
	has[a[n]] = n;

	if (a[n] > k)
		elemgEk = n;

	FORD(i, n - 1, 1)
	{
		if (a[i] < k)
			ind[i] = min(n + 1, minIndex);

		if (a[i] == k)
			ind[i] = min(elemgEk, minIndex);

		if (a[i] > k)
		{
			int diff = a[i] - k;

			if (k == 0)
				ind[i] = has[1];

			for (int j = 1; j <= ceil(sqrt(diff)); j++)
			{

				if (diff%j != 0)
					continue;

				int a = j,
					b=(diff/j);
				int index=100005; 

				if (a > k && has[a])
					index = has[a];
				
				if (b > k && has[b])
					index = min(index,has[b]);

				if (index && index <= minIndex)
				{
					if (ind[i] == 0)
						ind[i] = index;
					else
						ind[i] = min(ind[i], index);

				}
			}

			if (!ind[i])
				ind[i] = min(n + 1, minIndex);
			else
				ind[i] = min(ind[i], minIndex);

		}

		has[a[i]] = i;

		if (a[i] > k)
			elemgEk = i;

		minIndex = min(minIndex, ind[i]);

	}

	LL count = 0;

	FOR(i, 1, n)
		count += ind[i] - i;


	cout << count;

	return 0;
}
