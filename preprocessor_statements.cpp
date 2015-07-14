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

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a,int b)
{
return a>b?a:b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

#include<cstdio>
inline void fastRead_int(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;

	for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

	if (c == '-') {
		neg = 1;
		c = getchar_unlocked();
	}

	for (; c>47 && c<58; c = getchar_unlocked()) {
		x = (x << 1) + (x << 3) + c - 48;
	}

	if (neg)
		x = -x;
}

   	
int main()
{	
	inp_s;cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	

	// calculate the timing
	#include <windows.h>
	DWORD dw1 = GetTickCount();
	// do something
	DWORD dw2 = GetTickCount();
	cout << "Time difference is " << (dw2 - dw1) / 1000 << " Seconds" << endl;





	return 0;
}