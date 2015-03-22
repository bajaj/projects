// indexed_min_pq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

class MinIndexedPQ
{
	int maxsize,heapsize;
	int *heap, *keys, *index;

	void swap(int i, int j)
	{
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;

		index[heap[i]] = i;
		index[heap[j]] = j;
	}

	void bubbleup(int k){

		while (k > 1 && keys[heap[k / 2]] > keys[heap[k]])
		{
			swap(k, k / 2);
			k = k / 2;
		}

	}

	void bubbledown(int k)  // min heapfiy
	{
		int left = 2 * k;
		int right = 2 * k + 1;
		
		int smallest = k;

		if (left <= heapsize && keys[heap[left]] < keys[heap[k]])
			smallest = left;

		if (right <= heapsize && keys[heap[right]] < keys[heap[smallest]])
			smallest = right;

		if (smallest != k)
		{
			swap(k, smallest);
			bubbledown(smallest);
		}

	}

public:

	MinIndexedPQ(int n)
	{
		maxsize = n;
		heapsize = 0;
		heap = new int[n + 1];
		keys = new int[n + 1];
		index = new int[n + 1];
		
		for (int i = 0; i <= n; i++)
		{
			index[i] = -1;
		}
	}

	~MinIndexedPQ()
	{
		delete[] keys;
		delete[] heap;
		delete[] index;
	}

	void insert(int i, int item)
	{
		heapsize++;
		
		keys[i] = item;
		index[i] = heapsize;
		heap[heapsize] = i;
		bubbleup(heapsize);
	}

	bool isEmpty()
	{
		return heapsize == 0;
	}

	bool contains(int k)
	{
		return index[k] != -1;
	}

	int size()
	{
		return heapsize;
	}

	int minitem()
	{
		return keys[heap[1]];
	}

	int minindex()
	{
		return heap[1];
	}

	int deletemin()      // delete the minimal key and return its associated index
	{
		int min = heap[1];

		swap(1, heapsize);
		heapsize--;
		bubbledown(1);

		index[min] = -1;
		return min;
	}

	int item(int i)
	{
		return keys[i];
	}

	void changeitem(int i, int item)
	{
		if (keys[i] > item)     // decrease key
		{
			keys[i] = item;
			bubbleup(index[i]);
		}
		else   // increase key
		{
			keys[i] = item;
			bubbledown(index[i]);
		}

	}

	void deleteitem(int k)
	{
		int ind = index[k];
		swap(ind, heapsize);
		heapsize--;

		bubbleup(ind);
		bubbledown(ind);

		index[k] = -1;
	}


};


int _tmain(int argc, _TCHAR* argv[])
{
	MinIndexedPQ pq(10);
	for (int i = 0; i<10; i++)
		pq.insert(i, 10 - i);

	cout << pq.minitem() <<" "<<pq.size();

//	pq.changeitem(0, 0);
	cout << " " << pq.minitem() << "\n";

	cout << "minindex" << pq.minindex();

	pq.deleteitem(9);

	cout << " " << pq.minindex() << "\n";

	cout << pq.deletemin();

	

	return 0;
}

