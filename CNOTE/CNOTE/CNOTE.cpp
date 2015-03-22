// CNOTE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)


//#include <bits/stdc++.h>

typedef long long int LL;


#define DRT() int test_case; cin>>test_case;while(test_case--)

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int _tmain(int argc, _TCHAR* argv[])
{
	inp_s; cinnull;

	int t, x,y,n, k, p, c;


	cin >> t;
	
	while (t--)
	{
		cin >> x >> y >> k >> n;
		
		int req = x - y;

		bool ans = 0;
		
		if (req <= 0)
		{
			ans = 1;
		}

		while (n--)
		{
			cin >> p >> c;

			if (p >= req && c <= k)
				ans = 1;

		}

		if (ans == 1)
			cout << "LuckyChef";
		else
			cout << "UnluckyChef";

		cout << "\n";
	}


	return 0;
}

