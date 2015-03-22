// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>

#include <string.h>

#include <deque>

using namespace std;


struct node_tst
{
	int data;
	char c;
	node_tst* left,*middle,*right;

	node_tst(char cr):c(cr)
	{
		left=NULL;
		middle=NULL;
		right=NULL;
		data=0;
	}

};


void all_keys(node_tst *root,string prefix,deque<string>& q); // for tst

void get_longest_prefix_key(node_tst *root,string key,int,int&);        // for tst

class tst
{
	node_tst *root;


	node_tst *insertr(node_tst *root,string key,int data,int d)
	{
		char c =key.at(d);

		if(root==NULL)
		{
			root=new node_tst(c);
		}

		if(c<root->c)
			root->left=insertr(root->left,key,data,d);

		else if(c>root->c)
			root->right=insertr(root->right,key,data,d);

		else if(d < key.length()-1)
		root->middle=insertr(root->middle,key,data,d+1);

		else
			root->data=data;

		return root;
	}


	node_tst* getr(node_tst *root,string key,int d)
	{
		if(root==NULL)
			return NULL;

		char c=key.at(d);

		if(c<root->c)
			return getr(root->left,key,d);
				
		else if(c>root->c)
		return getr(root->right,key,d);

		else if(d < key.length()-1)
			return getr(root->middle,key,d+1);

		else
			return root;

	}

public:

	tst()
	{
		root=NULL;
	}

	void insert(string key,int data)
	{
		root=insertr(root,key,data,0);
	}

	int  get(string key)
	{
		node_tst *temp=getr(root,key,0);

		if(temp==NULL)
		{
			cout<<"value not found ";
			return 0;
		}
		else
			return temp->data;

	}

	void print_all_keys()
	{
		deque<string> q;

	//	q.push_back("wfew");

		all_keys(root,"",q);

		while(!q.empty())
		{
		//	cout<<"wf";
			cout<<endl<<q.front()<<"  ";
			q.pop_front();

		}
	}

	void print_prefix_key(string prefix)
	{
		deque<string> q;

		all_keys(getr(root,prefix,0),prefix.substr(0,prefix.length()-1),q);

		while(!q.empty())
		{
		//	cout<<"wf";
			cout<<endl<<q.front()<<"  ";
			q.pop_front();

		}
	}

string print_longest_prefix_key(string key)
{
	int length=0;

	get_longest_prefix_key(root,key,0,length);

	return key.substr(0,length);
}
	
};


void get_longest_prefix_key(node_tst* root,string key,int d,int& length)
{

	if(root==NULL)
		return;
	
	char c=key.at(d);

	if(root->data!=0)
			length=d+1;

	if(c<root->c)
		get_longest_prefix_key(root->left,key,d,length);

	else if(c>root->c)
		get_longest_prefix_key(root->right,key,d,length);

	else if(d < key.length()-1)
	{	
		get_longest_prefix_key(root->middle,key,d+1,length);
	}
	

}


void all_keys(node_tst *root,string prefix,deque<string>& q)
{

	if(root==NULL)
		return;

	

	if(root->data!=0)
		{
			prefix+=root->c;
			q.push_back(prefix);
	//		cout<<"   "<<q->size();
	     }
	
		if(root->left!=NULL)
			all_keys(root->left,prefix,q);

		if(root->right!=NULL)
			all_keys(root->right,prefix,q);

		if(root->middle!=NULL)
			all_keys(root->middle,prefix+(root->c),q);
	

}

// for R-way tries
struct node
{
	int data;
	node *next[256];

	node():data(0)
	{
			for(int i=0;i<256;i++)
			next[i]=NULL;
	}

};


void insert(node **root,string key,int data)
{
	if((*root)==NULL)
		(*root)=new node;

	
	int len=key.length();
	
	node *visit=(*root);

	for(int i=0;i<len;i++)
	{
		if(visit->next[key.at(i)]==NULL)
			visit->next[key.at(i)]=new node;

			visit=visit->next[key.at(i)];
	}

	visit->data=data;

	// cout<<visit->data;

}

node* get(node **root,string key)
{
	if((*root)==NULL)
	{
		return NULL;

	}
	int len=key.length();
	
	node *visit=(*root);

	for(int i=0;i<len;i++)
	{
		if(visit->next[key.at(i)]==NULL)
			return NULL;

		visit=visit->next[key.at(i)];
	}

	return visit;
}

int getdata(node **root,string key)
{

	node *temp=get(root,key);
	if(temp==NULL)
	{
		cout<<"no such string ";
		return 0;
	}

	return temp->data;

}


string longprefix(node *root,string key)
{

	int longkey=0;

	int length=key.length();
	
	for(int i=0;i<length;i++)
	{
		if(root->next[key.at(i)]==NULL)
			break;

		if(root->next[key.at(i)]->data!=0)
			longkey=i+1;

		root=root->next[key.at(i)];
		
	}

	return key.substr(0,longkey);

}





int _tmain(int argc, _TCHAR* argv[])
{

	// for R-way search tries

	node *root=NULL;

	
insert(&root,"riteshb",3);
insert(&root,"ritesh",1);

//	cout<<endl<<((root->next['s'])->next['e'])->data;

//	cout<<endl<<getdata(&root,"riteh");

//	cout<<endl<<"longest prefix  "<<longprefix(root,"riteshbajaj")<<" ";

	
	// ternary search tries

	tst t;

	t.insert("bajaj",1);
	t.insert("pop",2);
	t.insert("abc",3);
	t.insert("abcde",6);

	t.insert("ab",4);


	cout<<t.get("abcd");

	t.print_all_keys();

	t.print_prefix_key("abcd");

	// longest key in tst that is prefix of query string

	// search for the string and keep track of length

	cout<<endl<<"longest prefix   "<<t.print_longest_prefix_key("bajajbajaj")<<"  ";


	return 0;
}

