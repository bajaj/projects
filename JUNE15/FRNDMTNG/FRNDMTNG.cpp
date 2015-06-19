// FRNDMTNG.cpp : Defines the entry point for the console application.
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



int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double T1, T2, t1, t2,ans,area,tri1,tri2,total;

	DRT()
	{
		cin >> T1 >> T2 >> t1 >> t2;

		total = T1*T2;
	
	
		if (t2 == 0 && t1 != 0)
		{
			tri1 = (T2 - t1)*T1 / 2;
			tri2 = (T1*T2) / 2;
		}
		else if (t1 == 0 && t2 != 0)
		{
			tri1 = (T1 - t2)*T2 / 2;
			tri2 = (T2*T1) / 2;
		}
		else if (t1 == 0 && t2 == 0)
		{
			tri1 = total/2;
			tri2 = total / 2;
		}
		else
		{
			tri1 = pow((T2 - t1), 2) / 2;
			tri2 = pow((T1 - t2), 2) / 2;
		}

		area = total - tri1 - tri2;

		ans = area / total;

		cout.precision(6);

		ans = 0;

		cout<<ans << "\n";

	}

	return 0;
}

