// heap_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;


inline int parent(int i)
{
	return i >> 1;

}

inline int left(int i)
{
	return i << 1;
}

inline int right(int i)
{
	return (i << 1) + 1;

}

void swap(int arr[], int i, int j)
{
	int temp = arr[i];

	arr[i] = arr[j];
	arr[j] = temp;

}

void max_heapify(int arr[], int i,int heapsize)
{
	int l = left(i);
	int r = right(i);


	int largest=i;

	if (l <= heapsize && arr[l] > arr[i])
		largest = l;

    if (r <= heapsize && arr[r] > arr[l])
		largest = r;

	if (largest != i)
	{
		swap(arr, largest, i);
		max_heapify(arr, largest, heapsize);
	}

}

void build_max_heap(int arr[], int length)
{

	for (int i = length / 2; i > 0; i--)
		max_heapify(arr, i, length);

}


void heapsort(int arr[], int length)
{
	build_max_heap(arr, length);



	for (int i = length; i > 1; i--)
	{
		swap(arr, 1, i);
		--length;
		max_heapify(arr, 1, length);

	}


}


int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cout << "enter the  no of elements in an array";

	cin >> n; 

	int *arr = new int[n+1];

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];

	}

	//cout << right(1)<<" "<<left(2)<<" ";

	//build_max_heap(arr, n);

	heapsort(arr, n);

	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << "  ";

	}


	return 0;
}

