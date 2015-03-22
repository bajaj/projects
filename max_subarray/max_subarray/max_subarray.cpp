// max_subarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int max(int x,int y)
{
	return x>y?x:y;

}


int max_subarray(int arr[],int size,int& start,int &end)
{

	int max_so_far=0;
	int max_ending_here=0;

	int neg[1][2]={{0,0}};     // fo all neagative no
	int neg_count=0;


	start=0;
	int x=0;
	for(int i=0;i<size;i++)
	{

		max_ending_here=max_ending_here+arr[i];

		if(max_ending_here<0)
		{
			max_ending_here=0;
			x=0;
		}

		else if(max_so_far<max_ending_here)
		{
			x++;
			if(x==1)
				start=i;

			max_so_far=max_ending_here;
			end=i;
		}

		// for all negative no // the smallest no will be the max subarray
	
		
		if(arr[i]<0 && neg_count==i)
		{
			neg_count++;
			if(neg[0][0]>arr[i])
				{
					neg[0][0]=arr[i];
					neg[0][1]=i;
			    }
		}

	}
	if(neg_count==size)
		{
			start=neg[0][1];
			end=neg[0][1];
			return neg[0][0];
	    }
	return max_so_far;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={2,-3,4,5,2,-1,-6,-8};

	int start=0;
	int end =0;

	int size=sizeof(arr)/sizeof(arr[0]);


	cout<<"sum of max sub array is"<<max_subarray(arr,size,start,end);

	cout<<endl<<"the subarray is";

	for(int i=start;i<=end;i++)
		cout<<"   "<<arr[i];


	return 0;
}

