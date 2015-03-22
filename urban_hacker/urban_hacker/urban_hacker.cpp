// urban_hacker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;


#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)


//#include <bits/stdc++.h>

typedef long long int LL;

int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	string s;

	cin >> t;


	cin >> s;


	while (t--)
	{
		string ans;
		cin >> s;

		int size = s.length();

		int i = 0;
		for (; i < size; i++)
		{
			int x = s[i] - '0';

			if (x>3 && x < 5)
			{
				ans.push_back(5);
				break;
			}
			if (x < 3)
			{
				ans.push_back(3);
				break;
			}
			if (x > 5)
			{

			}

		}




		cout << ans;
	}
	return 0;
}

