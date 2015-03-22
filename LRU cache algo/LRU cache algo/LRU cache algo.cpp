// LRU cache algo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>

int hash_int(int key,int M)   // M is the table
{
	return (key & 0x7fffffff)%M;            // anded to produce positive result
	 
}

using namespace std;

struct node
{
	int key;
	string value;
	node *next;
	node *prev;

	node(int key,string value):key(key),value(value),next(NULL),prev(NULL)
	{
		
	}

};


class LRU
{
	node **arr;     // hash table
	int M;			// for size  of the hash table

	node *head;      // head of queue link list
	node *tail;

	int frame_size;   // max size of queue
	int allocated;    // current size

	int hash;            // temp variable so that a hash is not recalculted every time

public:

	LRU(int cache_size)
	{
		// for queue

		head=NULL;
		tail=NULL;
		frame_size=cache_size;
		allocated=0;

		/// for hash table

		M=cache_size*2;

		arr=new node*[M];

		for(int i=0;i<M;i++)
		{
			arr[i]=NULL;
		}
	}

	node* insert_value_linear_probing(int key,string value);
	
	node* search_value_linear_probing(int key);

	node* insert_linked_list(int key,string value);

	void bringfront(node *temp);
	
	void replace(int key,string value);

	string search(int key,string value);    //search for the page and then if not there insert otherwise return value 
	
	void insert(int key,string value)
	{
		cout<<endl<<"value inserted   "<<insert_value_linear_probing(key,value)->value<<"  ";
	}

	void display_cache()
	{
		node *visit=head;

		cout<<endl<<"no of element in cache "<<allocated;

		cout<<endl<<"key"<<"		"<<"value"<<"	"<<endl;

		while(visit!=NULL)
		{
			cout<<visit->key<<"			"<<visit->value;

			cout<<endl;

			visit=visit->next;
		}

	}

};

string LRU::search(int key,string value)
{
			
	return (insert_value_linear_probing(key,value))->value;

		
}


void LRU::replace(int key,string value)    // replace the end node and then bring front
{

	arr[hash_int(tail->key,M)]=NULL;

	tail->key=key;
	tail->value=value;

	bringfront(tail);

}

void LRU::bringfront(node *front)
{
	if(front==head)
		return;

	if(front==tail)
	{
		tail=(front->prev);
	}

		node *head_old=head;

	(front->prev)->next=(front->next);

	if(front==tail)
	{
		tail=(front->prev);
    	(front->next)->prev=(front->prev);
	}


	head=front;

	head->next=head_old;
	head->prev=(head_old->prev);

	head_old->prev=head;

}
node* LRU::insert_linked_list(int key,string value)
{
	if(frame_size==allocated)
		{
			replace(key,value);     // replace the tail node

			return head;
     	}

	allocated++;

	if(head==NULL)
	{
		head=new node(key,value);
		tail=head;
		return head;
	}

	// insert into front

	node* temp=head;

	head=new node(key,value);

	temp->prev=head;
	head->next=temp;

	return head;
}

node* LRU::search_value_linear_probing(int key)
{
	 hash=hash_int(key,M);

	for(int i=hash;arr[i]!=NULL;i=(i+1)%M)
	{
		if(arr[i]->key==key)
			return arr[i];
		
		
	}

	return NULL;

}


node* LRU::insert_value_linear_probing(int key,string value) 
{
	      
        	node *temp=search_value_linear_probing(key);

			if(temp!=NULL)   // if the page is present bring into the front of the list
				{
					cout<<endl<<" page is there in cache ";
				  // bring into the front  of the list							
					bringfront(temp);
					return head;
				}
	

		int i;
	
	for(i=hash;arr[i]!=NULL;i=(i+1)%M)
	{
		if(arr[i]==NULL)
			break;
	}

	arr[i]=insert_linked_list(key,value);

	return head;

}


int _tmain(int argc, _TCHAR* argv[])
{
	LRU l(5);

	l.insert(0,"bajaj");
	l.insert(1,"ritesh");

	l.insert(2,"komal");

	l.search(3,"mom");

	l.search(4,"teema");

	l.display_cache();

	l.insert(9,"cool");
	l.insert(45,"jay:");

		l.display_cache();

//	l.disp();
	return 0;
}

