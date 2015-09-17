// headout.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

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

int score[305], b[305];
vector< vector<int> > v(305);

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	FOR(i,1,n)
	{
		int c;
		cin >> c;

		REP(j, c)
		{
			int x;
			cin >> x;
			v[i].push_back(x);
			score[x]++;
		}

	}
	int val = 1;
	
	int total = n;

	queue<int> q;

	while (total)
	{
		FOR(i, 1, n)
		{
			if (score[i] == 0)
				q.push(i);
		}

		while (!q.empty())
		{
			int x = q.front();
			q.pop();
		//	_ASSERTE(score[x] == 0);
			score[x]--;
			for (int i = 0; i < v[x].size(); i++)
				score[v[x][i]]--;
			total--;
			b[x] = val;
		}
		val++;
	}

	FOR(i, 1, n)
		cout << b[i] << " ";

	return 0;
}

