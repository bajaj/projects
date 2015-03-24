// sudoku.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE


#include "stdafx.h"
#include <iostream>
#include <vector>




using namespace std;

int arr[901][901] = { 0 };
vector< pair<int, int> >v(901);

int pointer = 0; // points to current empty cell

int n;  // no of rows and columns

void initialize()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)

		{
			if (arr[i][j]==0)
			{
				v.push_back(make_pair(i, j));
			}
		}
	}

}

bool isEmpty()
{
	if (pointer == v.size())
		return true;
	else
		return false;



	int len = v.size();
	len--;

	if (arr[v[len].first][v[len].second] != 0)
		return false;
	else
		return true;

}

bool checkRow(int no)
{
	int row = v[pointer].first;

	for (int j = 1; j <= n; j++)
	{
		if (arr[row][j] == no)
			return false;
	}

	return true;
}

bool checkColumn(int no)
{
	int column = v[pointer].second;

	for (int i = 1; i <= n; i++)
	{
		if (arr[i][column] == no)
			return false;
	}

	return true;

}

bool checkBox(int no)
{
	float n_sqrt = sqrt(n);

	int rowth = ceil(v[pointer].first/(float)n_sqrt);
	int colth = ceil(v[pointer].second / (float)n_sqrt);

	int rowStart = (rowth - 1) * n_sqrt + 1;
	int colStart = (colth - 1) * n_sqrt + 1;

	for (int i = rowStart, count = 0; count < n_sqrt; count++, i++)
	{
		for (int j = colStart, countC = 0; countC < n_sqrt; countC++, j++)
		{
			if (arr[i][j] == no)
				return false;
		}

	}
	return true;
}

bool check(int no)
{
	bool x=checkRow(no);

	if (!x) return 0;

	bool y=checkColumn(no);

	if (!y) return 0;

	//bool z=checkBox(no);
	bool z = true;

	if (x && y && z)
	{
		arr[v[pointer].first][v[pointer].second] = no;
		pointer++;

		return true;

	}
	else
		return false;

}

void remove(int no)
{
	pointer--;
	arr[v[pointer].first][v[pointer].second] = 0;
}


bool solve()
{
	if (isEmpty())
		return true;

	for (int i = 1; i <= n; i++)
	{
		bool flag=0;

		if (check(i))
			flag = solve();
		else
			continue;

		if (flag)
			return flag;
		else
		{
			remove(i);
			continue;
		}

	}

	return false;
}

void sudokuSolver()
{
	bool flag = solve();

	// write to file
		//cout << "done";

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << arr[i][j] << " ";

			cout << "\n";
		}

	
}


int _tmain(int argc, _TCHAR* argv[])
{

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k;

	//cout << "enter no of filled cells \n";
	cin >> n>>k;

	n = pow(n, 2);

	//cout << "enter rowNo columnNo integer \n";

	for (int i = 0,x,y,no; i < k; i++)
	{
		cin >> x >> y>>no;
		arr[x][y] = no;
	}

	initialize();

	sudokuSolver();


	return 0;
}

