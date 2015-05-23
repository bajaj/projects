// HackerEarth_Zopper.cpp : Defines the entry point for the console application.
//

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

LL max(LL a, LL b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
LL upper[1000005], lower[1000005], L;

int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	

	DRT()
	{
		cin >> L;

		upper[0] = 0;

		LL ans = 0;

		FOR(i, 1, L - 1)
		{
			cin >> upper[i];
		}
		FOR(i, 1, L - 1)
		{
			cin >> lower[i];
		}

		FOR(i, 1, L - 1)
		{
			LL rem = L - i;

			if (upper[i] > rem)
				upper[i] -= rem;
			else
				upper[i] = 0;

			if (lower[i] > rem)
				lower[i] -= rem;
			else
				lower[i] = 0;

			ans = max(ans,max(lower[i], upper[i]));
		}

		ans += L;

		cout << ans << "\n";

	}


	return 0;
}

