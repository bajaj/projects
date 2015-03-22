// chefinv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include "fstream"

using namespace std;


unsigned long int range(unsigned long int i, unsigned long int j, unsigned long int* arr, unsigned int* inv,unsigned int* tot_inv,unsigned long int n)
{
	long int total_inv = 0;
	
    long int inv_i = inv[i],inv_j=inv[j];


	for (unsigned long int p = i+1; p < j; p++)
	{
		if ((arr[p]>arr[i] && arr[p] > arr[j]) || (arr[p] < arr[i] && arr[p] < arr[j]))
		{
			// don't add anything
		}
		
		if ((arr[p]>arr[i]) && (arr[p]<arr[j]))
		{
			total_inv++;
		}

		if ((arr[p]<arr[i]) && (arr[p]>arr[j]))
		{
			total_inv--;
		}
		if (arr[i] > arr[p])
		{
			inv_i--;
		}
		if (arr[j] > arr[p])
		{
			inv_j++;
		}

		total_inv += inv[p];

	}

	if (arr[i] < arr[j])
		total_inv++;
	else if (arr[i] > arr[j])
		inv_i--;
		

	total_inv += inv_i + inv_j;

	return total_inv;
}


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream myfile;
	 
	myfile.open("in.txt");

	unsigned long int n, m;

	myfile >> n;
	myfile >> m;

	unsigned long int* arr = new unsigned long int[n];
	
	unsigned int *inv = new unsigned int[n];

	unsigned int *tot_inv = new unsigned int[n];

	//unsigned long int inv[6];

	//unsigned long int tot_inv[6];

	inv[n - 1] = 0;
	tot_inv[n - 1] = 0;

	//unsigned long int arr[6];

	for (unsigned long int i = 0; i < n; i++)
		myfile >> arr[i];

	//unsigned long int arr[] = { 1, 4, 6, 3, 2, 5 };

	for (long int i = n - 2; i >= 0; i--)
	{   
		inv[i] = 0;

		for (unsigned long int j = i + 1; j < n; j++)
		{
			
			if (arr[i] > arr[j])
				inv[i] += 1;

		}

		tot_inv[i] = tot_inv[i + 1] + inv[i];
	}

	ofstream my_o;
	my_o.open("out.txt");


	for (unsigned long int t = 0; t < m; t++)
	{
		unsigned long int i, j;

		unsigned long int total_inv = 0;

		myfile >> i; myfile >> j;

		i -= 1; j -= 1;


		if (i == j || (arr[i] == arr[j]))
			total_inv=tot_inv[0];
		else
		{
			total_inv += range(i, j, arr, inv, tot_inv, n);


				if (j != n - 1)
				{
				total_inv += tot_inv[j + 1];
				}
			if (i != 0)
			{
				total_inv += tot_inv[0] - tot_inv[i];
			}
		}
		
		my_o << total_inv << "\n";

	}


	delete[] arr;
	delete[] inv;
	delete[] tot_inv;
	

	return 0;
}

