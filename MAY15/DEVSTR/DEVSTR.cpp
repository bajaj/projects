// DEVSTR.cpp : Defines the entry point for the console application.
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


char arr[100001];
char rarr[100001];

//int cnt[100000][2];
	
int cnt[100000];

int n,k;

void getCount(int& operation,char a[])
{
	int i = 0;

	cnt[i] = 1;
	i++;

	while (i < n)
	{
		if (a[i] == a[i - 1])
			cnt[i] = cnt[i - 1]+1;
		else cnt[i] = 1;

		if (cnt[i] > k)
		{
			operation += 1;

			int j;

			if (k == 1 || (i!=n-1 && arr[i]==arr[i+1]))
				j = i;
			else
				j = i - 1;

			if (a[j] == '0')
				a[j] = '1';
			else
				a[j] = '0';

			cnt[i] = 1;
		}

		i++;
	}
}

int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	DRT()
	{
		cin >>n>>k;

		REP(i, n)
		{
			cin >> arr[i];
			rarr[n - i - 1] = arr[i];
		}
		
		arr[n] = 0;
		rarr[n] = 0;

	//	cnt[0][0] = 0;
	//	cnt[0][1] = 0;

		int operation=0,Roperation=0;

	//	cnt[i][arr[i]] = 1;

		if (k != 1)
		{
			getCount(operation, arr);
			getCount(Roperation, rarr);

			if (operation <= Roperation)
				cout << operation << "\n" << arr;
			else
			{
				cout << Roperation << "\n";

				REP(i, n)
					cout << rarr[n - i - 1];

			}
		}
		else
		{
			int a = 0, b = 0;
			char ax[] = { '0', '1' };
			bool flag1 = 0,flag2=1,flag;

			REP(i, n)
			{
				if (ax[flag1] != arr[i])
					a++;
				
				if (ax[flag2] != arr[i])
					b++;

				flag1 = !flag1;
				flag2 = !flag2;
			}

			if (a > b)
			{
				cout << b << "\n";
				flag = 1;
			}
			else
			{
				cout << a << "\n";
				flag = 0;
			}

			REP(i, n)
			{
				cout << ax[flag];
				flag = !flag;
			}

		}


		cout << "\n";
	}


	return 0;
}

