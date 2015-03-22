// codechef_oneking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#include "algorithm"
#include "utility"


using namespace std;

bool cmp(const pair<short,short> a,const pair<short,short> b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;

}

int _tmain(int argc, _TCHAR* argv[])
{
	int t, n;
	short a, b;

	pair <short, short> arr[200002];

//	p arr[100001];

	cin >> t;

	while (t--)
	{
		cin >> n;

		arr[0].first = 0;
		arr[0].second = 0;

		int c = 1;

		for (int i = 1; i <= n; i++)
		{
			cin >> a >> b;

			arr[c].first = a;
			arr[c].second = -1;

			c++;
			arr[c].first = b;
			arr[c].second = 1;

			c++;
		}
			
	sort(arr+1, arr+n*2+1,cmp);

    	int count = 0,nostart=0;

		int x = n * 2;

		for (int i = 1; i<=x; i++)
		{
			if (nostart == 0)
				count++;

			if (arr[i].second == -1)
				nostart++;
			else
				nostart--;

				
		}


		//cout << arr[1].first;
		cout << count;
	}


	return 0;
}

