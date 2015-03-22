// segment_tree.cpp : Defines the entry point for the console application.
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


void process(int node, int b, int e, int *arr, int *m)
{

	if (b == e)
		m[node] = b;

	else
	{
		process(left(node), b, (b + e) / 2, arr, m);
		process(right(node), (int)((b + e) / 2) + 1, e, arr, m);


		if (arr[m[left(node)]] <= arr[m[right(node)]])
			m[node] = m[left(node)];
		else
			m[node] = m[right(node)];

	}



}


int query(int node, int b, int e, int *arr, int* m, int i, int j)
{
	int p1,p2;


	if (i>e || j < b)
		return -1;


	if (b >= i && e <= j)
		return m[node];


	p1 = query(left(node), b, (b + e) / 2, arr, m, i, j);

	p2 = query(right(node), (int)((b + e) / 2) + 1, e, arr, m, i, j);


	if (p1 == -1)
		return p2;

	if (p2 == -1)
		return p1;

	if (arr[p1]>=arr[p2])
		return p2;
	else
		return p1;

}



int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cin >> n;

	int *arr = new int[n+1];

	int segsize = 2 * pow(2, (int)ceil(log2(n)));

	int *m = new int[segsize+1];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	process(1, 0, n - 1, arr, m);


	int ind = query(1, 0, n - 1, arr, m, 4,7);

	cout << "\n" << arr[ind];


	return 0;
}

