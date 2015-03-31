// twoArraySameBST.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
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

void getSmallBig(int root, int arr[],int len, int& small, int& big)
{
	FOR(i, root, len - 1)
	{
		if (arr[i] < arr[root] && small==-1)
			small = i;
		else if (arr[i] > arr[root] && big==-1)
			big = i;

		if (small != -1 && big != -1)
			break;

	}

}


bool solve(int a[], int b[], int n,int rootA, int rootB)
{
	int as = -1, ab = -1, bs = -1, bb = -1;

	getSmallBig(rootA, a, n, as, ab);
	getSmallBig(rootB, b, n, bs, bb);

	bool left=false,right=false;

	if (as == -1 && bs==-1)
		left = true;

	if (ab == -1 && bb == -1)
		right = true;
	
	if (!left)
	{
		if (a[as] == b[bs])
			left = solve(a, b, n, as, bs);
		else
			left = false;
	}

	if (!right)
	{
		if (a[ab] == b[bb])
			right = solve(a, b, n,ab, bb);
		else
			right = false;

	}

	return left && right;

}


int main()
{
	inp_s; cinnull;

  #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a[100], b[100];
	int n;

	cout << "enter length of array \n";
	cin >> n;

	REP(i, n)
	{
		cin >> a[i];
	}
	REP(i, n)
	{
		cin >> b[i];
	}

	if (a[0] == b[0])
	{
		if (solve(a, b, n, 0, 0))
			cout << "SAME";
		else
			cout << "not same";

	}
	else
	{
		cout << "NOT SAME";
	}


	return 0;
}