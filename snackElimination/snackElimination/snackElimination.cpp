// snackElimination.cpp : Defines the entry point for the console application.
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


LL pre_hash[100001], suff_hash[100001];

int a[150];

vii str(30);

#define very_large_prime 1000007

/* Calculates the Forward hash of substring [i,j] */
unsigned long long CalculateHash(int i, int j)
{
	if (i>j)
		return -1;
	unsigned long long ret = pre_hash[j] - pow(very_large_prime, 2 * (j - i + 1))*pre_hash[i - 1];
	return ret;
}
/* Calculates the reverse hash of substring [i,j] */
unsigned long long CalculateHash_Reverse(int i, int j)
{
	unsigned long long ret = suff_hash[j] - pow(very_large_prime, 2 * (j - i + 1))*suff_hash[i - 1];
	return ret;
}

int main()
{
	inp_s; cinnull;

    #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string s;
	cin >> s;

	int diff = 0;


	REP(i, s.length())
	{
		a[(int)s[i]]++;
	}

	int xx = 1;

	str[0].first = (char)3;
	str[0].second = 4;

	FOR(i, 97, 125)
	{
		if (a[i] != 0)
		{
			str[xx].first = (char)i;
			str[xx].second = a[i];
			xx++;
			diff++;
		}
	}

	pre_hash[0] = 0;
	for (int i = 1; i <= diff; i++)
	{
		pre_hash[i] = pre_hash[i - 1] * very_large_prime + str[i].first;
		pre_hash[i] = pre_hash[i] * very_large_prime + str[i].second;
	}

	/* Computing the Suffix Hash Table */
	suff_hash[0] = 0;
	for (int i = 1; i <= diff; i++)
	{
		suff_hash[i] = suff_hash[i - 1] * very_large_prime + str[diff - i + 1].first;
		suff_hash[i] = suff_hash[i] * very_large_prime + str[diff - i + 1].second;
	}

	int i, j, k, l;
	
	DRT()
	{
		cin >> i >> j >> k >> l;

		bool a, b,intersect=0,small,end,ans=0;

		a = (CalculateHash(i, j) == CalculateHash_Reverse(i, j));
		b = (CalculateHash(k, l) == CalculateHash_Reverse(k, l));

		if (i >= k && i <= l)
			intersect = 1;

		if (j >= k && j <= l)
			intersect = 1;

		if (intersect)
		{
			if (i > k)
				small = k;
			else
				small = i;

			if (j > l)
				end = j;
			else
			end = l;

			ans = (CalculateHash(small, end) == CalculateHash_Reverse(small, end));

		}
		else
		{
			ans = b;
		}

		if (ans)
			cout << "NO";
		else
			cout << "YES";
		
		cout << "\n";

	}



	return 0;
}

