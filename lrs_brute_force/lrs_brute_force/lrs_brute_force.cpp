// lrs_brute_force.cpp : Defines the entry point for the console application.
// longest repeated substring using brute force method

#include "stdafx.h"

#include "string"

#include "iostream"

using namespace std;


struct lrs
{
	int start;
	int end;

	lrs(int start = 0, int end = 0) :start(start), end(end)
	{

	}

	int length()
	{
		return end - start;
	}
		

};


lrs LCP(int a, int b, int p, int q, string s)
{

	lrs temp (a, a);

	int i = a;
	for (int j = p; i <= b && j < q; i++, j++)
	{
		if (s[i] != s[j])
			break;

	}
	temp.end = i;

	return temp;
}


int _tmain(int argc, _TCHAR* argv[])
{

	string s;

	cin >> s;

	lrs ans(0, 0);

	for (int i = 0; i < s.length() - 1; i++)
	{
		int j = i + 1;



		while (j < s.length())
		{
			lrs temp = LCP(i, j - 1, j, s.length(), s);

			if (temp.length() > ans.length())
				ans = temp;

			j++;

		}

	}

	cout << s.substr(ans.start,ans.length());

	return 0;
}

