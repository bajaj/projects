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



int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);


	DRT()
	{
		int n;
		int arr[20];
		int ans[20];

		cin >> n;

		FOR(i, 1, n)
			cin >> arr[i];

		sort(arr + 1, arr + n + 1);

		int lar = n, sma = 1;
		int temp = n;

		while (lar >= sma)
		{
			ans[temp--] = arr[lar--];

			if (lar >= sma)
				ans[temp--] = arr[sma++];
		}

		int taste = 0;
		for (int i = 2; i <= n; i++){
			if (ans[i] - ans[i - 1] >= 0){
				taste = taste + i*(ans[i] - ans[i - 1]);
			}
			else{
				taste = taste + i*(ans[i - 1] - ans[i]);
			}
		}

		cout << taste << "\n";
	}
	
	


	return 0;
}

