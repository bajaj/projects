// oct_long_prpotion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;

inline unsigned long getmax(int x)
{
	unsigned long max = 0,temp;

	for (int i = 0; i < x; i++)
	{
		cin >> temp;

		if (temp > max)
			max = temp;
	}

	return max;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int t, r, g, b, m;

	cin >> t;

	unsigned long maxr, maxg, maxb;

	for (int i = 0; i < t; i++)
	{


		cin >> r;
		cin >> g;
		cin >> b;
		cin >> m;

		maxr = getmax(r);
		maxg = getmax(g);
		maxb = getmax(b);

		for (int i = 0; i < m; i++)
		{
			if (maxr > maxg)
			{
				if (maxr > maxb)
					maxr /= 2;
				else
					maxb /= 2;
			}
			else
			{
				if (maxg > maxb)
					maxg /= 2;
				else
					maxb /= 2;

			}

		}

		if (maxr > maxg)
		{
			if (maxr > maxb)
				cout << maxr;
			else
				cout << maxb;
		}
		else
		{
			if (maxg > maxb)
				cout << maxg;
			else
				cout << maxb;

		}


		cout << "\n";
	}


	return 0;
}

