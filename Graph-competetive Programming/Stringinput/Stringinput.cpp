// Stringinput.cpp : Defines the entry point for the console application.
//

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




int _tmain(int argc, _TCHAR* argv[])
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int aa;
	string a, b, c;

	cin >> aa;// >> b;

	getline(cin, c);
	
	//cout << c;

	if (c.empty())
		cout << "cool";

	cin >> a;
	cout << a;
	getline(cin, c);
	getline(cin, c);
	getline(cin, c);
	cout << "\n c is " << c;


	return 0;
}

