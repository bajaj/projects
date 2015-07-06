// Graph-competetive Programming.cpp : Defines the entry point for the console application.
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

#define VISITED 1
#define UNVISITED -1

vector<vii> Ad;
vector<vii>& AdjList=Ad;

int marked[100];
int reachable[100];
int reachX[100];

int ans[100][100];

void dfs(int u,int vertex)
{
	marked[u] = VISITED;

	if (vertex == 0)
		reachable[u] = VISITED;
	else
		reachX[u] = VISITED;

	REP(i, (int)AdjList[u].size())
	{
		ii v = AdjList[u][i];

		if (marked[v.first] == UNVISITED)
			dfs(v.first,vertex);
	}
}

void init(int n,int arr[])
{
	REP(i, n)
		arr[i] = UNVISITED;

}

void takeInput(int n)
{
	int x;
	REP(i, n)
	{
		REP(j, n)
		{
			cin >> x;

			if (x)
				AdjList[i].push_back(make_pair(j, 0));

		}

	}

}

void fillAnswer(int v,int n)
{
	if (v == 0)
	{
		ans[0][0] = 1;

		REP(i, n)
		{
			if (reachable[i] == VISITED)
				ans[v][i]=ans[i][i] = 1;
			else
				ans[v][i] =ans[i][i] = 0;
			
		}
	}
	else
	{
		REP(i, AdjList[v].size())
		{
			ii vert= AdjList[v][i];

			if (reachable[vert.first] == VISITED && reachX[vert.first] == UNVISITED)
				ans[v][vert.first] = 1;
			else
				ans[v][vert.first] = 0;
		}
	}

}

void initAns(int n)
{
	REP(i, n)
		REP(j, n)
		ans[i][j] = 0;
}

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t=1;
		
	DRT()
	{
		vector<vii> Adj(100);
		AdjList = Adj;
		int n; 
		cin >> n;
		takeInput(n);
		init(n,reachable);
		
		REP(i, n)
		{
			init(n, reachX);
			init(n, marked);
			
			marked[i] = VISITED;
			dfs(0,i);
			fillAnswer(i, n);
		}


		cout << "Case " << t << ":" << "\n";
		
		bool flag = 1;
		REP(i, 2 * n + 1)
		{
			bool toggle = 1;

			REP(j, 2 * n + 1)
			{
				if (flag)
				{
					if (j == 0 || j + 1 == 2 * n + 1)
						cout << "+";
					else
						cout << "-";
				}
				else
				{
					if (toggle)
						cout << "|";
					else
					{
						if (ans[(int)i/2][(int)j/2] == 1)
							cout << "Y";
						else
							cout << "N";
							
					}
					
				}
			toggle = !toggle;
			}

			cout << "\n";
			flag = !flag;
		}
			
		t++;
	}

	return 0;
}

