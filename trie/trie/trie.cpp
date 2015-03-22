// trie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>

using namespace std;


const int R = 256;


struct node{

	int value;
	node* next[R] = {};

	node(int val = 0) :value(val)
	{

	}




};



void puting(node** rootref, int val, string key, int d,int len)
{
	if (d == len)
	{
		(*rootref)->value = val;
		return;
	}

	if ((*rootref)->next[key[d]] == NULL)
	{
		(*rootref)->next[key[d]] = new node();
		puting(&((*rootref)->next[key[d]]), val, key, d+1, len);
	}
	else
	{
		puting(&((*rootref)->next[key[d]]), val, key, d+1, len);
	}
	
}


void put(node** root, int value,string key)
{
	puting(root, value, key, 0, key.length());

}

node* gets(string key, node* root, int d, int len)
{
	if (root == NULL)
		return NULL;

	if (d == len)
	{
		if (root->value == 0)
			return NULL;
		else
			return root;
	}
	else
		return gets(key, root->next[key[d]], d + 1, len);

}

void get(string key, node* root)
{
	node *temp = gets(key, root, 0, key.length());
	
	if (temp == NULL)
	{
		cout << "no value ";

	}
	else
		cout<<temp->value;

}

int _tmain(int argc, _TCHAR* argv[])
{
	node* root=new node(10);


	put(&root, 5,"she");
	put(&root, 15, "shell");
	put(&root, 6, "he");

	get("shel", root);

//	cout << root->next['s']->next['h']->next['e']->value;


	return 0;
}

