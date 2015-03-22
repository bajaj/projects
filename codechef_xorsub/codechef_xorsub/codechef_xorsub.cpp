// codechef_xorsub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "bitset"
#include "algorithm"


using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{

	int t, k, n,temp;

	cin >> t;

	while (t--)
	{
	//	bitset<1001> arr;
		int arr[1001] = { 0 };


		cin >> n >> k;

	//	int max = k;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			arr[i] = temp;
		}


		sort(arr, arr + n);
		arr[n] = k;
		
		int supermax = k;
		for (int i = n - 1; i >= 0; i--)
		{
			int max = 0;
			for (int j = i + 1; j <= n; j++)
			{
				if ((arr[i] ^ arr[j])>max)
					max = arr[i] ^ arr[j];

			}

			arr[i] = max;

			if (max > supermax)
				supermax = max;
		}


		cout << supermax << "\n";

	}

	return 0;

}

