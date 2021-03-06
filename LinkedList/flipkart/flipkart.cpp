// flipkart.cpp : Defines the entry point for the console application.
//
//http://www.geeksforgeeks.org/flipkart-interview-experience-set-32-for-sde-1/

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node
{
	node *next, *down;
	int data;
		
	node(int x)
	{
		data = x;
		next =NULL;
		down = NULL;
	}

};

node* convert(node* head)
{
	if (!head->down && !head->next)
		return head;

	if (head->down == NULL)
		return convert(head->next);
	
	if (head->next == NULL)
	{
		head->next = head->down;
		head->down = NULL;
		return convert(head->next);
	}

	node* temp = head->next;

	convert(head->down)->next = temp;
	head->next = head->down;
	head->down = NULL;

	return convert(head->next);
}

void printLink(node* temp)
{
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

}

node* reverse(node* headref,node** headref2)
{
	if (!headref)
		return NULL;
	
	node* tail = reverse(headref->next,headref2);

	if (tail)
		tail->next = headref;
	else
		*headref2 = headref;


	headref->next = NULL;
	return headref;

}


int main()
{
/*	node* head = new node(1);
	head->next = new node(2); head->next->next = new node(3);// ->next = new node(4);

	head->down = new node(7);
	head->next->down= new node(8);
	
	node* tail=convert(head);
	*/

	node* head = new node(1);
	head->next = new node(2); head->next->next = new node(3);
	printLink(head);

	cout << "\n";

	node* temp;

	reverse(head,&temp);
	printLink(temp);


	return 0;
}

