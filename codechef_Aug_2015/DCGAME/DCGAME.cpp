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
#include <map>
#include <unordered_map>


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

pair<LL, LL> arr[1000005];
pair<LL, LL> arr2[1000005];

LL counti[1000005];

void populateCount(int point)
{
	counti[0] = 0;
	FOR(i, 1, point)
		counti[i] = arr2[i].second + counti[i - 1];

}

int binarySearch(LL k,int size)
{
	int low = 1,high = size,mid;
	int index = -1;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (arr2[mid].first == k)
		{
			index = mid;
			break;
		}

		if (arr2[mid].first > k)
			high = mid - 1;
		else
			low = mid + 1;

	}

	if (index == -1)
		return low;
	else
		return index;

}

int removeDuplicates(int n)
{
	int j = 1;
	FOR(i, 1, n)
	{
		if (arr[i].first == arr[i - 1].first)
			arr2[j-1].second += arr[i].second;
		else
			arr2[j++] = arr[i];
		
	}
	return j;
}

//#include <windows.h>

int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n>>m;

	LL point = 1,x,value;
	
	//DWORD dw1 = GetTickCount();
	// do something
	
	FOR(i,1,n)
	{
		cin >> arr[i].first;
		arr[i].second = 1;
		
		if (arr[i].first >= arr[i - 1].first)
			arr[i].second += arr[i - 1].second;		
	}

	sort(arr+1, arr+n);

	int no=removeDuplicates(n);

	point = no - 1;
	populateCount(point);

	char comp,
		player;
	LL k;
	

	REP(i, m)
	{
		cin >> comp >> k >> player;

		int index = binarySearch(k, point);
		LL Nocount = 0;

		if (comp == '=')
		{
			if (arr2[index].first == k)
				Nocount = counti[index]-counti[index-1];
			else
				Nocount = 0;
		}
		else if (comp == '>')
		{
			if (arr2[index].first <= k)
				Nocount = counti[point] - counti[index];
			else
				Nocount = counti[point]- counti[index - 1];
		}
		else if (comp == '<')
		{
			if (arr2[index].first >= k)
				Nocount = counti[index-1];
			else
				Nocount = counti[index];
		}

		if (Nocount % 2 == 0)  //even
		{
			if (player == 'D')
				cout << 'C';
			else
				cout << 'D';
		}
		else
			cout << player;
	}

//	DWORD dw2 = GetTickCount();
	//cout << "Time difference is " << (float)(dw2 - dw1) / 1000 << " Seconds" << endl;

	return 0;
}



