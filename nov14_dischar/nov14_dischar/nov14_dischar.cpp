// nov14_dischar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

#include "iostream"

#include <bitset>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
//	ios_base::sync_with_stdio(false);

//	cin.tie(NULL);

	//bitset<26> arr(0);

	short t;

	//unsigned int n;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		bitset<130> arr(0);

		//cin >> n;

		register int temp;
		short count=0;
		temp = getchar();

		while ((temp = getchar())!='\n')
		{
			if (arr[temp] == 0)
			{
				count += 1;
			}
			arr[temp] = 1;

		}

		cout << count;
		cout << "\n";
	}


	return 0;
}

