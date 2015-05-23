// CHAPD.cpp : Defines the entry point for the console application.
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

typedef unsigned long long int LL;


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

#define limit 2

bool v[limit];
LL sp[limit];

void sieve()
{
	for (LL i = 2; i <= limit; i += 2)sp[i] = 2;

	for (LL i = 3; i <= limit; i += 2)
	{
		if (!v[i])
		{
			sp[i] = i;

			for (LL j = i; (j*i) <= limit; j += 2)
			{
				if (!v[j*i])
					v[j*i] = 1 , sp[j*i] = i;
			
			}
		}


	}

}

	
LL gcd(LL a, LL b)
{
	while (b)
	{
		return gcd(b, a%b);
	}
	return a;
}


int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	LL a, b,h,y;

	//sieve();

	DRT()
	{
		h = 0;
		cin >> a >> b;

		int flag = -1;


		if (b % 2 == 0 && a % 2 != 0)
			flag = 0;

		if (flag == -1)
		{
			if (a >= b && a%b == 0)
				flag = 1;
		}
		
	/*	if (flag == -1)
		{
			if (b > limit)
				flag = 0;
		}*/


		/*if (flag == -1)
		{
			flag = 1;

			LL spi = sp[b];
			LL c = b;
			while (true)
			{
				if (a%spi != 0)
				{
					flag = 0;
					break;
				}
				
				c = c / spi;

				if (c == 1)
					break;

				spi = sp[c];
				
			}

		}*/
		
		if (flag == -1)
		{

			while (h != 1)
			{
				if (a > b)
					h = gcd(a, b);
				else
					h = gcd(b, a);

				y = b / h;

				a = h;
				b = y;
			}

			if (y > 1)
				flag = 0;
			else
				flag = 1;

		}


		if (flag)
			cout << "Yes";
		else
			cout << "No";

		cout << "\n";
	}


	return 0;
}

