// SETDIFF.cpp : Defines the entry point for the console application.
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

typedef  long long int LL;


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

#define mod 1000000007
#define length 100005

LL values[length];

typedef unsigned long long int uint64;

uint64 PowMod(uint64 x, uint64 e)
{
	uint64 res;

	if (e == 0)
	{
		res = 1;
	}
	else if (e == 1)
	{
		res = x;
	}
	else
	{
		res = PowMod(x, e / 2);
		res = (res * res) % mod;
		if (e % 2)
			res = (res * x) % mod;
	}

	return res;
}


LL powmod(LL base, LL pow)
{
	LL res = 1;
	while (pow)
	{
		if (pow % 2 != 0)  res = (res*base) % mod;
		base = (base*base) % mod;
		pow /= 2;
	}
	return res;
}

void fillPowersof2()
{

	for (int i=0; i < 100001;i++)
		values[i] = powmod(2, i);
	

}


LL arr[100005];

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	fillPowersof2();

	DRT()
	{
		int n;

		LL ans = 0;

		cin >> n;

		REP(i, n)
			cin >> arr[i];
		
		sort(arr, arr + n);

		for (int i = n - 1; i >= 0; i--)
		{
		ans = (ans + ((arr[i] * (values[i] - 1)) % mod)) % mod;

			ans = (ans - ((arr[i] * (values[n - i - 1] - 1)) % mod)) % mod;

		//	ans = ans + (arr[i] * (values[i] - values[n - i - 1])) % mod;

		}

		/*int i = n - 1,j=0;
		ans = 0;
		while (i >= j)
		{

			ans = ans + ((values[i] - 1)*(arr[i] - arr[j])) % mod;
			ans = ans - (values[n - i - 1]-1)*(arr[i] - arr[j]) % mod;
			i--;
			j++;
		}*/

	/*	ans = 0;

		LL prod;

		REP(i, n)
		{
			prod = values[i] - values[n - i - 1];

			prod = arr[i] * prod;

			prod = prod % mod;

			ans += prod;

			ans = ans%mod;
		}
		*/
		cout << ans << "\n";
	}

	return 0;
}

