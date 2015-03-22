// CHEFEQ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
using namespace std;


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

int main()
{
	inp_s; cinnull;

	int t,x,n;

	cin >> t;

	while (t--)
	{
		int ans = 0;
		int arr[100001] = { 0 };

		cin >> n;

		int temp = n;

		while (n--)
		{
			cin >> x;

			arr[x] += 1;

			if (arr[x] > ans)
				ans = arr[x];

		}

		cout << temp - ans << "\n";

	}

	return 0;
}

