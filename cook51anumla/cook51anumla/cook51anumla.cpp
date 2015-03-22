// cook51anumla.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "algorithm"

#include "iostream"

#include <math.h>

#include <set>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int t;

	int n;

	
	multiset<long long unsigned int> multi;

	multiset<long long unsigned int>::iterator it;

	cin >> t;

	

	long long unsigned int arr[15];

	long long unsigned int subset[32770];
	
	

	for (int i = 0; i < t; i++)
	{
		int count = 0;
		cin >> n;
		
		//int temp = (int)pow(2, n);
		int temp = 1 << n;
		long long unsigned int tem = 0;


		for (int j = 0; j < temp; j++)
		{
			cin >> tem; multi.insert(tem);
		}

		multi.erase(0);
		
		it = multi.begin();
		arr[0] = *it;

		multi.erase(it);

		for (int i = 1; i < n; i++)
		{

			int x = count;

			while (x >= 0 && count!=0)
			{

				multi.erase(arr[i - 1] + subset[x]);
				subset[count] = subset[x] + arr[i - 1];
				count++;
				x--;
			}
			subset[count] = arr[i - 1];
			if(count==0)count++;
			it = multi.begin();
			arr[i] = *it;

			multi.erase(it);

		}

		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}

		cout << "\n";
	}

	return 0;
}

