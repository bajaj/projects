// P3.cpp : Defines the entry point for the console application.
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

typedef long long int LL;


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

LL a[100001];

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	DRT()
	{
		int n;
		cin >> n;
		int minCount = 0,maxCount=0;

		REP(i, n)
		{
			cin >> a[i];
		}

		sort(a, a + n);

		int i = 0;

		while (i < n)
		{
			if ((i + 1 < n) && a[i] == a[i + 1] - 1)
			{
				if ((i + 2 < n) && a[i + 1] == a[i + 2] - 1)
					i += 3;
				else
					i += 2;
			}
			else
				i++;
		
			minCount++;
		}
	
		i = 0;


		while (i < n)
		{
			if ((i + 1 < n) && a[i] == a[i + 1] - 1)			
					i += 2;
			else
				i++;

			maxCount++;
		}

		cout << minCount <<" "<<maxCount<< "\n";

	}


	return 0;
}

