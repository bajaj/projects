// nov14_rbtree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "string"

#include "iostream"

#include <bitset>

#include <math.h>

using namespace std;


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




int _tmain(int argc, _TCHAR* argv[])
{

	bitset<1> flag = 0;         // intially black
	bitset<1> xcol; 
	bitset<1> ycol;
	bitset<1> maxcol;
	bitset<1> minicol;
	bitset<1> toggle;

	bitset<1> query;

	unsigned int t;
	unsigned long int x, y,maxi,mini;
	string str;
	int logx, logy;



	cin >> t;

	for (int i = 0; i < t; i++)
	{
		unsigned int count = 0;
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

			xcol = getcolor(logx, flag);
			ycol = getcolor(logy, flag);


			if (xcol == query)
				count++;

			if (ycol == query)
				count++;

			if (logx > logy)
			{
				maxcol = xcol;
				maxi = x;
				mini = y;
				minicol = ycol;
			}
			else
			{
				maxcol = ycol;
				minicol = xcol;
				maxi = y;
				mini = x;

			}

			int diff = abs(logx - logy);
			toggle = maxcol;


			if(diff)maxi = maxi / 2;

			while (diff && maxi>mini)
			{
				toggle = ~toggle;

				if (toggle == query)
					count++;

				maxi = maxi / 2;
				diff--;
			}

			toggle = minicol;


			if (maxi>mini)

			{
				maxi /= 2;
				mini /= 2;

				while (maxi != mini)
				{
					toggle = ~toggle;

					if (toggle == query)
						count += 2;

					maxi /= 2;
					mini /= 2;

				}


				toggle = ~toggle;

				if (toggle == query)
					count++;

			}

			if (x == y)
			{
				if (query == xcol)
					cout << 1;
			}
			else
			cout << count;

			cout << "\n";


		}




	}


	



	return 0;
}

