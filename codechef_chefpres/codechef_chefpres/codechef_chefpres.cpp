// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <list>

#include <stack>

#include <deque>
#include <algorithm>

using namespace std;


// dist[101] = { -1 };
class graph;



struct node
{
	int smallest;
	int furthest;
	bool iss;
	bool isf;

	node(int s,int f) :iss(0), isf(0), smallest(s), furthest(f)
	{

	}

};

node* k[101];//= { NULL }; // array of products

int atmynode[10001];
int whichpath[10001];

list<int> *kprod[101] = { NULL };
int smallest[101] = {10002};


void productlist(int product, int nodeno)
{
	if (kprod[product] == NULL)
	{
		kprod[product] = new list < int > ;
		smallest[product] = nodeno;
	}

	kprod[product]->push_front(nodeno);

	if (smallest[product] > nodeno)
		smallest[product] = nodeno;
}


class graph
{

	int V;

public:
	list<int> *adj;
	int* dist;

	graph(int x) :V(x)
	{
		adj = new list<int>[x+1];
		dist = new int[x+1];
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
};


class bfs
{
	int *edgeto;
	bool *marked;
	int s;

public:
	bfs(graph& G, int s) :s(s)
	{
		//edgeto = new int[G.v()];
		marked = new bool[G.v()+1];

		for (int i = 1; i<=G.v(); i++)
			marked[i] = 0;

		breadth_first_search(G, s);
	}

	void breadth_first_search(graph& G, int& s)
	{
		deque<int> q;

		q.push_back(s);

		list<int>::iterator iter;

		while (!q.empty())
		{
			int x = q.front();
			productlist(atmynode[x],x);
			q.pop_front();
			for (iter = (G.adj[x]).begin(); iter != (G.adj[x]).end(); iter++)
			{
				if (!marked[*iter])
				{
					marked[*iter] = 1;
				//	edgeto[*iter] = x;
					q.push_back(*iter);
				}
			}
		}
	}

	void show_bfs(graph& g)
	{
		cout << " bfs from source s " << s;
		cout << endl;
		for (int i = 0; i<g.v(); i++)
		{
			if (i != s)
				cout << " reached edge " << i << " from edge " << edgeto[i];

			cout << endl;
		}

	}

};





inline void addproduct(int city, int prod, graph g)
{
	if (k[prod] == NULL)
	{
		k[prod] = new node(city, city);
	}
	else
	{
		if (city < k[prod]->smallest)
			k[prod]->smallest = city;

		if (g.dist[city]>g.dist[k[prod]->furthest])
			k[prod]->furthest = city;
	}

}





class dfs
{
	int* edgeto;
	bool* marked;
	int s;              // source from depth first search

	void depth_first_search(graph& G, int v,int path,int distance)
	{
		marked[v] = 1;
		productlist(atmynode[v], v);
		G.dist[v] = distance;

		list<int>::iterator iter;

		for (iter = (G.adj[v]).begin(); iter != (G.adj[v]).end(); iter++)
		{
			whichpath[*iter] = path;

			if (!marked[*iter])
			{
				
				depth_first_search(G, *iter,path,distance+1);
		//		edgeto[*iter] = v;
			}

		}

	}


public:


	dfs(graph G)
	{
		marked = new bool[G.v() + 1];
	}

	void dodfs_path(graph& G, int v) // v=b king city
	{
		s = v;

		for (int i = 1; i<=G.v(); i++)
			marked[i] = 0;

		whichpath[v] = -1;

		marked[v] = 1;

		list<int>::iterator iter;
		int path = 1,distance=1;
		for (iter = (G.adj[v]).begin(); iter != (G.adj[v]).end(); iter++)
		{
			G.dist[*iter] = distance;
			//productlist(atmynode[*iter], *iter);
			depth_first_search(G, *iter, path,distance);
			path++;
		}

	}

	
	/*void modified_dfs(graph& G, int v, int product)      // s=B king city
	{
		marked[v] = 1;

		list<int>::iterator iter;

		for (iter = (G.adj[v]).begin(); iter != (G.adj[v]).end(); iter++)
		{
			if (k[product]->iss && k[product]->isf)
				break;

			if (*iter == s)
			{
				marked[*iter] = 1;
			}
			else if(!marked[*iter])
			{

				if (*iter == k[product]->smallest)
					k[product]->iss = 1;
				
				if (*iter == k[product]->furthest)
					k[product]->isf = 1;

				modified_dfs(G, *iter, product);
			}

		}

	}



	void calcity(graph& G,int chefcity,int product)
	{
		for (int i = 1; i <= G.v(); i++)
			marked[i] = 0;
		
		modified_dfs(G, chefcity, product);

	}


	void caldist(graph& G, int B)
	{
		s = B;
		for (int i = 1; i<=G.v(); i++)
			marked[i] = 0;

		G.dist[B] = 0;

		//marked[B] = 1;

		depth_first_search(G, s,1);

	}

	*/


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


int getanswer(int product)
{
	node *t = k[product];

	int x = 0;   // 0 if return smallest 1 if return furthest
	
	if (t->iss&&t->isf)
	{
		x = 1;
	}
	else if (t->iss == 0 && t->isf == 0)
		x = 0;

	else if (t->iss)
		x = 0;

	else
		x = 1;

	t->iss = 0;
	t->isf = 0;

	if (x)
		return t->furthest;
	else
		return t->smallest;
}

struct sorting
{
	graph* g;
	sorting(graph* g2)
	{
		g = g2;
	}

	bool operator () (int i, int j)
	{
		if (g->dist[i] == g->dist[j])
		{
			return j > i;
		}
		else
		{
			return g->dist[i] > g->dist[j];
		}
	}

};
void sorting_list(graph& g)
{
	for (int i = 1; i < 101; i++)
	{
		if (kprod[i] != NULL)
		{
			(*kprod[i]).sort(sorting(&g));
		}
	}

}


int _tmain(int argc, _TCHAR* argv[])
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, b,x, q,u,v,product,chefcity;

	cin >> n >>x >> b;

	

	graph g(n);
		

	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		g.addedge(u, v);

	}
//	df.caldist(g, b);

	for (int i = 1; i <= n; i++)   // product being sold in the city i==city
	{
		cin >> product;
		atmynode[i] = product;
	}

	dfs df(g);
	df.dodfs_path(g, b);


//	bfs bf(g, b);

	sorting_list(g);

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		cin >> chefcity >> product;

		if (kprod[product] == NULL)
			cout << -1;
		else
		{
			if (chefcity == b)
				cout << smallest[product];

			else
			{
				list<int>::iterator iter;

				for (iter = (*kprod[product]).begin(); iter != (*kprod[product]).end(); iter++)
				{
					if (whichpath[*iter] == whichpath[chefcity])
					{
						cout << *iter; break;
					}
				}

				if (iter == (*kprod[product]).end())
					cout << smallest[product];

			}

		}

		cout << "\n";
	}


	return 0;
}

