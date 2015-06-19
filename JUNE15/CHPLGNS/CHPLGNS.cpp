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

struct point
{
	LL x, y;

	point()
	{
		x = y = 0;
	}
	point(LL _x, LL _y) :x(_x), y(_y){}
};

point p[100001];
int polygon[100001];
pair<LL,int> areaP[100001];

LL area(int size)
{
	LL ans=0;
	LL x1, x2, y1, y2;

	REP(i,size)
	{
		x1 = p[i].x;
		y1 = p[i].y;

		x2 = p[i+1].x;
		y2 = p[i+1].y;

		ans += (x1*y2 - x2*y1);
	}
	return abs(ans) / 2;
}


int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	DRT()
	{
		int n;
		cin >> n;

		REP(i, n)
		{
			int m;
			cin >> m;

			REP(j, m)
			{
				cin >> p[j].x;
				cin >> p[j].y;
			}
			p[m].x = p[0].x;
			p[m].y = p[0].y;

			areaP[i].first = area(m);
			areaP[i].second = i;

		}
		sort(areaP,areaP+n);

		REP(i, n)
		{
			polygon[areaP[i].second] = i;
		}

		REP(i, n)
		{
			cout << polygon[i] << " ";
		}
			
		cout << "\n";
	}

	return 0;
}

