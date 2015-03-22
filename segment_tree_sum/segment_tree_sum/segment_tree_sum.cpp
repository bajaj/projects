// segment_tree_sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "iostream"

using namespace std;

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

void swap(int arr[], int i, int j)
{
	int temp = arr[i];

	arr[i] = arr[j];
	arr[j] = temp;

}

void build(int *s, int *arr, int l, int r, int node)
{
	if (l == r)
	{
		s[node] = arr[l];
	}
	else
	{
		int mid = (l + r) / 2;
		build(s, arr, l, mid, left(node));
		build(s, arr, mid + 1, r, right(node));

		s[node] = s[left(node)] + s[right(node)];
	}
}

int getSum(int *s, int i,int j,int l, int r, int node)
{
	if (i > r || j < l)
		return 0;

	if (l >= i && r <= j)
		return s[node];

	int mid = (l + r) / 2;
	return getSum(s, i, j, l, mid, left(node)) + getSum(s, i, j, mid + 1, r, right(node));

}

void modify(int *s, int *arr, int p,int x, int l, int r, int node)
{
	s[node] += x - arr[p];

	if (r - l < 1)
	{
		arr[p] = x;
		return;
	}

	int mid = (l + r) / 2;

	if (p>mid)
	{
		modify(s, arr, p, x, mid + 1, r, right(node));
	}
	else
		modify(s, arr, p, x, l, mid, left(node));
}

void upd(int *lazy,int *s,int l,int r,int x,int node) // increase all members in this interval by x
{
	lazy[node] += x;

	s[node] += ((r - l) + 1)*x;

}


void passchildren(int *lazy, int *s, int l, int r, int node)
{

	int mid = (l + r) / 2;

	upd(lazy, s, l, mid, lazy[node],left(node));

	upd(lazy, s, mid + 1,r,lazy[node], right(node));

	lazy[node] = 0;

}

void increase(int *lazy, int *s, int i, int j, int l, int r, int x,int node)
{
	if (i > r || j < l)
		return;

	if (l >= i && r <= j)
	{
		upd(lazy, s, l, r, x, node);
		return;
	}

	passchildren(lazy, s, l, r, node);

	int mid = (l + r) / 2;

	increase(lazy, s, i, j, l, mid, x, left(node));
	increase(lazy, s, i, j, mid + 1, r, x, right(node));

	s[node] = s[left(node)] + s[right(node)];
}

int getLazySum(int *lazy, int *s, int i, int j, int l, int r, int node)
{
	if (i > r || j < l)
		return 0;

	if (l >= i && r <= j)
	{
		return s[node];
	}
	passchildren(lazy, s, l, r, node);

	int mid = (l + r) / 2;

	return getLazySum(lazy, s, i, j, l, mid, left(node)) + getLazySum(lazy, s, i, j, mid + 1, r,right(node));
}



int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cin >> n;

	int *arr = new int[n+1];

	cout << "enter n elements \n";

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int segsize=2 * pow(2, (int)ceil(log2(n)));

	int *s = new int[segsize+1];

	int *lazy = new int[segsize + 1];

	for (int i = 1; i <= segsize; i++)
	{
		lazy[i] = 0; s[i] = 0;
	}

	build(s, arr, 1, n, 1);

	//cout << getSum(s,2, 4,1,n,1)<<" modify"<<"\n ";

//	modify(s, arr, 4, 45, 1, n, 1);

//	cout << getSum(s,2, 4, 1, n, 1) << "\n ";

	increase(lazy, s, 1, 4, 1, n, 45, 1);

	cout << getLazySum(lazy, s, 1, 5, 1, n, 1);

	return 0;
}

