// jancook15_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>


typedef long long int LL;

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL);

#define DRT() int test_case; cin>>test_case;while(test_case--)

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)


#define MAX 20000
//#include <bits/stdc++.h>

using namespace std;

bool comp(const int a, const int b)
{
	return a > b;

}

int main()
{
	inp_s; cinnull;

	int t, n, arr[1001];

	int sum;

	cin >> t;

	while (t--)
	{
		cin >> n;

		sum = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		sort(arr, arr + n,comp);

		int i = 0;bool flag = 1;
		while (i < n)
		{
			if (flag)
			sum += arr[i];
			i++;
			if (i < n)
			{
				if (flag)
				sum += arr[i];
				i++;
			}
		
			flag = !flag;
		}

		cout << sum << "\n";
	}


	return 0;
}

