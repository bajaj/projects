// codechef_chefstone.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include <cstdio>

#include <math.h>

#define gc getchar_unlocked
using namespace std;

//const 

inline unsigned int left(unsigned int i)
{
	return (i << 1);
}

inline unsigned int right(unsigned int i)
{
	return (i << 1) + 1;
}

inline unsigned int parent(unsigned int i)
{
	return i >> 1;
}

inline unsigned int gcd(unsigned int a, unsigned int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}

	return a;
}

unsigned int gcd_recursive(unsigned int a, unsigned int b)
{
	if (b)
		return gcd_recursive(b, a % b);
	else
		return a;
}


void process(unsigned int* arr, unsigned int* segment, unsigned int s, unsigned int e, unsigned int node)
{

	if (s == e)
		segment[node] = arr[s];
	else
	{
		process(arr, segment, s, (s + e) / 2, left(node));
		process(arr, segment, (unsigned int)((s + e) / 2) + 1, e, right(node));

		segment[node] = gcd(segment[left(node)], segment[right(node)]);

	}

}

unsigned int query(unsigned int* segment, unsigned int s, unsigned int e, unsigned int node, unsigned int l, unsigned int r)
{
	unsigned int p1, p2;

	if (l > e || r < s)
		return 0;

	if (s >= l && e <= r)
		return segment[node];


	p1 = query(segment, s, (s + e) / 2, left(node), l, r);
	p2 = query(segment, (unsigned int)(s + e) / 2 + 1, e, right(node), l, r);

	if (p1 == 0)
		return p2;

	if (p2 == 0)
		return p1;

	return gcd(p1, p2);

}

void scanint(unsigned int &x)
{
	register unsigned int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	unsigned int t, n, q, l, r, arr[100001], g, l1, r1, l2, r2,forw[100001],back[100001];
	int x;

//	unsigned int *segment=new unsigned int[262145];

	cin >> t;

	while (t--)
	{
		cin >> n >> q;

		scanint(arr[1]);
		forw[1] = arr[1];


		for (unsigned int i = 2; i <= n; i++)
		{
			//cin >> arr[i]; 
			scanint(arr[i]);
			forw[i] = gcd_recursive(arr[i], forw[i - 1]);
		}

		back[n] = arr[n];


		for (unsigned int i = n-1; i >=1; i--)
		{
			back[i] = gcd_recursive(arr[i], back[i + 1]);
		}


		//process(arr, segment, 0, n - 1, 1);

		for (unsigned int j = 0; j < q; j++)
		{
			//cin >> l >> r;
			scanint(l); scanint(r);

		//	l = l - 1; r = r - 1;

			if (l == 1)
			{
				//g = query(segment, 0, n - 1, 1, r + 1, n - 1);
				g = back[r + 1];
			}
			else if (r == n)
			{
				//g = query(segment, 0, n - 1, 1, 0, l - 1);
				g = forw[l - 1];
			}
			else
			{
				//g = gcd(query(segment, 0, n - 1, 1, 0, l - 1), query(segment, 0, n - 1, 1, r + 1, n - 1));
				g = gcd_recursive(forw[l - 1], back[r + 1]);
			}

			cout << g << "\n";

			// printf(" %d \n",g);

		}


	}


	return 0;
}