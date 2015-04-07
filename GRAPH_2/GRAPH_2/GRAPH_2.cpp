// GRAPH_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "list"
#include "algorithm"

using namespace std;

class Graph;

class Dfs;

// Design decouple the grapg object from the processing of graph routine


class Graph
{
	int V;

	public:
	list<int> *adj;


	Graph(int v):V(v)
	{
		adj = new list<int>[V + 1];             // indexed 1
	}

	void addEdge(int v, int w)                 // for undirected graph
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	static int degree(Graph G,int v)
	{
		return G.adj[v].size();
	}

	int noOfVertices()
	{
		return V;
	}

	void printGraph();

	~Graph()
	{

	}

};


class Dfs
{
private:
	void dfs(int v);
	bool* marked;

public:

	Graph& g;

	Dfs(Graph& gg):g(gg)
	{

	}

	void doDfs()
	{
		int v = g.noOfVertices();
		marked = new bool[v + 1];

		dfs(1);
	}

};


void Dfs::dfs(int v)
{
	marked[v] = 1;

	list<int>::iterator iter;

	for (iter = (g.adj[v]).begin(); iter != (g.adj[v]).end(); iter++)
	{
		if (!marked[*iter])
		{
			dfs(*iter);
			
		}

	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


