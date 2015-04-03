// AprilLong2015.cpp : Defines the entry point for the console application.
//

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


int main()
{
	inp_s; cinnull;

    #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	DRT()
	{
		int n;
		cin >> n;
		bool arr[100000];
		int count = 0;

		LL a, b;
		
		cin>>a;
		arr[0] = 0;

		

		FOR(i, 1, n - 1)
		{
			cin >> b;

			if (b != a)
			{
				if (arr[i - 1] == 1)
					count++;
				else
					count += 2;

				arr[i - 1] = 1; arr[i] = 1;

			}
			else
				arr[i] = 0;

			a = b;
		}

		cout << count << "\n";

	}


	return 0;
}