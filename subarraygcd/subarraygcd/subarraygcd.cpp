// subarraygcd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include "stdio.h"

using namespace std;


int gcd(int a, int b)
{
	if (b==0)
		return a;
	
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return (a*b) / gcd(a, b);

}

int _tmain(int argc, _TCHAR* argv[])
{

	int t, n,x=0;

	int arr[100000];

	cin >> t;

	while (x != t)
	{
		t--;

		cin >> n;

		//	int *arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int size = 0, c_start = 0, c_end = 0,p_start;

		for (int i = 0; i < n - 1; i++)
		{

			c_start = i;
		//	c_end = i;

			if (c_end <= i)
				p_start = i + 1;
			else
				p_start = c_end;

			for (int j =p_start; j < n; j++)
			{
				if (lcm(arr[i], arr[j]) != arr[i]*arr[j])
					break;
				else
				{
					c_end = j;
					for (int k = i; k < j; k++)
					{
						if (lcm(arr[k], arr[j]) != arr[k]*arr[j])
						{
							c_end = j - 1;
							break;
						}

					}
				}

				if (c_end == j - 1)
					break;

			}

			if (((c_end - c_start) + 1) > size)
				size = c_end - c_start + 1;

		}

			if (size == 1)
				cout << -1;
			else cout << size;

			cout << '\n';

		

	}

	return 0;
}

