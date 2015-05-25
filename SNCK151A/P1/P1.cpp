// P1.cpp : Defines the entry point for the console application.
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

int arr[55];

bool comp(const int a, const int b)
{
	return arr[b]<arr[a];
}


int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int cnt = 1;
	DRT()
	{
	//	cout << "case " << cnt << " ";
		//cnt++;
		int n; int ans[55] = { 0 };

	//	int sortedIndex[55];
		int b[51];
		int bcnt = 0;

		cin >> n;

//		REP(i, n)
	//		sortedIndex[i] = i;

		bool flag = 1;   // possible

		int sum = 0;

		REP(i, n)
		{
			cin >> arr[i];

			if (arr[i] >= n)
				flag = 0;         // not possible

			sum += arr[i];

		}

	//	sort(sortedIndex, sortedIndex + n, comp);


		if (sum != n)
			flag = 0;

		if (n == 1 && sum == 0)
		{
			cout << -1 << "\n";
			continue;
		}


		if (flag)
		{
			REP(i, n)
			{
				int j = (i + 1) % n;

				int x = arr[i];

				while (x != 0)
				{
					if (!ans[j])
					{
						ans[j] = i+1;
						x--;
					}
					j = (j + 1) % n;
				}
						
			}

			REP(i, n)
			{
				if (ans[i] == i+1)
					b[bcnt++] = i;
			}


			if (bcnt == 1)
			{
				REP(i, n)
				{
					if (ans[i] !=ans[b[0]])
					{
						int temp = ans[i];
						ans[i] = ans[b[0]];
						ans[b[0]] = temp;
						break;
					}
				}

			}
			else
			{
				REP(i, bcnt)
					ans[b[i]] = ans[b[(i + 1) % bcnt]];
			}

			REP(i, n)
			{
				cout << ans[i];

				if (i == n - 1);
				else
					cout << " ";

			}

		}
		else
		{
			cout << -1;
		}
		//	cnt++;

		cout << "\n";
	}

	



	return 0;
}
