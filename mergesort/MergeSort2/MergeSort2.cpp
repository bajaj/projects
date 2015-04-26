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

int inv = 0;

void merge(int left, int mid, int right, int arr[])
{
	int len = right - left + 1;

	int* aux = new int[len];

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
	{
		arr[index++] = aux[l++];
	}



	while (r < len)
		arr[index++] = aux[r++];

	delete aux;

}

void mergeSort(int left, int right, int arr[])
{
	int mid = (left + right) / 2;

	if (right > left)
	{
		mergeSort(left, mid, arr);
		mergeSort(mid + 1, right, arr);
		merge(left, mid, right, arr);
	}

	

}

int main()
{
		inp_s; cinnull;

		#pragma warning (disable : 4996)
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);

		int n;
		int arr[20];

		cin >> n;

		rdarr(arr, n);
	
		mergeSort(0,n-1, arr);

		REP(i, n)
		{
			cout << arr[i] << " ";
			
		}
		cout << "\n" << inv;

	return 0;
}

