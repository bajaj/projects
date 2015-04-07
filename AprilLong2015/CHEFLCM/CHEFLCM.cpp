// CHEFLCM.cpp : Defines the entry point for the console application.
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

typedef unsigned long long UL;

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


//UL arr[200000];
//UL arr2[100000];

int main()
{
	inp_s; cinnull;

 #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	DRT()
	{
		UL n; cin >> n;
		UL sum = 0;

		UL count1 = 0, count2 = 0;
		
		//int sqrtN = sqrt(n);

		for (int i = 1; i <= sqrt(n); i++)
		{
			if (n%i == 0)
			{
				sum += i;
	//			arr[count1] = i;
				count1++;

				if (i != sqrt(n))
				{
					sum += (n / i);
		//			arr2[count2] = n / i;
			//		count2++;

				}

			}

		}
		
		UL sum2 = sum;

	//	for (int i = count2 - 1; i > 0; i--)
		//	arr[count1++] = arr2[i];

		
		/*for (int i = count1 - 1; i >= 0; i--)
		{
			for (int j = i+1; j < count1; j++)
			{
				if (arr[j] != 0)
				{
					if (arr[j] % arr[i] == 0)
					{
						sum -= arr[i];
						arr[i] = 0;
						break;
					}
				}
			}

		}*/

		/*for (int i = 0; i <count1-1; i++)
		{
			for (int j = i + 1; j < count1; j++)
			{
				//if (arr[j] != 0)
					if (arr[j] % arr[i] == 0)
					{
						sum -= arr[i];
						break;
					}
				//}
			}

		}*/


		cout << sum2 << "\n";

	}


	return 0;
}