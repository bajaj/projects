// UVa online Judge.cpp : Defines the entry point for the console application.
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

int M, C, price[20][21];
int memo[201][20];
bool reachable[20][201];

int solve(int money, int g)
{
	if (money < 0)
		return -100000;

	if (g == C)
		return M - money;         // money i have spent
	
	if (memo[money][g] != -1)
		return memo[money][g];

	int ans = -1;

	for (int model = 1; model <= price[g][0]; model++)
		ans = max(ans, solve(money - price[g][model], g + 1));

	return memo[money][g] = ans;     // store and return
}



int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	DRT()
	{
		cin >> M >> C;
		//memset(memo, -1, sizeof memo);
		memset(reachable, 0, sizeof reachable);

		REP(i, C)
		{
			cin >> price[i][0];
			FOR(j, 1, price[i][0])
				cin >> price[i][j];
		}

		//int ans = solve(M, 0);

		FOR(i, 1,price[0][0])
		{
			if (M - price[0][i] >= 0)
				reachable[0][M - price[0][i]] = 1;
		}

		FOR(i, 1, C - 1)
		{
			//for (int j = 0; j < price[i - 1][0];j++)
			REP(j, 201)
			{
				if (reachable[i - 1][j])
				{
					FOR(k, 1, price[i][0])
					{
						if (j - price[i][k]>=0)
							reachable[i][j - price[i][k]] = 1;
					}
				}
			}
		}

		int ans = -1;

		REP(i, 201)
		{
			if (reachable[C - 1][i])
			{
				ans = i;
				break;
			}
		}

		if (ans < 0)
			cout << "no solution";
		else
			cout << M-ans;
		cout << "\n";
	}



}

