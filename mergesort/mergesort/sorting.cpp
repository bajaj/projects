// mergesort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;


// ** merger sort *//////

void merge(int arr[],int lo,int mid,int high)
{
	int *arr1=new int[mid-lo+1];
	int *arr2=new int[high-mid];

	int a1=0;

	for(int i=lo;i<=mid;i++)
		{
			arr1[a1++]=arr[i];
	   }

	a1=0;
	for(int i=mid+1;i<=high;i++)
		{
			arr2[a1++]=arr[i];
	   }

	a1=mid-lo+1;
	int a2=high-mid;

	int x=0,y=0;

	for(int i=lo;i<=high;i++)
	{
		if(x<a1 && y<a2)
		{
		if(arr1[x]<=arr2[y])
			arr[i]=arr1[x++];
		else
			arr[i]=arr2[y++];
		}
		else if(x<a1)
			arr[i]=arr1[x++];
		else if(y<a2)
			arr[i]=arr2[y++];

	}

	delete[] arr1;

	delete[] arr2;
}

void mergesort(int arr[],int lo,int high)
{
	if(lo<high)
	{
		int mid=lo+(high-lo)/2;

		mergesort(arr,lo,mid);          // sort the left part 
		mergesort(arr,mid+1,high);     // sort the right part
		merge(arr,lo,mid,high);      // merger  the result
	}


}

//  **////    merger sort

/// *******************************************HEAPSORT ************************************** //////

inline int left(int i)
{
	return 2*i;
}
inline int right(int i)
{
	return 2*i+1;
}

inline int parent(int i)
{
	return i/2;
}


inline void swap(int &x,int &y)
{
	int temp;

	 temp=x;
	x=y;
	y=temp;
}

void max_heapfiy(int arr[],int i,int heapsize)       // logarithmic time
{
	int l=left(i);
	int r=right(i);
	int largest;

	if(l<=heapsize && arr[l]>arr[i])
		largest=l;
	else
		largest=i;

	if(r<=heapsize && arr[r]>arr[largest])            // important step  
		largest=r;

	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		max_heapfiy(arr,largest,heapsize);
	}

}

void build_max_heap(int arr[],int length)       // linear time 
{

	int heapsize=length;

	for(int i=length/2;i>=1;i--)
		max_heapfiy(arr,i,heapsize);
}

void heapsort(int arr[],int length)
{
	build_max_heap(arr,length);  // linear time

	int heapsize=length;
	for(int i=length;i>=2;i--)
	{
		swap(arr[1],arr[i]);
		heapsize--;
		max_heapfiy(arr,1,heapsize);
	}


}

// **********  Priority queue ***** ////////////////

int max(int arr[])
{
	return arr[1];
}

int extract_max(int arr[],int& heapsize)
{

	_ASSERT(1<heapsize);
	

int max=arr[1];

arr[1]=arr[heapsize];

heapsize--;

//cout<<"  heapsize is "<<heapsize;

max_heapfiy(arr,1,heapsize);

return max;
}

void increase_key(int arr[],int i,int k,int& heapsize)
{
	if(k<arr[i])
		cout<<"not allowed";

	arr[i]=k;

	for(int j=parent(i);j>=1;j--)
		max_heapfiy(arr,j,heapsize);
}

void insert(int arr[],int k,int& heapsize)
{
	arr[++heapsize]=0xf0000000;

	cout<<arr[heapsize];

	increase_key(arr,heapsize,k,heapsize);
}





void display(int arr[],int length)
{
	cout<<endl;
	for(int i=0;i<length;i++)
	{
		cout<<"   "<<arr[i];

	}

}


// ***************** bubble sort   **********************///

void bubble_sort(int arr[],int length)
{
	for(int i=1;i<length;i++)
	{
		cout<<endl;
		cout<<i;

		int flag=0;

		for(int j=0;j<length-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];

				arr[j]=arr[j+1];
				arr[j+1]=temp;

				flag=1;
			}

		}

		if(flag==0)
			break;

	}




}


int partition(int arr[],int start,int end)
{
	int pivot=arr[end];

	int pindex=start;

	for(int i=start;i<end;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr[i],arr[pindex]);
			pindex++;
		}

	}
	swap(arr[pindex],arr[end]);
	return pindex;
}

void quicksort(int arr[],int start,int end)
{
	if(start<end)
	{

		int pindex=partition(arr,start,end);
		quicksort(arr,start,pindex-1);
		quicksort(arr,pindex+1,end);
	}


}


int ranki(int arr[],int start,int end,int rank)    // returns element of rank x
{
	int pindex=-1;
	
	rank=rank-1;

	while(start<=end)
	{
		pindex=partition(arr,start,end);

		if(pindex>rank)
			end=pindex-1;
		
		else if (pindex<rank)
		{
			start=pindex+1;
		}
		else
		{
			return arr[pindex];
		}
			
	}
	
}


void insertionsort(int arr[],int len)
{
	
	for(int i=1;i<len;i++)
	{

		int value=arr[i];
		int hole=i;

		while(hole>0 && arr[hole-1]>value)
		{
			arr[hole]=arr[hole-1];
			hole--;
		}

		arr[hole]=value;

	}


}


int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={7,2,1,6,8,5,3,4};

//	cout<<"wfw";
//	bubble_sort(arr,9);

//	quicksort(arr,0,8);

//	swap(arr[0],arr[8]);

	insertionsort(arr,8);

display(arr,8);

	
	//cout<<endl<<ranki(arr,0,7,7);

//	mergesort(arr,0,4);

//	heapsort(arr,8);

/*	build_max_heap(arr,8);

	cout<<"maximum is "<<max(arr);

	int heapsize=8;

	increase_key(arr,3,400,heapsize);

	display(arr,heapsize+1);

	cout<<endl<<"extracted max "<< extract_max(arr,heapsize);
	display(arr,heapsize+1);

	insert(arr,322,heapsize);
	display(arr,heapsize+1);
*/



	return 0;
}

