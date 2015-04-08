// CSEQ.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <string>

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

int nmax = 10000;
int dp[10001][10001];
int mod = 1000003;


int main()
{
	inp_s; cinnull;

    #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);

	

	FOR(i, 0, nmax)
		dp[i][0] = 1;

	FOR(i, 1, nmax)
		dp[0][i] = 0;


	FOR(i, 1, nmax)
	{
		FOR(j, 1, nmax)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] ) % mod;
		}
	}

	

	cout << "done";

	return 0;
}

