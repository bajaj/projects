// codechef_SEAVOTE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <cmath>


using namespace std;

inline bool get(int num, int deno)
{
	num *= 10000000;

	if (num%deno==0)
	{
		return true;
	}
	else
	{
		return false;
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	/*float x = 1.0 / 4;
	if (x * 4.0 == 1)
	{
		cout << "done";
	}
	else
		cout << x * 4;
	*/

	int t, n, x,sum,total=0,ans,extra;

	cin >> t;

	while (t--)
	{
		cin >> n;

		sum = 0; total = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			sum += x;
			if (x != 0)total++;
		}

		if (sum < 100)
			ans = 0;
		else if (sum == 100)
			ans = 1;
		else
		{
			extra = sum - 100;

			while (total)
			{
				if ((extra / total) >= 1)
				{
					ans = 0;
					break;

				}

				
					ans = 1;
					break;
				
				total--;
			}

		}

		if (ans)
			cout << "YES";
		else
			cout << "NO";

		cout << "\n";
	}


	return 0;
}

