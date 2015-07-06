// 11060.cpp : Defines the entry point for the console application.
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

vector<vii> AdjList;
//vector<vii>& AdjList = Ad;

// in main    AdjList.assign(V,vii())

bool cmp(const int& a, const int& b)
{
	return a > b;
}

struct compareVal
{
	bool operator()(const int& a,const int& b)
	{
		return a > b;
	}
};

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string str;
	int testCase = 0;
	//while (getline(cin, str))
	int nox;
	while (cin>>nox)
	{
	//	cout << str;
	

		testCase++;
		int vertices = nox,
		    indegree[100],
		    sortedList[100],
		    counter = 0;
		string namesList[100];
		memset(indegree, 0, sizeof indegree);

		map<string, int> list;

		REP(i, vertices)
		{
			string x;
			cin >> x;
			list[x] = i;
			namesList[i] = x;
		}
		int edges;
		cin >> edges;
		AdjList.assign(vertices, vii());
		

		REP(i, edges)
		{
			string u, v;
			cin >> u >> v;

			indegree[list[v]]++;

			AdjList[list[u]].push_back(make_pair(list[v], 0));
		}

		//queue<int> pq;

		priority_queue<int, vi, compareVal> pq;

		REP(i, vertices)
			if (indegree[i] == 0)
				pq.push(i);

		

		while (!pq.empty())
		{
			int u = pq.top(); pq.pop();

			for (int i = 0; i < AdjList[u].size(); i++)
			{
				 ii v = AdjList[u][i];

				 if (--indegree[v.first] == 0)
					 pq.push(v.first);
			}
			
			sortedList[counter++] = u;
		}


		cout << "Case #" << testCase << ":" << " Dilbert should drink beverages in this order:";

		REP(i, vertices)
			cout << " " << namesList[sortedList[i]];
		cout << ".";

		cout << "\n\n";
	}

	return 0;
}
