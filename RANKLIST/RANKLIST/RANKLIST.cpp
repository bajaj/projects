// RANKLIST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;


#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)


typedef long long int LL;


#define DRT() int test_case; cin>>test_case;while(test_case--)

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)


int _tmain(int argc, _TCHAR* argv[])
{
	
	LL t,n,s;

	cin >> t;

	while (t--)
	{
		cin >> n >> s;

		s = s - n;
		n--;

		int i = 1;

		for (; i <= n; i++)
		{
			if (s >= i)
				s = s - i;
			else
				break;
		}

		if (i <= n)
			cout << n - i + 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}

