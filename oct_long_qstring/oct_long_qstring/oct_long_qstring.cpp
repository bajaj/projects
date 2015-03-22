// oct_long_qstring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "string"

#include "iostream"

#include "map"

#include "vector"

#include "algorithm"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	map<string, int> m;

	vector<string> v;

	string n;

	cin >> n;

	
	for (int i = 0; i < n.length(); i++)
	{
		m[n.substr(i)] = i;

		v.push_back(n.substr(i));

	}

	sort(v.begin(), v.end());


	for (int i = 0; i < n.length(); i++)
	{
		cout << m[v[i]] << "\n";
	}


	return 0;
}

