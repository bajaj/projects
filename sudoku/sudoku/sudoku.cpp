// sudoku.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE


#include "stdafx.h"
#include <iostream>
#include <vector>




using namespace std;

int arr[10][10] = { 0 };
vector< pair<int, int> >v;

int pointer = 0; // points to current empty cell

void initialize()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)

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

	for (int j = 1; j <= 9; j++)
	{
		if (arr[row][j] == no)
			return false;
	}

	return true;
}

bool checkColumn(int no)
{
	int column = v[pointer].second;

	for (int i = 1; i <= 9; i++)
	{
		if (arr[i][column] == no)
			return false;
	}

	return true;

}

bool checkBox(int no)
{
	int rowth = ceil(v[pointer].first/3.0);
	int colth = ceil(v[pointer].second / 3.0);

	int rowStart = (rowth - 1) * 3 + 1;
	int colStart = (colth - 1) * 3 + 1;

	for (int i = rowStart, count = 0; count < 3; count++, i++)
	{
		for (int j = colStart, countC = 0; countC < 3; countC++, j++)
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
	bool y=checkColumn(no);
	bool z=checkBox(no);

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

	for (int i = 1; i <= 9; i++)
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

		for (int i = 1; i <= 9; i++)
		{
			cout << "\n";

			for (int j = 1; j <= 9; j++)
				cout << arr[i][j] << " ";
		}

	
}


int _tmain(int argc, _TCHAR* argv[])
{

#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cout << "enter no of filled cells \n";
	cin >> n;

	cout << "enter rowNo columnNo integer \n";

	for (int i = 0,x,y,no; i < n; i++)
	{
		cin >> x >> y>>no;
		arr[x][y] = no;
	}

	initialize();

	sudokuSolver();


	return 0;
}

