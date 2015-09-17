// ANUCBC.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

// Common memset settings
//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr); // to clear array of integers

typedef long long int LL;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;    // graph representation
vector< pair<int, ii> > EdgeList;   // edgeList for kruskal algorithm


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define rdarr(a,n) REP(i,n) cin >> a[i];

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

LL arr[100005];
LL pre[100][2], curr[100][2];

bool sign(LL d)
{
	return d >= 0 ? 0 : 1;
}

void init()
{
	REP(i, 100)
	{
		pre[i][0] = 0;
		pre[i][1] = 0;
		curr[i][0] = 0;
		curr[i][1] = 0;
	}

}

#define mod 1000000009

int n = 3;
int used[3];
int arrr[3] = { 1, 2, 3 };

void printarr(int index, int sz)
{
	if (sz == 0)
	{
		REP(i, n)
			if (used[i])
				cout << " " << arrr[i];
		cout << "\n";
		return;
	}

	if (index == n)
		return;

	used[index] = 1;
	printarr(index + 1, sz - 1);
	used[index] = 0;
	printarr(index + 1, sz);

}


int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	printarr(0, 2);


/*	cout << (-2) % 5<<"\n";

	DRT()
	{
		LL n, q, m;

		cin >> n >> q;
		
		REP(i, n)
			cin >> arr[i];

		REP(ti, q)
		{
			LL no;
			cin >> no;
			init();
			int s = -(no - 1);
			int e = no-1;
			REP(i, n)
			{
				FOR(num, s, e)
				{
					bool indFlag = sign(num);
					LL ind = abs(num);

					if (pre[ind][indFlag] != 0)
					{
						LL sum = (num + arr[i]) % no;
						LL sumFlag = sign(sum);
						curr[abs(sum)][sumFlag] += pre[ind][indFlag];
					}
		
				}
				curr[abs(arr[i]) % no][sign(arr[i])] += 1;

				FOR(num, s, e)
				{
					bool indFlag = sign(num);
					LL ind = abs(num);

				//	if (num == 0 && pre[ind][indFlag] != 0)	
					//	pre[ind][indFlag] += (pre[ind][indFlag] * curr[ind][indFlag]);				
					//else
					pre[ind][indFlag] = (pre[ind][indFlag]+curr[ind][indFlag])%mod;


					curr[ind][indFlag] = 0;
				}

			}

			cout << (pre[0][0] + 1)%mod << "\n";
		}

	}
	*/


	// calculate the timing

	return 0;
}