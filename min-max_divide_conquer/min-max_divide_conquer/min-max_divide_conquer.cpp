// min-max_divide_conquer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int arr[]={3,1,5,6,72,12,45};

void minmax(int i,int j,int& min,int& max)
{
	if(i==j)
	{
		max=arr[i];
		min=arr[j];
	}
	else if(i==j-1)
	{
		if(arr[i]<arr[j])
		{
			max=arr[j];
			min=arr[i];
		}
		else
		{
			max=arr[i];
			min=arr[j];
		}
	}
	else
	{
		int max1,min1;

		int mid=(i+j)/2;

		minmax(i,mid,min,max);

		minmax(mid+1,j,min1,max1);

		if(max<max1)
			max=max1;

		if(min>min1)
			min=min1;

	}


}



int _tmain(int argc, _TCHAR* argv[])
{

		
	
	char *p="abcewr";

	cout<<sizeof(p);

	cout<<endl;

	int min=868;
	int max;

//	minmax(0,6,min,max);

	cout<<(&min);

//	cout<<min;
//	cout<<endl<<max;

	return 0;
}

