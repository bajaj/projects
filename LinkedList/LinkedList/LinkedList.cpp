// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <algorithm>

using namespace std;


struct node
{
	node* next;
	int data;

	node(int data):next(NULL),data(data)
	{

	}

};


class link
{
	node* head;

public:
	link():head(NULL)
	{


	}


	~link();

int length();

void push(int data);

node* gethead()
{
	return head;
}

void free_memory(node *);
void wrapper_free();
void display();

int pop();

void insertn(int data,int index);


void sortedinsert(node *nod);



void wrapper_sort();

friend void appen(link& a,link& b);

friend void frontbacksplit(link& a,link& front,link& back);


void remove_duplicate(); // NOT IMPLEMENTED

friend void movenode(link& a ,link& b);

friend void shuffle_merge(link& a ,link& b,link& c);

friend void sorted_merge(link& a ,link& b,link& c);

friend void merge_sort(link& a);

friend void intersect(link& a ,link& b,link&);

void revers(node *nod);


void adj_reverse();


void rec_reverse(node* nod);

};



void link::rec_reverse(node* nod)
{
	if(nod->next==NULL)
	{
		head=nod;
		return;
	}
	rec_reverse(nod->next);

	nod->next->next=nod;
	nod->next=NULL;

}

node* rev(node* nod)
{
	if(nod->next==NULL)
	{
		return nod;
	}

	node *p=rev(nod->next);

	nod->next->next=nod;
	nod->next=NULL;

	return p;

}

void link::revers(node *nod)
{

	if(nod->next==NULL)
	{
		head=nod;
		return;
	}

	revers(nod->next);

	nod->next->next=nod;
	nod->next=NULL;

}


void print_f(node* head)
{
	if(head==NULL)
		return;

	cout<<"   "<<head->data;

	print_f(head->next);

}


void print_b(node* head)
{
	if(head==NULL)
		return;

	print_b(head->next);

	cout<<"   "<<head->data;

}







void intersect(link& a ,link& b,link& inter)
{

	node *f=a.head;
	node *s=b.head;

	while(f!=NULL || s!=NULL)
	{
		
		if(f->data==s->data)
		{
			inter.push(f->data);
			f=f->next;
			s=s->next;
		}
		else if(f->data>s->data)
			s=s->next;
		else
			f=f->next;

	}



}


void  merge_sort(link& arr)
{

	link a,b;
 	
	if(arr.head==NULL || ((arr.head)->next==NULL))
		return;

	frontbacksplit(arr,a,b);

	merge_sort(a);	

	merge_sort(b);

	sorted_merge(a,b,arr);


}



void sorted_merge(link& a ,link& b,link& c)
{
	if(a.head==NULL && b.head==NULL)
		return;


	node **temp=&c.head;

	node *f=a.head;
	node *s=b.head;


	while(f!=NULL || s!=NULL)
	{
		if(f!=NULL && s!=NULL)
		{
			if(f->data>s->data)
				{
					*temp=s;
					s=s->next;
		     	}
			else
				{
					*temp=f;
					f=f->next;
		     	} 

		}

		else if(s!=NULL)
		{
				*temp=s;
				s=s->next;
		}

		else if(f!=NULL)
		{
			*temp=f;
			f=f->next;
		}

		temp=&((*temp)->next);	
	}


a.head=NULL;                 
	b.head=NULL;
			
}



void  shuffle_merge(link& a ,link& b,link& c)           // can't return object because of destructor is called 
{
	

	node *f=a.head;
	node *s=b.head;

	if(a.head!=NULL)
	{
		c.head=a.head;
		f=f->next;
	}
	else if(b.head!=NULL)
	{
		c.head=b.head;
		s=s->next;
	}

	node *t=c.head;

	while(f!=NULL || s!=NULL)
	{
		if(s!=NULL)
		{
			t->next=s;
			s=s->next;
			t=t->next;
		}

		if(f!=NULL)
		{
			t->next=f;
			f=f->next;
			t=t->next;
		}

	}


	// below statment are necessary since  and b points to some part of c and when main() terminates 
	// then destructor of object are called  so dangling pointer error
	// beacause a frees the memory and then when dest

	a.head=NULL;                 
	b.head=NULL;
	

//	return c;

	//l.display();

 //  return l;

}

void movenode(link& a,link& b)
{
	if(b.head==NULL)
		return;

	node *temp=b.head;

	b.head=b.head->next;

	temp->next=a.head;
	a.head=temp;


}



void frontbacksplit(link& a,link& front,link& back)
{
		

	if(a.head==NULL || a.head->next==NULL)
	{
		front.head=a.head;
		back.head=NULL;
		a.head=NULL;

		return;
	}

	node* first=a.head;
	node* second=a.head->next;

	while(second!=NULL ) // see order of comparison
	{
		

		if(second->next!=NULL)
		{
			first=first->next;
		second=(second->next)->next;
		}
		else
		{
			second=second->next;
		}

	}


	front.head=a.head;

    a.head=NULL;

	back.head=first->next;

	first->next=NULL;

}



void appen(link& a,link& b)
{
	if(a.head==NULL)
	{
		a.head=b.head;
		b.head=NULL;
		return;
	}

	node *temp=a.head;

	while(temp->next!=NULL)
		temp=temp->next;

	_ASSERT(temp!=NULL);

	temp->next=b.head;
	b.head=NULL;

}



void sorted_insert(node **head,node *nod)
{
	if(*head==NULL || (*head)->data>=nod->data)
	{
		nod->next=*head;
		*head=nod;

		return;
	}
	

	// locate the point before the point of intersection


		node *current=(*head);

		while(current->next!=NULL && (current->next)->data<nod->data)
			current=current->next;

		nod->next=current->next;

		current->next=nod;



}

/// for sorting the link list this function i.e  sortedinsert page 22 of linked list problems stanford


void link::wrapper_sort()
{
	if(head==NULL || head->next==NULL)
		return;

	node *result=NULL;

	node *curr=head;

	node *next;

	while(curr!=NULL)
	{
		next=curr->next;

		sorted_insert(&result,curr);
		curr=next;
	}

	head=result;

}


void link::sortedinsert(node *nod)
{
	if(head==NULL || head->data>=nod->data)
	{
		nod->next=head;
		head=nod;

		return;
	}
	

	// locate the point before the point of intersection


		node *current=head;

		while(current->next!=NULL && (current->next)->data<nod->data)
			current=current->next;

		nod->next=current->next;

		current->next=nod;

}





void link::insertn(int data,int index)
{
	if(index==0)
	{
		push(data);
		return;
	}

	int count=0;

	node* temp=head;

	while(count!=(index-1))
		{ 
			_ASSERT(temp!=NULL);

			++count;

			temp=temp->next;
     	}

	_ASSERT(head!=NULL);

	node* nxt=temp->next;


	temp->next=new node(data);

	(temp->next)->next=nxt;

//	head=temp;


}



int link::pop()
{
	int data=head->data;

	node *temp=head;

	head=head->next;

	delete temp;

	return data;
}

void link::free_memory(node* nod)
{

	if(nod==NULL)
		return;

	free_memory(nod->next);

	delete nod;



}


void link::wrapper_free()
{
free_memory(head);

	head=NULL;
}



link::~link()
{
free_memory(head);

}


int link::length()
{
	int count=0;

	node* temp=head;

	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}

	return count;
}


void link::push(int data)
{
	node *temp=new node(data);

	temp->next=head;

	head=temp;

}

void link::display()
{

	node* nod=head;

	while (nod!=NULL)
	{
		cout<<" "<<nod->data;
		nod=nod->next;
	}

}



void link::adj_reverse()
{

	if(head==NULL || head->next==NULL)
		return;

	node* temp1=head;
	
	//head=head->next;

	node **prev=&head;

	node* temp2=temp1->next;


	while( temp1!=NULL && temp1->next!=NULL )
	{
		*prev=temp2;

		prev=&((*temp1).next);

		temp1->next=temp2->next;

		temp2->next=temp1;

		temp1=temp1->next;

		if(temp1!=NULL)
		temp2=temp1->next;

	}


}



int _tmain(int argc, _TCHAR* argv[])
{



	link l,l2;

//	l.push(12);
//	l.push(2);

	l.insertn(14,0);
	l.insertn(111,1);


	l.insertn(333,2);

	l.insertn(337,3);

	l.insertn(500,4);

	
//	l.insertn(600,5);

	l.display();


//	l.adj_reverse();

	l.rec_reverse(l.gethead());

	cout<<endl;

	l.display();
//l.insertn(35,5);




l2.insertn(333,0);

	l2.insertn(500,1);




//movenode(l,l2);



//	link front,back;

	

//	/l.sortedinsert(new node(55));            // work because not deferencing it	

//		l.sortedinsert(new node(45));

//	l.wrapper_sort();

	
	//l.display();
	cout<<endl;

//	merge_sort(l);

//	cout<<" merge sort  is ";

	//l.display();

//	cout<<" shuffle merge is ";

	//link l3;

//	shuffle_merge(l,l2,l3);

//	sorted_merge(l,l2,l3);


//	intersect(l,l2,l3);

//	l.revers(l.gethead());

	

 //l.display();
//	int arr[]={2,5,10,8,1};

// cout<<endl<<"  forward recursion ";

// print_f(l.gethead());

 //cout<<endl<<"    backward recursion";

// print_b(l.gethead());

	return 0;
}

