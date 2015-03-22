// XORSUB_practise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;


#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

#define rep(i,n) for(int i=0;i<(n);i++)
#define forup(i,a,b) for(int i=(a);i<=(b);i++)



int maxi(int a, int b)
{
	return a > b ? a : b;
}


void setImplementation(unsigned short n, unsigned short k, unsigned short arr[])
{	
	unordered_set<unsigned short> s;
	unsigned short max = k;
	rep(i, n)
	{
		cin >> arr[i];
	//	s.insert(arr[i]);
		
	}
	s.insert(k);

	rep(i, n)
	{
		for (const auto& elem : s)
		{
			max = maxi(max, elem^arr[i]);
			s.insert(elem^arr[i]);
		}
	}

	
		
	

	cout << max << "\n";
}


unsigned short dp[1001][1024] = { 0 };
int main()
{

	inp_s; cinnull;

	unsigned short t, arr[1001], k, n;


	cin >> t;

	while (t--)
	{
		cin >> n >> k;

		setImplementation(n, k, arr);
	}
		return 0;

		dp[0][0] = 1;

		for (unsigned short j = 1; j<=1023; j++)
		{
			dp[0][j] = 0;
		}

		unsigned short max = 0;

		for (unsigned short i = 1; i <= n; i++)
		{
			cin >> arr[i];

			for (unsigned short j = 0; j <= 1023; j++)
			{
				dp[i][j] = dp[i - 1][j] | dp[i - 1][j^arr[i]];
				
				if (dp[i][j])
				{
					max = maxi(max, j^k);
				}

			}

		}

		cout << max << "\n";

	


	return 0;
}

