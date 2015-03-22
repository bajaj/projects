// google coin problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int max(int a,int b)
{

	return a>b?a:b;

}

int min(int a,int b)
{

return a>b?b:a;
}




int arr[]={2,4,5,1,11,14};




int memo[6][6]={0};


int p(int i,int j)
{

	if(i==j || i>j)
		return 0;

//	static int k=0;

//	cout<<" "<<k++;

	return max((arr[i]+min(p(i+2,j),p(i+1,j-1))),arr[j]+min(p(i+1,j-1),p(i,j-2)));
}

int memoo(int i,int j)
{
//	static int k=0;
	

	if(i==j || i>j)
		return 0;

	if(memo[i][j]!=0)
		return memo[i][j];

//	cout<<" "<<k++;

	memo[i][j]=max(arr[i]+min(memoo(i+2,j),memoo(i+1,j-1)),arr[j]+min(memoo(i+1,j-1),memoo(i,j-2)));

	return memo[i][j];

}


	


int _tmain(int argc, _TCHAR* argv[])
{

	cout<<p(0,5);

	cout<<endl;

	cout<<"   "<<memoo(0,5);

//	cout<<memo[0][5];

	return 0;
}

