// divideto3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
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

int ans, n,arr[12],ptr;

void set(int s1, int s2, int s3, int ptr)
{
	if (ptr == n)
	{
		int mini = max(max(s1, s2), s3);

		if (ans > mini)
		{
			ans = mini;
		}

	}
	else
	{

		set(s1 + arr[ptr], s2, s3,ptr+1);
		set(s1, s2 + arr[ptr], s3, ptr + 1);
		set(s1, s2, s3 + arr[ptr], ptr + 1);
	}


}




int main()
{
	inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int sum = 0, avg; ans = 10000;
	ptr = 0;

	cin >> n;

	int maxi=0;

	REP(i, n)
	{
		cin >> arr[i];
		sum += arr[i];

		maxi = max(arr[i], maxi);
	}

	int dp[1201] = { 0 };

	avg = ceil(sum / 3.0);

	dp[0] = 1;

	REP(i, n)
	{
		for (int j = 1200 - arr[i]; j >= 0;j--)
		{
			if (dp[j])
			{
				dp[j + arr[i]] = 1;
			}
		}

	}
	int S1;
	FOR(j, 0, 1200)
	{
		if (dp[j])
		{
			if (j >= avg)
			{
				S1 = j;
				break;
			}
		}

	}



	cout << S1;

	return 0;
}

