// oct_lunch_physics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;


unsigned int max(unsigned int a, unsigned b)
{
	return a > b ? a : b;

}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long int t, n, f, arr[10000], maxi, mini,fi;


	cin >> t;

	for (unsigned int k = 0; k < t; k++)
	{
		cin >> n;
		cin >> f;

		unsigned long int count = 0;

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
		}

		for (int i = 0; i < n - 1; i++)
		{

			for (int j = i + 1; j < n; j++)
			{
				fi = f;

				if (arr[i]>arr[j])
				{
					maxi = arr[i];
					mini = arr[j];

				}
				else
				{
					maxi = arr[j];
					mini = arr[i];
				}

				while (true)
				{

					if (maxi == mini || (maxi / fi) >= mini )
					{
						count += 1;
						break;
					}

					if (fi > maxi)
						break;

					fi = fi*f;


				}


			}


		}

		cout << count << "\n";

	}



	return 0;
}

