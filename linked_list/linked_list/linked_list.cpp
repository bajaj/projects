// linked_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <algorithm>

using namespace std;



struct node
{
	int data;
	node *next;

	node(int data,node* next=NULL) :data(data), next(next)
	{


	}
	node()
	{

	}



};


int length(node *head)
{
	if (head == NULL)
		return 0;

	return 1 + length(head->next);

}

void push(node *head)
{




}


node* BuildOneTwoThree()
{

	node *head = new node(1);

	head->next = new node(2);

	head->next->next = new node(3);

	return head;

}


void display(node* head)
{

	while (head != NULL)
	{
		cout << head->data<<"  ";
		head = head->next;

	}

}

void push(node **head,int data)
{
	node *temp = new node(data);

	temp->next = (*head);

	(*head) = temp;


}


void delete_list(node** head)
{

	while ((*head) != NULL)
	{
		node* temp = (*head)->next;

		delete *head;
		(*head) = temp;
	}

}

int pop(node** head)
{
	if (*head == NULL)
	{
		return 0;
	}


	int data = (*head)->data;
	node* temp = (*head);
	(*head) = (*head)->next;
	delete temp;


	return data;
}

void insertn(node** head,int index, int data)
{
	if (index == 0)
	{
		push(head,data);
		return;
	}

	node** current = head;
	
	while (index != 1)
	{
	    current = &((*current)->next);
     	index--;
	}

	(*current)->next = new node(data, (*current)->next);
	

}


void sortedinsert(node **head, node *x)
{
	node** temp = head;

	if (*head == NULL || (*head)->data >= x->data)
	{
		x->next = (*head);
		(*temp) = x;
		return;
	}

	while ((*temp)->next != NULL  && (((*temp)->next)->data < x->data) )
	{
		temp = &((*temp)->next);

	}

	x->next = (*temp)->next;
	(*temp)->next = x;

}

void insertsort(node** head)
{
	node* temp = NULL;

	node *x = *head;

	node *y = NULL;

	while ((x!=NULL))
	{
		y = x;
		x = x->next;
		sortedinsert(&temp, y);
		
	}

	(*head) = temp;
}

void append(node **a, node **b)
{
	node *temp = *a;

	if ((*a) != NULL)
	{
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}

		temp->next = *b;

	}
	else
	{
		*a = *b;
		
	}

	*b = NULL;
	
}


void frontbacksplit(node *source, node **front, node **back)
{
	node* f = source;
	node* s = source->next;

	while (true)
	{

		if (s == NULL || s->next == NULL)
		{
			*front = source;
			*back = f->next;
			f->next = NULL;


			break;
		}

		else
		{
			f = f->next;
			s = (s->next)->next;
		}

	}


}


void removeduplicates(node* head)
{
	node* temp = head;

	while (true)
	{

		if (temp == NULL || temp->next == NULL)
			break;

		else if (temp->data == (temp->next)->data)
			{
				node* x = temp->next;
				temp->next = (temp->next)->next;

				delete x;

			}
		else
			temp = temp->next;

	}


}


void movenode(node**a, node** b)
{
	node* temp = *b;

	*b = temp->next;

	temp->next = *a;
	*a = temp;
}


void alternating_split(node* s,node** f,node** l)
{

	node *a = NULL;
	node *b = NULL;

	while (s != NULL)
	{

		movenode(&a, &s);

		if (s != NULL)
		{
			movenode(&b, &s);
		}
	}

	*f = a;
	*l = b;



}

node* shufflemerge(node* a, node *b)
{
	node* temp=NULL;
	node* first=NULL;


	while (1)
	{

		if (a != NULL)
		{
			if (temp != NULL)
			{
				temp->next = a;
				temp = temp->next;
			}
			else
			{
				temp = a;
				first = a;
			}

			a = a->next;

		}

		if (b != NULL)
		{
			if (temp != NULL)
			{
				temp->next = b;
				temp = temp->next;
			}
			else
			{
				temp = b;
				first = b;
			}

			b = b->next;


		}

		if (a == NULL && b == NULL)
			break;

	}

	
	return first;


}


node* sortedmerge(node* a, node *b)
{
	node dummy;
	node* temp = &dummy;

	dummy.next = NULL;

	while (1)
	{
		if (a == NULL)
		{
			temp->next = b;
			break;
		}
		else if (b == NULL)
		{
			temp->next = a;
			break;
		}

		if (a->data <= b->data)
		{
			movenode(&(temp->next), &a);
		}
		else
		{
			movenode(&(temp->next), &b);
		}


		temp = temp->next;
	}

	return(dummy.next);


}





void mergesort(node** headref)
{
	node* head = *headref;

	if (head==NULL || head->next == NULL)
		return;

	node* front;
	node* back;
	frontbacksplit(head, &front, &back);

	mergesort(&front);
	mergesort(&back);

	*headref = sortedmerge(front, back);

}


node* sortedintersect(node* a, node* b)
{
	node dummy;
	node* temp = &dummy;
	dummy.next = NULL;

	while (1)
	{
		if (a == NULL)
		{
			break;
		}
		else if (b==NULL)
		{
			break;
		}

		if (a->data == b->data)
		{
			temp->next = new node(a->data);
			a = a->next;
			b = b->next;
			temp = temp->next;

		}
		else if (a->data < b->data)
		{
			a = a->next;

		}
		else
			b = b->next;


		

	}

	return dummy.next;

}


void reverse(node** head)
{
	if (*head == NULL)
		return;

	node* f = NULL;
	node* s, *temp;

	s = *head;

	while (s != NULL)
	{
		temp = s->next;
		s->next = f;
		f = s;
		s = temp;
	}
	*head = f;

}


int _tmain(int argc, _TCHAR* argv[])
{
	node *head,*head2;


	head = BuildOneTwoThree();

	head2 = BuildOneTwoThree();


	


	//(&head, 1);

	//display(head);
	
	//delete_list(&head);

	//cout << pop(&head) << "\n";
	//cout << pop(&head) << "\n";

	//cout << "cool";

	insertn(&head, 1, 10);

	//node* temp2 = sortedmerge(head, head2);
	//display(temp2);

	insertn(&head, 4, 4);
	//insertn(&head, 4, 5);
	insertn(&head, 4, 7);
	insertn(&head, 3, 20);
	//sortedinsert(&head, new node(30));
//	sortedinsert(&head, new node(0));
	
	
	mergesort(&head);
	//display(head);

//	node* temp = sortedintersect(head, head2);
	//insertsort(&head);
	reverse(&head); display(head);
	//append(&head, &head2);

	node* front;
	node* back;

//	frontbacksplit(head, &front, &back);

	
//	removeduplicates(head);


	

	//display(head);

	cout << "\n";

//	alternating_split(head, &front, &back);

//	display(front);

	
	cout << "\n";


//	display(back);


	return 0;
}

