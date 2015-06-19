// PALINQUE.cpp : Defines the entry point for the console application.
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

// vector<vii> AdjList;    // graph representation


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


LL dp[5000][5000];
bool palindrome[5000][5000];

int main()
{
	inp_s; cinnull;
//	memset(dp, 0, sizeof dp);
	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str;
	cin >> str;
	int length = str.length();

	REP(i, length - 1)        // for every 2 letter 
	{
		dp[i][i] = palindrome[i][i] = 1;
		palindrome[i][i + 1] = (str[i] == str[i + 1]);

		dp[i][i + 1] = 2 + palindrome[i][i + 1];
	}

	palindrome[length - 1][length - 1] = dp[length-1][length-1]=1;
	
	for (int j = 2; j < length; j++)   // from length 2 to length     
	{
		for (int i = 0; i + j < length; i++)     // starting from every vertex
		{
			int l, r;
			l = i;
			r = i + j;

			palindrome[l][r] = (palindrome[l + 1][r - 1] && (str[l] == str[r]));
			dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l+1][r - 1]+palindrome[l][r];   // inclusion exclusion theorem
		}

	}

	DRT()
	{
		int x, y;
		cin >> x >> y;

		cout << dp[x - 1][y - 1] << "\n";
		
	}


	return 0;
}

