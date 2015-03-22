// hashing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>


using namespace std;


// refere algorithsm in java by robert segwick

struct node
{
	node* next;

	string key;

	int data;

	node(int d,string k):next(NULL),data(d),key(k)
	{

	}
};


int hash_int(int key,int M)   // M is the table
{
	return (key & 0x7fffffff)%M;            // anded to produce positive result
	 
}


int hash_string(string key,int M)
{
	int length=key.length();

	int hash=0;

	for(int i=0;i<length;i++)
		hash=key[i]+(31*hash);      // horrer's method

	return (hash & 0x7fffffff)%M;
}

int hash_double(double key,int M)
{
	
__int64 i=(_int64) key;
	
return ((int (i ^ (i>>32))) & 0x7fffffff)%M;          // xor most significant 32 bits with least significant 32 bits

return 0;
}


void insert_linklist(node **head,int value,string key)
{

	// if key present then replace it otherwise insert into the front of the list

	node *visit=*(head);

	while(visit!=NULL)
	{
		if((visit->key)==key)
		{
			visit->data=value;
			return;
		}
		else
			visit=visit->next;
	}

	// insert into front of the list

	node *temp=*(head);

	(*head)=new node(value,key);

	(*head)->next=temp;

}


void insert_value(string key,int value,node* arr[],int M)  // using separate chaining
{
	int hash=hash_string(key,M);

	if(arr[hash]==NULL)
		arr[hash]=new node(value,key);

	else insert_linklist(&(arr[hash]),value,key);

}



node* hashing_chaining(string key,node* arr[],int M)
{
	int hash=hash_string(key,M);

	if(arr[hash]==NULL)
		return NULL;

		node *temp=arr[hash];

		while(temp!=NULL)
		{
			if(temp->key==key)
				return temp;
			temp=temp->next;
		}

		return NULL;
}

int getvalue(string key,node* arr[],int M)
{
	node *temp=hashing_chaining(key,arr,M);

	if(temp==NULL)
	{
		cout<<"the required value with key is not there";
		return 0;
	}
	else
		return temp->data;

}

 void insert_value_linear_probing(string key,int value,string arr_key[],int arr_value[],int M)
 {
	 int hash=hash_string(key,M);

	 int i;

	 for(i=hash;arr_key[i]!="\0";i=(i+1)%M)
	 {
		 if(arr_key[i]==key)
			 break;

	 }
	  arr_key[i]=key;
	 arr_value[i]=value;
 }

 int get_value_linear_probing(string key,string arr_key[],int arr_value[],int M)
 {
	  int hash=hash_string(key,M);

	  int i;

	 for(i=hash;arr_key[i]!="\0";i=(i+1)%M)
	 {
		 if(arr_key[i]==key)
		 {
			 return arr_value[i];
		 }
	 }

	cout<<endl<<"value not found ";

	return 0;

 }


int _tmain(int argc, _TCHAR* argv[])
{

	double d=3434.532;

   __int64 i=(_int64) d;

//	cout<<i;

 


//***************** for linear probing **********************************888

string arr_key[29];

int arr_value[29];

   int M=24;

string key="bajaj";
   int  value=2323;

  for(int i=0;i<29;i++)                 // null and zero are same in c++
	  arr_value[i]=NULL;
   
  int n=1;

  while(n)    // insert loop
   {
	   cout<<endl<<"enter the key  ";
	   cin>>key;
	   
	   cout<<endl<<"enter the value ";
	   cin>>value;

	   insert_value_linear_probing(key,value,arr_key,arr_value,M);

	   cout<<endl<<" want to continue 0 or 1";

	   cin>>n;
	   
   }
 
  n=1;

   while(n)
   {
	      cout<<endl<<"enter the key to get the value  ";
		  cin>>key;

		  cout<<"value :  "<<get_value_linear_probing(key,arr_key,arr_value,M);

		  cout<<endl<<" want to continue 0 or 1";

	    cin>>n;

   }




//*********   // for separate chaining  *********************8

     node* arr[5];

   for(int i=0;i<5;i++)
   {
	   arr[i]=NULL;

   }



   

//   arr[hash_string(key,97)]=value;

//   cout<<arr[hash_string(key,97)];

//   insert_value(key,value,arr,M);

// 




  /*  while(n)    // insert loop
   {
	   cout<<endl<<"enter the key  ";
	   cin>>key;

	   cout<<"  hash is "<<hash_string(key,M);

	   cout<<endl<<" want to continue 0 or 1";

	   cin>>n;

	}
	*/

/*   while(n)    // insert loop
   {
	   cout<<endl<<"enter the key  ";
	   cin>>key;
	   
	   cout<<endl<<"enter the value ";
	   cin>>value;

	   insert_value(key,value,arr,M);

	   cout<<endl<<" want to continue 0 or 1";

	   cin>>n;
	   
   }

   n=1;

   while(n)
   {
	      cout<<endl<<"enter the key to get the value  ";
		  cin>>key;

		  cout<<"value :  "<<getvalue(key,arr,M);

		  cout<<endl<<" want to continue 0 or 1";

	    cin>>n;

   }

 */  

	return 0;
}

