// nov14_rbtree_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <bitset>
#include "string"
#include <math.h>

using namespace std;


int count(int level, bitset<1> root,bitset<1> color)
{

	int count = 0;

	while (level != 0)
	{
		if (color==root)
		{
			if (level % 2 == 0)
				count++;
		}
		else
		{
			if (level % 2 != 0)
				count++;
		}

		level--;
	}


	return count;
}



bitset<1> getcolor(int logx, bitset<1> flag)
{
	if (logx % 2 == 0)
	{
		if (flag == 0)
			return 0;
		else
			return 1;

	}
	else
	{
		if (flag == 0)
			return 1;
		else
			return 0;

	}

}

unsigned long int lca(unsigned long int x, unsigned long int y)
{
	int logx = (int)log2(x);
	int logy = (int)log2(y);

	if (logx > logy)
	{
		int temp = logx;
		logx = logy;
		logy = temp;

		unsigned long int z = x;
		x = y;
		y = z;

	}

	int dh = logy - logx;

	while (dh && y>=1)
	{
		y /= 2;
		dh--;
	}

	while (x != y)
	{
		x /= 2;
		y /= 2;
	}

	return x;
}



int _tmain(int argc, _TCHAR* argv[])
{

	bitset<1> flag = 0;
	bitset<1> query;
	int t;
	string str;
	unsigned long int x, y;
	int logx, logy;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		unsigned int c = 0, cx, cy;
		cin >> str;


		if (str == "Qi")
			flag = ~flag;
		else
		{
			cin >> x;
			cin >> y;

			logx = (int)log2(x);
			logy = (int)log2(y);

			if (str == "Qr")
				query = 1;
			else
				query = 0;

		}

		if (str != "Qi")
		{

			unsigned long int lc = lca(x, y);

			c = count(logx, flag, query) + count(logy, flag, query) - 2 * count((int)log2(lc), flag, query);


			if (getcolor((int)log2(lc), flag) == query)
				c++;

			cout << c << "\n";

		}
	}

	return 0;
}

