// sept_fun_rotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int n, m;

	cin >> n;
	cin >> m;

	unsigned int* arr = new unsigned int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	unsigned int ind = 0;
	char c;
	unsigned int x;
	for (int i = 0; i < m; i++)
	{
		cin >> c;
		cin >> x;
		if (c == 'R')
			cout << arr[(ind + x-1) % n] << endl;
		else if (c == 'C')
			ind = (ind + x) % n;
		else if (c == 'A')
			ind = (ind + n - x) % n;
		
	}
	delete[] arr;
	return 0;
}

