// MergeSort2.cpp : Defines the entry point for the console application.
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

int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

LL inv = 0;
LL arr[200001],aux[200001];


void merge(int left, int mid, int right)
{
	LL len = right - left + 1;


	for (int i = left,j=0; i <= right; i++,j++)
		aux[j] = arr[i];
	
	int leftCount = mid - left + 1;
	
	int l = 0;
	int r = leftCount;
	int index = left;

	while (l < leftCount && r < len)
	{
		if (aux[l]>aux[r])
		{
			arr[index++] = aux[r++];
			inv += leftCount - l;
		}
		else
			arr[index++] = aux[l++];
	}

	while (l < leftCount)
		arr[index++] = aux[l++];
	

	while (r < len)
		arr[index++] = aux[r++];
}

void mergeSort(int left, int right)
{
	int mid = (left + right) / 2;

	if (right > left)
	{
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}

	

}

int main()
{
		inp_s; cinnull;

		#pragma warning (disable : 4996)
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);

		int n;
		int space;
		DRT()
		{
			inv = 0;
			cin >> n;
			rdarr(arr, n);
			mergeSort(0, n - 1);

			cout << inv<<"\n";
		}

	return 0;
}

