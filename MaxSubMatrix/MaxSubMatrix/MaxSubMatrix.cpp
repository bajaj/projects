// MaxSubMatrix.cpp : Defines the entry point for the console application.
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


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)


#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)


struct mat
{
	int sr, er, sc, ec;

	mat()
	{
		sr = 0; er = 0; ec = 0; sc = 0;
	}


};





int row, column;

int noOfelem(mat elem)
{
	return ((elem.er - elem.sr) + 1)*((elem.ec - elem.sc) + 1);
}


int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	DRT()
	{
		int arr[11][11] = { 0 };
		mat dp[11][11];
		int maxelem = 0;
		mat max;

		cin >> row >> column;
		
		FOR(i, 1, row)
		{
			FOR(j, 1, column)
				cin >> arr[i][j];
		}

		FOR(i, 1, row)
		{
			FOR(j, 1, column)
			{	
				//mat &dp[i][j] = dp[i][j];

				if (arr[i][j] == 1)
				{
					if (arr[i][j - 1] == 0 && arr[i - 1][j] == 0)
					{
						dp[i][j].er = i; dp[i][j].sr = i; dp[i][j].sc = j; dp[i][j].ec = j;
					}
					else if (arr[i][j - 1] == 1 && arr[i - 1][j] == 0)
					{
						dp[i][j] = dp[i][j - 1]; dp[i][j].ec++;
					}
					else if (arr[i - 1][j] == 1 && arr[i][j - 1] == 0)
					{
						dp[i][j] = dp[i - 1][j]; dp[i][j].er++;
					}
					else
					{
						int x = noOfelem(dp[i - 1][j]);
						int y = noOfelem(dp[i][j - 1]);

						if (x >= y)
						{
							dp[i][j] = dp[i - 1][j];
							dp[i][j].er++;
						}
						else
						{
							dp[i][j] = dp[i][j - 1];
							dp[i][j].ec += 1;
						}

					}

					if (maxelem < noOfelem(dp[i][j]))
					{
						maxelem = noOfelem(dp[i][j]);
						max = dp[i][j];
					}


				} // 1

			}   // for
		}    // for

		cout <<max.sr << " " << max.er << "\n" << max.sc << " " << max.ec<<"\n \n";


	}    // test case



	return 0;
}