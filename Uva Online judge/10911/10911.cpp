// 10911.cpp : Defines the entry point for the console application.
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

double min(double a, double b)
{
	return a < b ? a : b;
}

int N,target;
int x[20], y[20];
double dist[20][20],memo[1 << 16];

double matching(int bitmask)
{
	if (memo[bitmask]>-0.5)
		return memo[bitmask];

	if (bitmask == target)
		return memo[bitmask] = 0;

	double ans = 2000000000.0;

	int p1, p2;
	
	REP(i, 2 * N)
		if (!(bitmask&(1 << i)))
		{
			p1 = i; break;
		}
	
	for (p2 = p1 + 1; p2 < 2 * N; p2++)
		if (!(bitmask&(1 << p2)))
			ans = min(ans, dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));

	
	return memo[bitmask] = ans;
}


int main()
{
	inp_s; cinnull;

    #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int Case = 1;
	while (cin>>N && N!=0)
	{
		string str;
		REP(i, 2 * N)
			cin >> str >> x[i] >> y[i];

		for (int i = 0; i < 2 * N - 1; i++)
			for (int j = i + 1; j < 2 * N; j++)
				dist[i][j] = hypot(x[i] - x[j], y[i] - y[j]);

		REP(i, (1 << 16))
			memo[i] = -1;

		target = (1 << (2 * N)) - 1;

		cout.precision(2);
		cout << "Case "<<Case++<<": "<<fixed<<matching(0)<<"\n";
		
	}


	return 0;
}

