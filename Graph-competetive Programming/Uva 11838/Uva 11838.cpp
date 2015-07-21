// Uva 11838.cpp : Defines the entry point for the console application
//http://www.quora.com/Whats-a-good-explanation-for-Tarjans-strongly-connected-components-algorithm

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <memory>

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
vector< pair<int, ii> > EdgeList; // edgelist for kruskal algorithm


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define rdarr(a,n) REP(i,n) cin >> a[i];

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)
#define Inf 1000000
#define UNVISITED -1

int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int N, M,SccComponents,dfs_counter;
vi dfs_num, dfs_low,visited,S;

inline void addEdge(int u, int v, int p)
{
	AdjList[u].push_back(ii(v,0));

	if (p == 2)
		AdjList[v].push_back(ii(u, 0));
}

void trajanScc(int u)
{
	dfs_num[u] = dfs_low[u] = dfs_counter++;
	visited[u] = 1;
	S.push_back(u);

	for (int i = 0; i < (int)AdjList[u].size(); i++)
	{
		ii v = AdjList[u][i];
			
		if (dfs_num[v.first] == UNVISITED)
			trajanScc(v.first);
		
		if (visited[v.first])
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
	}

	if (dfs_num[u] == dfs_low[u])
	{
		++SccComponents;

		while (1){
			int x = S.back();
			S.pop_back();
			visited[x] = 0;

			if (u == x)
				break;
		}

	}	
	
}


int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (true)
	{
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		AdjList.assign(N, vii());

		REP(i, M)
		{
			int u, v, p;
			cin >> u >> v >> p;
			addEdge(u-1, v-1, p);
		}

		SccComponents = 0,dfs_counter=0;
		dfs_low.assign(N, 0);
		dfs_num.assign(N, UNVISITED);
		visited.assign(N, 0);
		//S.assign(N, 0);

		REP(i, N)
		{
			if (dfs_num[i] == UNVISITED)
				trajanScc(i);
		}

		if (SccComponents == 1)
			cout << 1;
		else
			cout << 0;

		cout << "\n";
	}



	return 0;
}

