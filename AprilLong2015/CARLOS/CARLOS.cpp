// CARLOS.cpp : Defines the entry point for the console application.
//

// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <list>

#include <stack>

#include <deque>

using namespace std;


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

typedef long long int LL;


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)


#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a, int b)
{
	return a>b ? a : b;
}

#define INT_MAX 2147483647 


class graph;        // declaration

/*  design pattern

* create a graph object
*pass the graph to graph processing routine
* query the graph processing routine for information

eg...
if we put all the processing in Graph class the it will be very fat so not good design

so create class like Path


*/

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




// *****************************************///////

class connected_components
{
	int* marked;
	int* id;
	int count;

public:
	connected_components(graph& g);
	void dfs(graph& g, int s);
	int cout();
	int my_cc(int v);

	~connected_components()
	{
			delete[] marked;
			delete[] id;
	}

};

connected_components::connected_components(graph& g) :count(0)
{
	marked = new int[g.v()];
	id = new int[g.v()];

	for (int i = 0; i<g.v(); i++)
	{
		marked[i] = 0;
	}
	for (int i = 0; i<g.v(); i++)
	{
		if (!marked[i])
		{
			dfs(g, i);
			count++;
		}

	}
}

void connected_components::dfs(graph& g, int s)
{
	marked[s] = 1;
	list<int>::iterator iter;

	id[s] = count;

	for (iter = (g.adj[s]).begin(); iter != (g.adj[s]).end(); iter++)
	{
		if (!marked[*iter])
			dfs(g, *iter);
	}

}

int connected_components::cout()
{
	return count;
}

int connected_components::my_cc(int x)
{
	return id[x];

}

int min(int a, int b)
{
	return a > b ? b : a;
}


int arr[200001];
int dp[200001][201];
int s[201];
int M[201];
int id[201];

int m;

bool find(int p, int q)
{
	return id[p] == id[q];
}

void unite(int p, int q)
{
	int pid = id[p];

	REP(i, m + 1)
	{
		if (id[i] == pid)
			id[i] = id[q];
	}

}

int main()
{
	inp_s; cinnull;

    #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int  k, n;

	DRT()
	{
		REP(i, 201)
		{
			M[i] = 0;
			id[i] = i;
		}

		cin >> m >> k >> n;

	//	graph g(m + 1);

		REP(i, k)
		{
			int x, y;
			cin >> x >> y;
			
		//	g.addedge(x, y);
			unite(x, y);
		}

		int counts = 0; // no of different letter in 

		REP(i, n)
		{
			cin >> arr[i];
			M[arr[i]]= 1;
		}

		REP(i, 201)
		{
			if (M[i])
				s[counts++] = i;
		}

		connected_components cc(g);
		
//		cc.my_cc(1);

		
			REP(j, counts)
			{
				int ans;

				if (arr[0] == s[j])
					ans = 0;
				else if (cc.my_cc(arr[0]) == cc.my_cc(s[j]))
					ans = 1;
				else
					ans = INT_MAX;
				
				dp[0][j] = ans;
			}
		

		FOR(i, 1, n-1)
		{
			REP(j, counts)
			{
				int ans;
				if (arr[i] == s[j])
					ans = 0;
				else if (cc.my_cc(arr[i]) == cc.my_cc(s[j]))
					ans = 1;
				else
					ans = INT_MAX;
				

				dp[i][j] = INT_MAX;

				for (int k = j; k >= 0; k--)
				{
					int ans2;

					if (ans == INT_MAX || dp[i - 1][k]==INT_MAX)
						ans2 = INT_MAX;
					else
						ans2 = dp[i - 1][k] + ans;

					dp[i][j] = min(dp[i][j], ans2);
				}

			}

		}

		int best=INT_MAX;

		REP(j, counts)
		{
			best = min(best, dp[n - 1][j]);
		}

		if (best == INT_MAX)
			cout << -1;
		else
			cout << best;

		cout << "\n";

		

	}

	return 0;
}


