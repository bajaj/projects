// 10653.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

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

int ri[] = { -1, 1, 0, 0 };   
int ci[] = { 0, 0, 1, -1 };

int mat[1001][1001];

#define maxi 5000

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);

	int r, c;

	while (1)
	{
		cin >> r >> c;

		if (r == 0 && c == 0)break;

		REP(i, r)
			REP(j, c)
			mat[i][j] = maxi;

		int rbomb;
		cin >> rbomb;

		REP(i, rbomb)
		{
			int rno, nobomb;
			cin >> rno >> nobomb;
				
			REP(j, nobomb)
			{
				int colno;
				cin >> colno;

				mat[rno][colno] = -1;
			} 
		}
		int sr, sc, er, ec;
		cin >> sr >> sc >> er >> ec;

		mat[sr][sc] = 0;

		queue< pair<int, int> > q;

		q.push(ii(sr, sc));

		while (!q.empty())
		{
			ii pi = q.front(); 
			q.pop();

			bool flag = 0;

			REP(i, 4)
			{
				int newr = pi.first + ri[i];
				int newc = pi.second + ci[i];

				if (newr >= 0 && newr < r && newc >= 0 && newc < c)
				{
					if (mat[newr][newc] != -1 && mat[newr][newc] == maxi)
					{
						mat[newr][newc] = mat[pi.first][pi.second] + 1;

						if (newr == er && newc == ec)
						{
							flag = 1;
							break;
						}

						q.push(ii(newr, newc));

					}

				}


			}

		}

		cout << mat[er][ec] << "\n";

	}

	


	return 0;
}

