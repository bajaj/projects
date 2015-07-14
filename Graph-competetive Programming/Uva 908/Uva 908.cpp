// Uva 908.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>
#include <queue>

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
// prim's algorithm

LL N, K, M;

inline void takeInput()
{
	LL a, b, cost;
	cin >> a >> b >> cost;
	AdjList[a-1].push_back(ii(b-1, cost));
	AdjList[b-1].push_back(ii(a-1, cost));
}

// prims algo
vi taken;
priority_queue<ii> pq;

void process(LL vtx)
{
	taken[vtx] = 1;

	for (LL i = 0; i < AdjList[vtx].size(); i++)
	{
		ii v = AdjList[vtx][i];

		if (!taken[v.first])
			pq.push(ii(-v.second, -v.first));

	}

}

LL prims()
{
	taken.assign(N, 0);
	process(0);

	LL MSTcost = 0;

	while (!pq.empty())
	{
		ii v = pq.top();
		pq.pop();

		LL w = -v.first, u = -v.second;

		if (!taken[u])
		{
			MSTcost += w;
			process(u);
		}

	}
	return MSTcost;
}

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	while (cin >> N)
	{
		AdjList.assign(N, vii());
		LL originalCost = 0;
		
		for (LL i = 0; i < N-1; i++)
		{
			LL a, b,cost;
			cin >>a>>b>>cost;
			originalCost += cost; 
		}
	
		cin >> K;
		
		REP(i, K)
			takeInput();

		cin >> M;

		for (LL i = 0; i < M;i++)
			takeInput();

		LL MstCost=prims();

		cout << originalCost << "\n" << MstCost;
		cout << "\n"<<"\n";
	}


	return 0;
}

