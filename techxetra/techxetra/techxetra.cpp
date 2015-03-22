// techxetra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include "vector"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v;

	int t;

	float n;

	cin >> t;

	int temp; int i;
	for (i = 0;; i++)
	{

		 temp = (i*i + i + 2) / 2;

		 if (temp > 1000)
			 break;

		 v.push_back(temp);

	}

	v.push_back(temp);
		


	for (int i = 0; i < t; i++)
	{

		cin >> n;

		
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j]>=n)
			{
				cout << j;
				
				break;
			}

		}

		cout << "\n";

	}


	return 0;
}

