// codechef_oneking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#include "algorithm"
#include "utility"


using namespace std;

bool cmp(const pair<short, short> a, const pair<short, short> b)
{
	if (a.second == b.second)
		return a.first > b.first;

	return a.second < b.second;

}


bool intersect(pair<short, short> a, pair<short, short> b)
{
	if (a.first == b.first || a.second == b.second)
		return true;
	
	if (a.first > b.first && a.first < b.second)
		return true;

	if (a.second >= b.first && a.second < b.second)
		return true;

	return false;

}

int _tmain(int argc, _TCHAR* argv[])
{
	

	int t, n;
	short a, b;

	pair <short, short> arr[100001];

	//	p arr[100001];

	

	cin >> t;

	while (t--)
	{
		bool marked[100001] = { 0 };

		cin >> n;

		arr[0].first = 0;
		arr[0].second = 0;

		
		for (int i = 1; i <= n; i++)
		{
			cin >> a >> b;

			arr[i].first = a;
			arr[i].second = b;
		}

		sort(arr + 1, arr + n+1, cmp);

		int count = 0;

		for (int i = 1; i <= n; i++)
		{
			if (marked[i] == 0)
			{
				count++;
				marked[i] = 1;

				for (int j = i + 1; j <= n; j++)
				{

					if (marked[j] == 0)
					{
						if (intersect(arr[i], arr[j]))
						{
							marked[j] = 1;
						}
						else
							break;

					}

				}

			}


		}


		//cout << arr[1].first;
		cout << count<<"\n";
	}


	return 0;
}

