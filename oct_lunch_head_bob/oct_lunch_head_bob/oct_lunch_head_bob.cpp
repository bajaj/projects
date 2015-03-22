// oct_lunch_head_bob.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include "string"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int t,n;

	cin >> t;
	
	string s;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		cin >> s;

		int j = 0;
		for (; j < n; j++)
		{

			if (s[j] == 'Y')
			{
				cout << "NOT INDIAN";
				break;
			}
			else if (s[j] == 'I')
			{
				cout << "INDIAN";
				break;
			}

		}

		if (j == n)
			cout << "NOT SURE";

		cout << "\n";

	}


	return 0;
}

