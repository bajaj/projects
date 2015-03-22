// equalZerosandones.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<vector>

#include<iostream>

#include<string>

using namespace std;

int const M=31;


struct node
{
	int start;
	int end;
	int data;

	node* next;

	node(int d=0):start(-1),data(d),end(-1),next(NULL)
	{

	}

};

node* table[M]={NULL};

int maxdiff=-1;
int no;


inline int hash2(int i)
{

	return ((abs(i)%M));

}


void hashtable(int sum,int i)
{

	sum=abs(sum);

	node **x=&table[hash2(sum)];

	
	while(*x!=NULL)
	{
		if(((*x)->data)!=sum)
			*x=(*x)->next;
		else
		{
			(*x)->end=i;


			if(maxdiff<(((*x)->end)-((*x)->start)))
			{
				maxdiff=((*x)->end)-((*x)->start);
				no=sum;
			}
			break;

		}


	}

if(*x==NULL)
	{
		*x=new node(sum);
		(*x)->data=sum;
		(*x)->start=i;
		return;
	}


}


node* node_return(int data)
{
	node *temp=table[hash2(data)];

	while(temp!=NULL)
	{
		if(temp->data==data)
		break;
		temp=temp->next;

	}

	return temp;


}


int _tmain(int argc, _TCHAR* argv[])
{

	int prevsum=0;
	int sum=0;

	int index_zero=0;

	string str;

	cout<<"enter the string";

	cin>>str;

	int len=str.length();

	for(int i=0;i<len;i++)
	{
		if(str[i]=='0')
		sum=prevsum-1;
		else
			sum=prevsum+1;


		prevsum=sum;

        if(sum==0)
		index_zero=i;
		else
		hashtable(sum,i);


	}

	
	if(maxdiff>(index_zero))
	{
		node* temp=node_return(no);

		for(int i=temp->start+1;i<=temp->end;i++)
			cout<<" "<<str[i];

	}
	else
	{
		for(int i=0;i<=index_zero;i++)
			cout<<" "<<str[i];

	}
	

	return 0;
}

