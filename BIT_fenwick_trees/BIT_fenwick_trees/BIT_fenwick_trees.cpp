// BIT_fenwick_trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#define LSB(S) (S & (-S))
#define SIZE 10


using namespace std;

class BIT
{
	int *tree,size;

public:
	BIT(int n)
	{
		size = n;
		tree = new int[n + 1];

		for (int i = 0; i <= n; i++)
			tree[i] = 0;
	}

	~BIT()
	{
		delete[] tree;
	}

	void update(int x, int val)
	{
		for (; x <= size; x += LSB(x))
			tree[x] += val;
	}

	// return sum of the range [1...x]
	int sum(int x)
	{
		int sum = 0;

		for (; x > 0; x -= LSB(x))
			sum += tree[x];
		return sum;
	}

	// return sum of range [a...b]

	int sum(int a, int b)
	{
		return sum(b) - (a == 1 ? 0 : sum(a - 1));
	}



};



int _tmain(int argc, _TCHAR* argv[])
{
	BIT b(SIZE);

	for (int i = 1; i <= SIZE; i++)
	{
		b.update(i, i);
	}

	for (int i = 1; i <= SIZE; i++)
	{
		cout<<b.sum(i)<<"\n";
	}



	return 0;
}
