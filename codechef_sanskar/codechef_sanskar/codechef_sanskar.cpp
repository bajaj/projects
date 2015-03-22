// codechef_sanskar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "bitset"
#include "algorithm"
#include <cmath>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int t, n;
	
	float k;
	
	


	cin >> t;

	while (t--)
	{
		//	bitset<1001> arr;
		unsigned long long int arr[21] = { 0 };
		unsigned long long int temp, mean, sum = 0;

		cin >> n >> k;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			arr[i] = temp;
			sum += temp;

		}

		sort(arr, arr + n);


		if (floor(sum / k) != sum / k)
		{
			cout << "no";
		}
		else if ((mean = sum / k) < arr[n - 1])
		{
			cout << "no";
		}
		else
		{
			int i = 0, j = n - 1;

			mean = sum / k;

			while (j >= i)
			{
				if (arr[j] == mean)
					j--;
				else if (arr[i] + arr[j] == mean)
				{
					i++; j--;
				}
				else if (arr[i] + arr[j] < mean)
				{
					arr[j] += arr[i];
					i++;
				}
				else
					break;

			}

			if (j >= i)
			{
				cout << "no";
			}
			else
				cout << "yes";

		}
				
		cout << "\n";
	}


	return 0;
}

