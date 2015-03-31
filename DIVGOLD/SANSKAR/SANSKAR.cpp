// STRBIT.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include  <string>
using namespace std;


#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(n) for(int i=0;i<n;i++)

typedef long long  ll;

ll arr[21];
bool alloc[21] = { 0 };
int n, k;
ll sum = 0;
ll x;

int count = 0;

bool comp(ll a, ll b)
{
	return a > b;
}

bool initialCheck()
{
	if (k > n || sum%k != 0)
		return false;

	x = sum / k;

	if (arr[0] > x)
		return false;

	return true;
		
}

void allocateZero()
{
	REP(n)
	{
		if (arr[i] == 0 || arr[i]==x)
			alloc[i] = 1;
	}
}

bool isAllAllocated()
{
	REP(n)
	{
		if (alloc[i] == 0)
			return false;
	}

	return true;
}

bool solve(ll subset)
{
	if (subset==0 && isAllAllocated())
		return true;

	REP(n)
	{
		if (alloc[i])
			continue;

		if (subset + arr[i] < x)
		{
			subset += arr[i];
			alloc[i] = 1;


			if (solve(subset))
				return true;
			else
			{
				subset -= arr[i];
				alloc[i] = 0;

				if (subset == 0)
					return false;

				continue;
			}

		}
		else if (subset + arr[i] == x)
		{
			alloc[i] = 1;
			return solve(0);
		}
		else
			continue;
	}

	return false;
}


int main()
{
 #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	inp_s;cinnull;

	DRT()
	{
		cin >> n >> k;
		sum = 0;
	
		REP(n)
		{
			cin >> arr[i];
			alloc[i] = 0;
			sum += arr[i];
		}
		
		sort(arr, arr + n, comp);

		if (!initialCheck())
		{
			cout << "no"<<"\n";
			continue;
		}
		allocateZero();
		

		if (solve(0))
		{
			cout << "yes";
		}
		else
		{
			cout << "no";
		}
		cout << "\n";

	}

	return 0;
}

