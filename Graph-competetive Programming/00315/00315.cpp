// 00315.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include <cstdio>
#include <cstring>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include <sstream>

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
#define sz 105

int dfs_num[sz],
	dfs_low[sz], 
	articulation_vertex[sz], 
	parent[sz],
	V,
	rootNode,
	rootChildren,
	iterationCounter,
	matrix[sz][sz];

void init()
{
	memset(dfs_num, UNVISITED, sizeof dfs_num);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(articulation_vertex, 0, sizeof articulation_vertex);
	AdjList.assign(V, vii());
	rootChildren = iterationCounter=0;
	memset(matrix, 0, sizeof matrix);
}

void addEdge(int u, int v)
{
	if (!matrix[u][v])
	{
		AdjList[u].push_back(make_pair(v, 0));
		AdjList[v].push_back(make_pair(u, 0));
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
}

void articulationPoints(int u)
{
	dfs_num[u] = dfs_low[u] = iterationCounter++;

	for (int i = 0; i < AdjList[u].size(); i++)
	{
		ii v = AdjList[u][i];
		if (dfs_num[v.first] == UNVISITED)
		{
			parent[v.first] = u;

			if (u == rootNode)
				rootChildren++;
			
			articulationPoints(v.first);

			if (dfs_low[v.first] >= dfs_num[u])
				articulation_vertex[u] = 1;

			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
		}
		else if (v.first!=parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
	}
	
}

int noOfPoints()
{
	REP(i, V)
	{
		if (dfs_num[i] == UNVISITED)
		{
			rootNode = i;
			rootChildren = 0;
			articulationPoints(i);
			articulation_vertex[rootNode] = (rootChildren > 1);
		}
	}
	int count = 0;
	

	REP(i, V)
		if (articulation_vertex[i])count++;

	return count;
}

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string str;
	int u, v;
	while (1)
	{
		cin >> V;
		if (V == 0)
			break;
		
		init();
		
		while (1)
		{
			getline(cin, str);

			if (str.empty())
				getline(cin, str);
			//cin >> str;
			istringstream s(str);

			s >> u;

			if (u == 0)
				break;

			u--;

			while (s >> v)
			{
				v--;
				
					addEdge(u, v);
					
			}

		}

		cout << noOfPoints() << "\n";
	}

	return 0;	
}

