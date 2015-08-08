// GRGUY.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// codechef_Aug_2015.cpp : Defines the entry point for the console application.
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

typedef unsigned long long LL;

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

#define maxi 10000000

string str[2];

int getCount(bool lane,int len)
{
	int count=0,
		pointer=0;
	
	if (str[lane][pointer] == '#')
		return maxi;

	while (pointer < len)
	{
		if (str[lane][pointer] == '.')
			pointer++;
		else
		{
			if (str[!lane][pointer] == '.')
			{
				pointer++; 
				lane = !lane;
				count++;
			}
			else
			{
				count = maxi;
				break;
			}
		}
	}

	return count;
}



int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	DRT()
	{
		cin >> str[0] >> str[1];
		
		int len = str[0].length();

		int count1 = getCount(0,len);
		int count2 = getCount(1, len);

		if (count1 == maxi && count2 == maxi)
			cout << "No" << "\n";
		else
		{
			cout << "Yes" << "\n";
			if (count1 > count2)
				cout << count2;
			else
				cout << count1;

			cout << "\n";
		}

	}

	return 0;
}



