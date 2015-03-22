// spoj_CORNET.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef long long int LL;

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL);

#define DRT() int test_case; cin>>test_case;while(test_case--)

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)


#define MAX 20000
//#include <bits/stdc++.h>

using namespace std;


int p[MAX + 1], sum[MAX + 1];


void makenode(int x)
{
	p[x] = x;
	sum[x] = 0;
}

int root(int x)
{
	if (x != p[x])
	{
		int i = p[x];

		p[x] = root(x);

		sum[x] += sum[i];
	}

	return p[x];
}

	
int find(int x)
{
	return root(x);
}

void Union(int u, int v)
{
	p[u] = v;

	sum[u] = abs(u - v) % 1000;
}


int _tmain(int argc, _TCHAR* argv[])
{
	inp_s; cinnull;

	int t, u, v,n;
	char ch;

	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
			makenode(i);



		while (1)
		{
			cin >> ch;

			if (ch == 'O')
				break;

			if (ch == 'E')
			{
				cin >> u;

				find(u);

				cout << sum[u] << "\n";

			}

			if (ch == 'I')
			{
				cin >> u >> v;

				if (find(u) != find(v))
				{
					Union(u, v);
				}

			}

		}

	}


	return 0;
}

