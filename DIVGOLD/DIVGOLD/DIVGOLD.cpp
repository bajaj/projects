// DIVGOLD.cpp : Defines the entry point for the console application.
//
//#include <bits/stdc++.h>
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include  <string>
using namespace std;


#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)


void swap(char& a, char& c)
{
	char temp = a;
	a = c;
	c = temp;

}

bool comp(const pair<char, int> a, const pair<char, int> b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	else
		return a.first < b.first;
}

int main()
{ 
   #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, n;

	string str;
	
	pair<char, int> arr[50]; int hash[150];

	cin >> t;

	while (t--)
	{

		cin >> n;

		cin >> str;
		
		for (int i = 0; i < n; i++)
		{
			arr[i] = make_pair(str[i], i);
			hash[str[i]] = i;
		}
		
		sort(arr, arr + n);


		int i = 0;
		for (i = 0; i < n; i++)
		{
			if (str[i] != arr[i].first)
				break;

		}
		string min = str;
		if (i!=n) 
		{
			int j = hash[arr[i].first];

			for (; j > i; j--)
				swap(min[j], min[j - 1]);

			if (arr[i].first==str[i+1])
			{
				

				for (int j = i; j < n - 1; j++)
				{
						swap(str[j], str[j + 1]);
						if (min > str)
						{
							min = str;
						}

				}

				
			}
			
		}


		cout <<min<< "\n";

	}


	return 0;
}

