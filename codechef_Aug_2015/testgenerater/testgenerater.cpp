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
#include <map>
#include <unordered_map>


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


int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	//freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);

		cout << 10001 <<" "<< 10001<<"\n";
		FOR(i, 1, 10001)
			cout << i << " ";

		cout << "\n";

		char op[] = { '=', '>', '<' };
		char player[] = { 'D', 'C' };

		REP(i, 10001)
		{
			cout << op[rand() % 3] << " " << rand() % 10005 << " " << player[rand() % 2];
			cout << "\n";
		}


	return 0;
}



