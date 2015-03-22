// deepu_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "algorithm"
#include "utility"
#include "math.h"
#include "vector"


using namespace std;

#define MAX 100005

#define segsize 2 * pow(2, (int)ceil(log2(MAX)))

int arr[MAX];

int s[4 * MAX];
int lazy[4*MAX];

inline int parent(int i)
{
	return i >> 1;

}

inline int left(int i)
{
	return i << 1;
}

inline int right(int i)
{
	return (i << 1) + 1;

}

int min(int a, int b)
{
	return a > b?b : a;

}

void build(int l, int r, int node)
{
	if (l == r)
	{
		s[node] = arr[l];
		return;
	}

	int mid = (l + r) / 2;

	build(l, mid, left(node));
	build(mid + 1, r, right(node));

	s[node] = min(s[left(node)] , s[right(node)]);

}

void upd(int l, int r,int t,int node)
{
	lazy[node] += t;

	s[node] -= t;
}

void passchildren(int l, int r, int node)
{
	if (l != r)
	{
		int mid = (l + r) / 2;
		upd(l, mid, lazy[node], left(node));
		upd(mid + 1, r, lazy[node], right(node));
	}
	lazy[node] = 0;
}

void decrease(int l, int r, int node, int x,int t)
{
	passchildren(l, r, node);

	if (s[node]>x)
	{
		upd(l, r, t, node);

		if (lazy[node]!=0)
		passchildren(l, r, node);

		if (l!=r)
		s[node] = min(s[left(node)], s[right(node)]);

		return;
	}

	if (l==r) return;

	int mid = (l + r) / 2;
	decrease(l, mid, left(node), x, t);
	decrease(mid + 1, r, right(node), x, t);

	s[node] = min(s[left(node)], s[right(node)]);

}


void final_segupdate(int l, int r, int node,vector<pair<int,int> >& v )
{
	if (l == r & l!=0 )
	{
		v[v[l].second].first = s[node];
		return;
	}

	passchildren(l, r, node);

	int mid = (l + r) / 2;
	final_segupdate(l, mid, left(node),v);
	final_segupdate(mid + 1, r, right(node),v);
}



int _tmain(int argc, _TCHAR* argv[])
{
	//cout << "cool";

	int t, m, x,n;

	cin >> n;
	vector<pair<int, int> > v(100005);

	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		v[i]=make_pair(x, i);
	}

	memset(lazy, 0, sizeof lazy);

	sort(v.begin()+1,v.begin()+1+n);			

	for (int i = 1; i <= n; i++)
	{
		arr[i] = v[i].first;
	}

	build(1, n, 1);
	
	cin >> m;

	while (m--)
	{
		cin >> x;
		decrease(1, n, 1, x, 1);
	}

	final_segupdate(1, n, 1, v);
	
	for (int i = 1; i <= n; i++)
	{
		cout<<" "<<v[i].first;
	}

	
	return 0;
}

