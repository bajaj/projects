// Uva 10600.cpp : Defines the entry point for the console application.
// kruskal algorithm

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


int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

class UnionFind
{
	int n;
	vi arr,sz;

public:
	UnionFind(int x)
	{
		n = x;
		arr.assign(n, 0);
		sz.assign(n, 0);
		initialize();
	}

	void initialize()
	{
		REP(i,n)
			arr[i] = i;
	}

	int findSet(int i)
	{
		while (i != arr[i])
		{
			arr[i] = arr[arr[i]];
			i = arr[i];
		}
		return i;
	}

	bool isSameSet(int i,int j)
	{
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j)
	{
		
		if (!isSameSet(i, j))
		{
			int rooti = findSet(i);
			int rootj = findSet(j);
			
			if (sz[rooti] > sz[rootj])
				arr[rootj] = rooti;
			else
				arr[rooti] = rootj;                  // i is getting to j

			if (sz[rooti] == sz[rootj])
				sz[rootj]++;
		}
	}

};

bool marked[100005];
bool selected[101];

int M,N;

void incrCount(int& count,int u,int v)
{
	if (!selected[u])
		count++;

	if (!selected[v])
		count++;

	selected[u] = selected[v] = 1;

}

int kruskal(int edge)
{
	int mst_cost = 0;
	int count = 0;
	memset(selected, 0, sizeof(bool)*101);

	
	UnionFind uf(N+5);
	REP(i, M)
	{
		if (edge == i)
			continue;

		pair<int, ii> x = EdgeList[i];
		int u = x.second.first,
			v = x.second.second;

		if (!uf.isSameSet(u, v) && x.first!=Inf)
		{
			incrCount(count,u,v);
			mst_cost += x.first;
			uf.unionSet(u, v);

			if (edge==-1)
				marked[i] = 1;
			
		}

	}

	if (count != N && edge != -1)
	{
		return Inf;
	//	mst_cost += EdgeList[edge].first;
	}
	
	return mst_cost;
}

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	DRT()
	{
		cin>>N>>M;

		memset(marked, 0, sizeof(bool)*100005);

		EdgeList.clear();

		REP(i, M)
		{
			int u, v, w;
			cin >> u >> v >> w;
			EdgeList.push_back(make_pair(w, ii(u-1, v-1)));
		}

		sort(EdgeList.begin(), EdgeList.end());

		int mst_cost1 = kruskal(-1);
		int mst_cost2 = Inf;
		
		REP(i, M)
			if (marked[i])
				mst_cost2 = min(mst_cost2, kruskal(i));
		
		cout <<mst_cost1<<' '<<mst_cost2<<endl;

	}


	return 0;
}

