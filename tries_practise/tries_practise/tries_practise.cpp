// tries_practise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <vector>

#include <string>

using namespace std;


struct node
{

	char c;
	int data;

	node* middle;
	node *left;
	node *right;

	node(int c,int data=0):middle(NULL),left(NULL),right(NULL),data(data),c(c)
	{


	}

};


void insert(string str,node **root,int data,int d)
{
	

	if((*root)==NULL)
	{
		*root=new node(str[d],0);
		insert(str,root,data,d);
	}
	else if(d==str.length())
		return;
	else if(d==str.length()-1)
		(*root)->data=data;

	else if((*root)->c==str[d])
		insert(str,&((*root)->middle),data,d+1);

	else if((*root)->c>str[d])
		insert(str,&((*root)->left),data,d);

	else
		insert(str,&((*root)->right),data,d);


}

node* get_node(string str,int d,node *root);

int getdata(string str,int d,node *root)
{

	node *temp=get_node(str,d,root);


	if(temp!=NULL)
		return (temp->data);
	else 
	return 0;


}



node* get_node(string str,int d,node *root)
{
	if(root==NULL)
		return NULL;

	if(d==str.length())
		return NULL;

	if(d==str.length()-1 && root->c==str[d])
		return root;

	if(str[d]==root->c)
		return get_node(str,d+1,root->middle);

	if(str[d]>root->c)
		return get_node(str,d,root->right);

	return get_node(str,d,root->left);


}


void getall(node *root,vector<string>& vec,string str="")
{
	if(root==NULL)
		return;

	getall(root->left,vec,str);

	getall(root->middle,vec,str+root->c);

	if(root->data!=0)
		vec.push_back(str+root->c);

	getall(root->right,vec,str);


}

void allwords(string prefix,node *root,vector<string>& str)
{
	node *temp=get_node(prefix,0,root);
	
	getall(temp->middle,str,prefix);

}






int _tmain(int argc, _TCHAR* argv[])
{


	vector<string> vet;

	node *root=NULL;

	insert("bajaj",&root,3,0);

	insert("basj",&root,3,0);

	insert("ritesh",&root,5,0);

	insert("komal",&root,7,0);

	insert("baj",&root,13,0);

	insert("abc",&root,13,0);

	insert("cas",&root,13,0);

	insert("basw",&root,3,0);


//	 getall(root,vet);

	
	cout<<getdata("ritesh",0,root);

	allwords("ba",root,vet);

	for(int i=0;i<vet.size();i++)
	{

		cout<<"  "<<vet[i];

	}


	return 0;
}

