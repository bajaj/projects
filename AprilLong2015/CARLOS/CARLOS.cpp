// CARLOS.cpp : Defines the entry point for the console application.
//

// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <list>

#include <stack>

#include <deque>

using namespace std;


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

typedef long long int LL;


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)


#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a, int b)
{
	return a>b ? a : b;
}

#define INT_MAX 2147483647 


int min(int a, int b)
{
	return a > b ? b : a;
}


int arr[200001];
int dp[200001][201];
int s[201];
int M[201];
int id[201];
int mini[201];
int m;

bool find(int p, int q)
{
	return id[p] == id[q];
}

void unite(int p, int q)
{
	int pid = id[p];

	REP(i, m + 1)
	{
		if (id[i] == pid)
			id[i] = id[q];
	}

}

int main()
{
	inp_s; cinnull;

    #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int  k, n;

	DRT()
	{
		REP(i, 201)
		{
			M[i] = 0;
			id[i] = i;
		}

		cin >> m >> k >> n;

	//	graph g(m + 1);
		int counts = 0; // no of different letter in 

		REP(i, k)
		{
			int x, y;
			cin >> x >> y;
			
		//	g.addedge(x, y);
			unite(x, y);

			M[x] = 1;
			M[y] = 1;

		}

		
		REP(i, n)
		{
			cin >> arr[i];
			M[arr[i]]= 1;
		}

		REP(i, 201)
		{
			if (M[i])
				s[counts++] = i;
		}

	//	connected_components cc(g);
		
//		cc.my_cc(1);

		//int mini=0;
	//	int minino = INT_MAX;

		mini[0] = INT_MAX;

			REP(j, counts)
			{
				int ans;

				if (arr[0] == s[j])
					ans = 0;
				else if (find(arr[0],s[j]))
					ans = 1;
				else
					ans = INT_MAX;
				
				dp[0][j] = ans;

				if (j == 0)
					mini[j] = dp[0][j];
				else
					mini[j] = min(mini[j - 1], dp[0][j]);

			}
		

		FOR(i, 1, n-1)
		{
			REP(j, counts)
			{
				int ans,ans2;

				if (arr[i] == s[j])
					ans = 0;
				else if (find(arr[i], s[j]))
					ans = 1;
				else
					ans = INT_MAX;
				

				dp[i][j] = INT_MAX;

				if (ans == INT_MAX || mini[j] == INT_MAX)
					ans2 = INT_MAX;
				else
					ans2 = ans + mini[j];

				dp[i][j] = ans2;

				if (j == 0)
					mini[j] = dp[i][j];
				else
					mini[j] = min(mini[j - 1], dp[i][j]);

				/*for (int k = j; k >= 0; k--)
				{
					int ans2;

					if (ans == INT_MAX || dp[i - 1][k]==INT_MAX)
						ans2 = INT_MAX;
					else
						ans2 = dp[i - 1][k] + ans;

					dp[i][j] = min(dp[i][j], ans2);
				}*/

			}

		}

		int best=INT_MAX;

		REP(j, counts)
		{
			best = min(best, dp[n - 1][j]);
		}

		if (best == INT_MAX)
			cout << -1;
		else
			cout << best;

		cout << "\n";

		

	}

	return 0;
}


