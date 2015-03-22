// CHEFCH.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"



#include <iostream>
#include <string>
#include <fstream>
using namespace std;


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)


int min(int a, int b)
{
	return a > b ? b : a;

}


int main()
{

	inp_s; cinnull;

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);


	int t;

	cin >> t;

	while (t--)
	{
		string str;
	//	unsigned int count = 0, ans2 = 0,ans=0;
		cin >> str;

//		string temp = str;

		unsigned int n = str.length();

		int ans = 0, ans2 = 0; int flag = 1;
		
		for (unsigned int i = 0; i < n;i++)
		{
			if (flag)
			{
				flag = 0;

				if (str[i] == '+')
					ans++;
				else
					ans2++;
			}
			else
			{
				flag = 1;

				if (str[i] == '-')
					ans++;
				else
					ans2++;

			}

		}

		cout << min(ans,ans2) << "\n";

	}

	return 0;
}

