// oct_lunch_css2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include <tuple>

#include <map>

using namespace std;

struct nod
{
	unsigned int val;
	unsigned int pri;

	nod(unsigned int val2=0,unsigned int pri2=0) :val(val2), pri(pri2)
	{
	}

};


int _tmain(int argc, _TCHAR* argv[])
{

	map<tuple<unsigned int, unsigned int>, nod> arr;

	unsigned int n, m, id, att, pri, val,i;

	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> id >> att >> val >> pri;

		if (arr[make_tuple(id, att)].pri <= pri)
		{

			arr[make_tuple(id, att)] = *(new nod(val,pri));
		//	arr[make_tuple(id, att)].pri = pri;
		}
	}


	//arr[make_tuple(22, 1)].val = 300;

	for (i = 0; i < m; i++)
	{
		cin >> id >> att;
		cout << arr[make_tuple(id, att)].val;

		cout << "\n";
	}

	

	return 0;
}

