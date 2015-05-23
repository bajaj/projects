// SEZ.cpp : Defines the entry point for the console application.
//

// #include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>
#include <list>
#include <stack>
#include <deque>

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

typedef unsigned long long int LL;


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

int mark[205];
int col[205];
pair<int,int> deg[205];

class graph;        // declaration

class graph
{
	int V;

public:
	list<int> *adj;


	graph(int x) :V(x)
	{
		adj = new list<int>[V];
	}

	void addedge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);

		deg[v].first++;
		deg[w].first++;

	}

	int v()
	{
		return V;
	}

	int E()                    // no of edges
	{
		list<int>::iterator iter;

		int count = 0;
		for (int i = 0; i<V; i++)
		{
			count += adj[i].size();
		}

		return count / 2;
	}

	int degree(int v)
	{
		return adj[v].size();
	}

	int maxdegree();

	int self_loop();    // not that necessary

	void print_graph();

	~graph()
	{
		delete[] adj;
	}

};

int graph::maxdegree()
{
	int max = 0;
	for (int i = 0; i<V; i++)
	{
		if (adj[i].size()>max)
			max = adj[i].size();
	}
	return max;
}


int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int v, e, ans,x,y;

	cin >> v >> e;

	graph g(v);

	REP(i, v)
		deg[i].second = i;
	

	REP(i, e)
	{
		cin >> x >> y;
		g.addedge(x - 1, y - 1);
	}

	sort(deg, deg + v);

	//1---sez
	//2--non sez
	
	REP(i, v)
	{
		int xx = deg[i].second;

		if (!mark[xx])
		{
			mark[xx] = 1;

			if (deg[i].first <= 1)
			{
				col[xx] = 1;   //SEZ

				list<int>::iterator iter;

				for (iter = g.adj[xx].begin(); iter != g.adj[xx].end(); iter++)
				{
					mark[*iter] = 1;
					col[*iter] = 2;        // NON-SEZ

					for (list<int>::iterator iter2 = g.adj[*iter].begin(); iter2 != g.adj[*iter].end(); iter2++)
					{
						if (!mark[*iter2])
						{
							REP(j, v)
							{
								if (deg[j].second== *iter2)
								{
									deg[j].first--;
									break;
								}
							}

							
						}

					}

				}

			}
			

		}


	}


	int sez = 0, nsez = 0;

	REP(i, v)
	{
		if (col[i] == 1)
			sez++;
		else if (col[i] == 2)
			nsez++;
	}

	//if ((sez - nsez) >= 0)
		cout << sez - nsez;
	//else cout << 0;

	return 0;
}

