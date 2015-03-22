
#include "stdafx.h"

#include "iostream"

#include <string.h>
#include <stdio.h>

#include <stdlib.h> 


using namespace std;


inline int min(int l, int r, int c)
{
	if (l < r)
	{
		if (l < c)
			return l;
		else
			return c;
	}
	else{
		if (r < c)
			return r;
		else
			return c;
	}
}



int _tmain(int argc, _TCHAR* argv[])
{

	char s[100000], w[100000]; int dist[100000];
	int t, a, b, k;

	cin >> t;



	int downcell = 0, topcell = 0, cornercell = 0;
	int m, n;

	for (int x = 0; x < t; x++)
	{
		//cin >> s;
		//cin >> w;

		cin>> s;
		//scanf("%s", w);

		cin >> w;

		cin >> a;
		cin >> b;
		cin >> k;
		int current = 0, brek = 0, min2 = 101;

	//	m = strlen(s) + 1;
	//	n = strlen(w) + 1;

		//if (abs(m - n)*a>k)
		//	brek = 1;

		if ((a != 0 && b != 0))// && abs(m - n)*min(a, b, 101) <= k)
		{



			for (int j = 0; j < n; j++)
			{
				dist[j] = j*a;
			} 

			dist[0] = 0;



			for (int i = 1; s[i]!='\0'; i++)
			{
				int previous = i*a;
				int j = 1;
				for (; w[j]!='\0'; j++)
				{
					

					if (min2>previous)
						min2 = previous;

					topcell = previous + a;

					downcell = dist[j] + a;

					cornercell = dist[j - 1];

					if (s[i - 1] != w[j - 1])
						cornercell += b;

					current = min(topcell, downcell, cornercell);

					if (min2>current)
						min2 = current;

					if (min2>k)
					{
						brek = 1;
						break;
					}

					dist[j - 1] = previous;
					previous = current;

				}
				dist[j-1] = current;

				if (brek == 1)
					break;

			}

		}
		//int cost = edit_recursion(s, w, strlen(s), strlen(w), a, b);

		int cost = current;



		if (brek == 1 || cost > k)
			cout << -1;
		else
			cout << cost;

		cout << "\n";

	}

	return 0;
}