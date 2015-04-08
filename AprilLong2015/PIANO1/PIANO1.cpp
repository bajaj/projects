// PIANO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

typedef long long int LL;


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)


#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a, int b)
{
	return a>b ? a : b;
}

#define INT_MAX 2147483647 


int min(int a, int b)
{
	return a > b ? b : a;
}


int main()
{
	inp_s; cinnull;

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);

	string s; int n, octave;
	DRT()
	{
		int count = 0;
		cin >> s >> n;

		int patLenght=0;

		int len = s.length();

		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'T')
				patLenght += 2;
			else
				patLenght += 1;
		}


		octave = n * 12;

		int no = octave - patLenght;

		FOR(i, 1, no)
		{
			count++;

			count += ((octave - (i+patLenght)) / patLenght);
		}

		cout << count << "\n";

	}


	return 0;
}

