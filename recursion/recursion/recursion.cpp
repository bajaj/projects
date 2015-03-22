// recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;


void printarray(int arr[],int n)
{

	if(n==-1)
	{	
	cout<<endl;
	return;
	}
	cout<<"   "<<arr[n];
	printarray(arr,n-1);
	cout<<"   "<<arr[n];


}

int sum(int no)
{

	if(no==0)
		return 0;

	return no%10 + sum(no/10);

}



int _tmain(int argc, _TCHAR* argv[])
{

	int arr[10]={1,2,3,4,5,6,7,8,9,10};

//	printarray(arr,1);

	cout<<sum(1)<<" ";

	return 0;
}

