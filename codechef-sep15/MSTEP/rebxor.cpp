// MSTEP.cpp : Defines the entry point for the console application.
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

const int MN = 20000000;

class trie
{
	int n;
	int nodes[MN][2];

public:
	void clear()
	{
		n = 1;
		nodes[0][0] = nodes[0][1] = -1;
	}

	void insert(int x)
	{
		int node = 0;
		for (int i = 31; i >= 0; i--)
		{
			int next = (x&(1 << i)) != 0;
			
			if (nodes[node][next] == -1)
			{
				nodes[node][next] = n;
				nodes[n][0] = nodes[n][1] = -1;
				n++;
			}
			node = nodes[node][next];
		}
	}

	int query(int x)
	{
		int node = 0,
			ans = 0;

		for (int i = 31; i >= 0; i--)
		{
			int next = (x&(1 << i))!=0;
			int toInclude = 1;
			if (nodes[node][next ^ 1] == -1)
			{
				toInclude = 0;
				next ^= 1;
			}

			if (toInclude)
				ans += (1 << i);
			
			_ASSERT(nodes[node][next ^ 1] != -1);
			node = nodes[node][next ^ 1];
		}
		return ans;
	}

};


int a[400005],
	b[400005],
	arr[400005];

trie tree;

int main()
{
	inp_s; cinnull;
	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);

	
	int n;
	cin >> n;
	rdarr(arr, n);


	int best =0, accum = 0;
	tree.clear();
	tree.insert(0);
	for (int i = n - 1; i >= 0;i--)
	{
		accum ^= arr[i];
		best = max(best, tree.query(accum));
		b[i] = best;
		tree.insert(accum);
	}



	 best = 0,
		accum=0;

	tree.clear();
	tree.insert(0);
	REP(i, n)
	{
		accum ^= arr[i];
		best = max(best,tree.query(accum));
		a[i] = best;
		tree.insert(accum);
	}

	
	
	int ans = 0,
		l=n-2,
		r=n-1;

	while (l >= 0)
	{
		ans = max(ans, a[l] + b[r]);
		l--;
		r--;
	}

	cout << ans;

	return 0;
}

