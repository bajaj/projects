// oct_long_prladdu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include <cmath> 

using namespace std;

#include "vector"

int _tmain(int argc, _TCHAR* argv[])
{
	int t, n; int vect[1000000];
	int arr[1000000];

//	vector<int> vect;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		unsigned int sum = 0;
	//	vector<int> vect;
	    int x = 0, y = 0;

		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];

			if (arr[j]>0)
			{
				vect[x] = j;
				x++;
			}
			//	vect.push_back(j);

		}

		for (int i = 0; i < n; i++)
		{
			if (arr[i] < 0)
			{
				while (arr[i] != 0)
				{
				
					if (arr[vect[y]] == 0)
						y++;  //vect.erase(vect.begin());

					int have = arr[vect[y]];
					int need = -arr[i];

					if (need == have)
					{
						arr[vect[y]] = 0;
						arr[i] = 0;
						sum += need*(abs(i - vect[y]));
					}
					else if (need>have)
					{
						arr[vect[y]] = 0;
						arr[i] += have;        // arr[i] is negative
						sum += have*abs(i - vect[y]);
					}
					else
					{
						arr[i] = 0;
						arr[vect[y]] -= need;

						sum += need*abs(i - vect[y]);
					}

				}

			}
		
			

		}

		cout << sum << "\n";
	}


	return 0;
}

