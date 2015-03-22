// oct_long_chefpnt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include "fstream"

#include "vector"


using namespace std;


int getright(int i, int j, short arr [][100], short m)
{
	

	while (j<m)
	{
		if (arr[i][j] != 0)
		{
			j--;
			break;
		}
		j++;
	}

	if (j == m)
		return --j;

	return j;
}

int getdown(int i, int j, short arr[][100], short n)
{
	while (i<n)
	{
		if (arr[i][j] != 0)
		{
			--i;
			break;
		}
		i++;
	}

	if (i == n)
		return --i;

	return i;
}

void fillright(int i, int j, short arr[][100], int q)
{
	while (j <= q)
	{
		arr[i][j] = 2;
		j++;
	}


}


void filldown(int i, int j, short arr[][100], int p)
{

	while (i <= p)
	{
		arr[i][j] = 2;
		i++;
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> out;

	short arr[100][100] = { 0 };
    short n, m; int k;

	int steps = 0;

	ifstream myfile;
	
	myfile.open("in.txt");

	myfile >> n >> m >> k;

	
	

	for (int x = 0; x < k; x++)
	{
		int i; int j;
		myfile >> i >> j;
		arr[i-1][j-1] = 1;
	}

	myfile.close();
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				steps++;

			//	outfile << i+1 <<" "<< j+1<<" ";

				out.push_back(i + 1);
				out.push_back(j + 1);

				int p = getdown(i, j, arr, n);
				int q = getright(i, j, arr, m);

				if ((q - j)>=(p - i))
				{
					fillright(i,j, arr, q);
				//	outfile << 0;
					out.push_back(0);
				}
				else
				{
					filldown(i, j, arr, p);
				//	outfile << 1;
					out.push_back(1);
				}
					

			//	outfile << "\n";
			}



		}



	}

//	outfile.close();

//	outfile.open("out.txt");

	ofstream outfile;

	//outfile.open("out.txt");
	cout << steps;
	cout << "\n";

//	outfile.write(steps,0);
	int temp = out.size() ;
	for (int i = 0; i < temp; i++)
	{
		cout << out[i] << " " << out[i + 1] << " ";// << out[i + 2];
		if (out[i + 2] == 0)
		{
			cout << "0";
		}
		else cout << "1";

		cout << "\n";
		i = i + 2;

	}

	outfile.close();

	return 0;
}

