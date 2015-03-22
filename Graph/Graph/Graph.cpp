// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <list>

#include <stack>

#include <deque>

using namespace std;

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


	graph(int x):V(x)
	{
		adj=new list<int>[x];
	}

	void addedge(int v,int w)
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

        int count =0;
		for(int i=0;i<V;i++)
		{
			count+=adj[i].size();	
		}

		return count/2;
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
	bfs(graph& G,int s):s(s)
	{
		edgeto=new int[G.v()];
		marked=new bool[G.v()];
		
		for(int i=0;i<G.v();i++)
			marked[i]=0;

		breadth_first_search(G,s);
	}

	void breadth_first_search(graph& G,int& s)
	{
		deque<int> q;

		q.push_back(s);

		list<int>::iterator iter;

		while(!q.empty())
		{
			int x=q.front();
			q.pop_front();
			for(iter=(G.adj[x]).begin();iter!=(G.adj[x]).end();iter++)
			{
				if(!marked[*iter])
				{
					marked[*iter]=1;
					edgeto[*iter]=x;
					q.push_back(*iter);
				}
			}
		}
	}

	void show_bfs(graph& g)
	{
		cout<<" bfs from source s "<<s;
		cout<<endl;
		for(int i=0;i<g.v();i++)
		{
			if(i!=s)
				cout<<" reached edge "<<i<<" from edge "<<edgeto[i];

			cout<<endl;
		}

	}

};






class dfs
{
	int* edgeto;
	bool* marked;
	int s;              // source from depth first search

	void depth_first_search(graph& G,int v)
{
	marked[v]=1;

	list<int>::iterator iter;

	for(iter=(G.adj[v]).begin();iter!=(G.adj[v]).end();iter++)
	{
		if(!marked[*iter])
		{
			depth_first_search(G,*iter);

			edgeto[*iter]=v;
		}

	}

}


public:

	dfs(graph& G,int s):s(s)
	{
		edgeto=new int[G.v()];
		marked=new bool[G.v()];
		
		for(int i=0;i<G.v();i++)
			marked[i]=0;

		depth_first_search(G,s);
	}

	bool haspathto(int v)
	{	return marked[v];
	}

	void pathto(int v,stack<int>& stac)
	{
		if(!haspathto(v))
		{
			cout<<" no path to given vertices";
				return;
		}
				
		for(int x=v;x!=s;x=edgeto[x])
					stac.push(x);
		stac.push(s);
		
	}

};






void graph::print_graph()
{
	list<int>::iterator iter;

for(int i=0;i<V;i++)
	{
		for(iter=adj[i].begin();iter!=adj[i].end();iter++)
			cout<<endl<<" "<<i<<" -> "<<(*iter);
    }	
}

int graph::maxdegree()
{
int max=0;
		for(int i=0;i<V;i++)
		{
			if(adj[i].size()>max)
				max=adj[i].size();
		}
		return max;
}

int graph::self_loop()
{
	int count=0;

	list<int>::iterator iter;

	for(int i=0;i<V;i++)
		{
			for(iter=adj[i].begin();iter!=adj[i].end();iter++)
			{
				if(i==(*iter))
					count++;
			}
	}

	return count/2;               // because add_edge(0,0)  will add two 0 to the adj[0]
}

// *****************************************///////

class connected_components
{
	int* marked;
	int* id;
	int count;

public:
	connected_components(graph& g);
	void dfs(graph& g,int s);
	int cout();
	int my_cc(int v);
};

connected_components::connected_components(graph& g):count(0)
{
	marked=new int[g.v()];
	id=new int[g.v()];

	for(int i=0;i<g.v();i++)
	{
		marked[i]=0;
	}
	for(int i=0;i<g.v();i++)
	{
		if(!marked[i])
		{
			dfs(g,i);
			count++;
		}

	}
}

void connected_components::dfs(graph& g,int s)
{
	marked[s]=1;
	list<int>::iterator iter;

	id[s]=count;

	for(iter=(g.adj[s]).begin();iter!=(g.adj[s]).end();iter++)
	{
		if(!marked[*iter])
		dfs(g,*iter);
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

// *********************      **************************//

// ************** detect a cycle in the graph     ****************//

class cycle
{
	int* marked;
	

public:
	bool hascycle;

	cycle(graph& g)
	{
		marked=new int[g.v()];

		for(int i=0;i<g.v();i++)
			marked[i]=0;

		bool *offstack=new bool[g.v()];

		for(int i=0;i<g.v();i++)
		offstack[i]=0;

		stack<int> s;
		
		for(int i=0;i<g.v();i++)
		{
			if(!marked[i])
				dfs(g,i,i,s,offstack);

		}

		delete[] marked;
	}


	void dfs(graph& g,int v,int u,stack<int>& s,bool offstack[])
	{
		marked[v]=1;
		
		s.push(v);

		list<int>::iterator iter;

		for(iter=(g.adj[v]).begin();iter!=(g.adj[v]).end();iter++)
		{
			if(!marked[*iter])
				dfs(g,*iter,v,s,offstack);
	
			else if((*iter)!=u && offstack[*iter]!=1)           // offstack to see whether that element is not on the stack
				{
					hascycle=true;
		
				stack<int> out;

				cout<<endl<<"cycle is   ";

					while(s.top()!=*iter)                     // popping here so that we can print all cycle
						{
							cout<<s.top()<<" -> ";
							out.push(s.top());
								s.pop();
						}
						cout<<s.top();
					
						while(!out.empty())
						{
							s.push(out.top());
							out.pop();
						}

			}	

		}

		
	if(!s.empty())
    {
		offstack[s.top()]=1;
		s.pop();
	}
		

	}


};


int _tmain(int argc, _TCHAR* argv[])
{ 

	graph g(7);

	g.addedge(0,1);
g.addedge(0,6);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(2,4);
	g.addedge(4,5);
	g.addedge(5,6);

	//cout<<*((g.adj[0]).begin());
	g.addedge(4,6);
	//g.addedge(3,1);
//	g.addedge(8,9);




//	cout<<*iter;

	//(void*)0;

	g.print_graph();

	cycle c(g);

	cout << c.hascycle;

//	connected_components cc(g);

//	cout<<"   no of connected components "<<cc.cout();

//	cout<<endl<<"edge 9 is in "<<cc.my_cc(1);

//	bfs b(g,0);

//	b.show_bfs(g);


/*	dfs d(g,0);

	stack<int> s;

	d.pathto(4,s);

	while(!s.empty())
	{
		int x=s.top();
		s.pop();
		cout<<" "<<x<<"->";

	}

*/
	return 0;
}

