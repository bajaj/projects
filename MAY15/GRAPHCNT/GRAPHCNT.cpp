// GRAPHCNT.cpp : Defines the entry point for the console application.
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

LL total = 0;
LL countarr[100000];
LL dynamicArr[100000];


class graph;        // declaration

/*  design pattern

* create a graph object
*pass the graph to graph processing routine
* query the graph processing routine for information

eg...
if we put all the processing in Graph class the it will be very fat so not good design

so create class like Path


*/

// DIRECTED GRAPH

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
		//adj[w].push_back(v);
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

class dfs
{
	int* edgeto;
	bool* marked;
	int s;              // source from depth first search

	void depth_first_search(graph& G, int v)
	{
		marked[v] = 1;

		countarr[total]++;

		list<int>::iterator iter;

		for (iter = (G.adj[v]).begin(); iter != (G.adj[v]).end(); iter++)
		{
			if (v==s)
			total++;

			if (!marked[*iter])
			{
				depth_first_search(G, *iter);

				edgeto[*iter] = v;
			}

			
		}

	}


public:

	dfs(graph& G, int s) :s(s)
	{
		edgeto = new int[G.v()];
		marked = new bool[G.v()];

		for (int i = 0; i<G.v(); i++)
			marked[i] = 0;

		depth_first_search(G, s);
	}

	bool haspathto(int v)
	{
		return marked[v];
	}

	void pathto(int v, stack<int>& stac)
	{
		if (!haspathto(v))
		{
			cout << " no path to given vertices";
			return;
		}

		for (int x = v; x != s; x = edgeto[x])
			stac.push(x);
		stac.push(s);

	}

	~dfs()
	{
		delete edgeto;
		delete marked;
	}

};






void graph::print_graph()
{
	list<int>::iterator iter;

	for (int i = 0; i<V; i++)
	{
		for (iter = adj[i].begin(); iter != adj[i].end(); iter++)
			cout << endl << " " << i << " -> " << (*iter);
	}
}

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

int graph::self_loop()
{
	int count = 0;

	list<int>::iterator iter;

	for (int i = 0; i<V; i++)
	{
		for (iter = adj[i].begin(); iter != adj[i].end(); iter++)
		{
			if (i == (*iter))
				count++;
		}
	}

	return count / 2;               // because add_edge(0,0)  will add two 0 to the adj[0]
}



int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	LL v, e, x, y;

	LL ans = 0;
	
	cin >> v >> e;

	graph g(v);

	REP(i, e)
	{
		cin >> x >> y;
		x--;
		y--;

		g.addedge(x, y);
	}

	dfs d(g, 0);

	dynamicArr[total] = countarr[total];

	for (int i = total - 1; i >= 1; i--)
	{
		dynamicArr[i] = countarr[i] + dynamicArr[i + 1];
	}

	ans += dynamicArr[1];

	for (int i = 1; i < total; i++)
	{
		ans += countarr[i] * dynamicArr[i + 1];
	}

	cout << ans;

	return 0;
}

