// Target.cpp : Defines the entry point for the console application.
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

vector<vii> AdjList;    // graph representation
vector< pair<int, ii> > EdgeList;   // edgeList for kruskal algorithm


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define rdarr(a,n) REP(i,n) cin >> a[i];

int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

LL arthi(LL a1, LL n, LL d)
{
	LL an = (a1 + (n - 1)*d);

	return n*(a1 + an) / 2;

}


int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

int arrc[] = { 91, 81, 61, 7 };
int arrop[] = { 99, 82, 98 };
int arrno[] = { 77760311 };

cout << 96 << "\n";

int count = 0;
for (int bitmask = 0; bitmask <= 7; bitmask++)
{
	int country = (bitmask)&(1 << 2);
	int op = (bitmask)&(1 << 1);
	int no = (bitmask)&(1);

	int in = 4, jn = 3, jk = 1;
	

	REP(i,in)
		REP(j,jn)
		REP(k, jk)
	{
		//count++;
		if (country)
			cout << arrc[i];
		else
			cout << 21;

		cout << " ";

		if (op)
			cout << arrop[j];
		else
			cout << 55;

		if (no)
			cout << arrno[k];
		else
			cout << "a" << 1234567;
		
		cout << "\n";
	}

	//cout << count;
}


	
	return 0;
}

