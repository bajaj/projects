// codechef_CAPPLE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <bitset>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n,temp,count;

	cin >> t;

	while (t--)
	{
		bitset<1000001> arr;
		count = 0;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;

			if (arr[temp] == 0)
				count++;
			
			arr[temp] = 1;
			
		}

		cout << count << "\n";
	}



	return 0;
}

