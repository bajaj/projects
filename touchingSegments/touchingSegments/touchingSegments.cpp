// touchingSegments.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>
#include <array>

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

#define MAXL 100005
#define initMAX 1000000001

int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}



array<LL, 2> compress[MAXL], arr[MAXL], s[MAXL], e[MAXL];


void finishArrayFunction(array<LL, 2> a[MAXL], int start, int end, int& index,int flag)   // flag=0 for start
{

	FOR(i, start, end)
	{
		if (a[i][0] == a[i - 1][0])
		{
			compress[a[i][1]][flag] = index - 1;
		}
		else
		{
			compress[a[i][1]][flag] = index;
			index++;
		}
	}

}

void initialize(array<LL, 2> a[MAXL])
{
	a[0][0] = initMAX;
	a[0][1] = initMAX;
}

void maxIndexCount(int count[MAXL], int& maxIndex, int& maxi,int n)
{
	FOR(i, 1, n)
	{
		if (maxi<count[i])
		{
			maxi = count[i];
			maxIndex = i;
		}

	}

}

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	initialize(arr);
	initialize(s);
	initialize(e);
	initialize(compress);

	int t = 1;
	DRT()
	{
		int n;
		cin >> n;

		FOR(i, 1, n)
		{
			REP(j, 2)
			{
				cin >> arr[i][j];

				j ? e[i][0] = arr[i][j], e[i][1] = i : s[i][0] = arr[i][j], s[i][1] = i;

			}

		}

		//	sort(arr+1, arr+n+1);

		sort(s + 1, s + n + 1);
		sort(e + 1, e + n + 1);

		int si = 1, ei = 1, index = 1;

		while (si <= n && ei <= n)
		{
			if (s[si][0] < e[ei][0])
			{
				if (s[si][0] != s[si - 1][0])
				{
					compress[s[si][1]][0] = index;
					index++;
				}
				else
					compress[s[si][1]][0] = index - 1;

				si++;
			}
			else if (e[ei][0] < s[si][0])
			{
				if (e[ei][0] != e[ei - 1][0])
				{
					compress[e[ei][1]][1] = index;
					index++;
				}
				else
					compress[e[ei][1]][1] = index - 1;

				ei++;
			}
			else
			{
				if (e[ei][0] != e[ei - 1][0] && s[si][0] != s[si - 1][0])
				{
					compress[e[ei][1]][1] = index;
					compress[s[si][1]][0] = index;
					index++;
				}
				else
				{
					compress[e[ei][1]][1] = index - 1;
					compress[s[si][1]][0] = index - 1;
				}

				si++;
				ei++;

			}

		}

		if (si <= n)
			finishArrayFunction(s, si, n, index, 0);

		if (ei <= n)
			finishArrayFunction(e, ei, n, index, 1);


		int count[2*MAXL+2] = { 0 };

		FOR(i, 1, n)
		{
			count[arr[i][0]]++;
			count[arr[i][1]+1]--;
		}

		int maxA = 0;
		int maxAIndex = 0;

		FOR(i, 1, 500)
			count[i] += count[i - 1];
		

		maxIndexCount(count, maxAIndex, maxA, 500);

		FOR(i, 1, 500)
			count[i] = 0;
		

		FOR(i, 1, n)
		{
			if (maxAIndex >= arr[i][0] && maxAIndex <= arr[i][1]);			
			else
			{
				count[arr[i][0]]++;
				count[arr[i][1] + 1]--;
			}
		}

		FOR(i, 1, 500)
			count[i] += count[i - 1];
		

		int maxB = 0;
		int maxBIndex = 0;

		maxIndexCount(count, maxBIndex, maxB, 500);

		cout <<"Case "<<t<<": "<< maxA + maxB << "\n";
		t++;
	}


	return 0;
}

