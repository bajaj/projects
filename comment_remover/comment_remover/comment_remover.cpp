// comment_remover.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[5000];
	int m=1,temp,t,n,x;
	arr[0] = 1;

	cin >> t;
	
	while (t--)
	{
		cin >> n;
		temp = 0;
		m = 1;
		arr[0]=1;

		for (int i = 1; i <= n; i++)
		{
			int xxx = i;

			while (i % 10 == 0)
				i = i / 10;

	//		if (i % 5 == 0)
	//			i = i / 5;

			for (int j = 0; j < m; j++)
			{
				x = arr[j] * i + temp;
				arr[j] = x % 10;
				temp = x / 10;
			}

			while (temp > 0)
			{
				arr[m] = temp % 10;
				temp /= 10;
				++m;
			}

			i = xxx;
		}

		cout << " sum of Fact of n is ";
		int sum = 0;
		for (int i = m - 1; i >= 0; i--)
			sum+=arr[i];
		
		
		cout <<sum<< "\n";
	}





	return 0;
}

