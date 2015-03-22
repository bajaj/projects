// bst2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;


struct node
{
	int data;
	node* left;
	node* right;
	int count;

	node(int d) :data(d), count(1)
	{
		left = NULL;
		right = NULL;
	}


};

int size(node* root);

node* insert_recursive(node* root, int data)
{
	if (root == NULL)
		return new node(data);

	if (root->data > data)
		root->left = insert_recursive(root->left, data);
	else
		root->right = insert_recursive(root->right, data);


	root->count = 1+size(root->left) + size(root->right);

	return root;

}




void display(node *root)
{
	if (root == NULL)
		return;

	display(root->left);
	cout << root->data<<" ";
	display(root->right);
}



node* min(node* root)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL)
		return root;

	return min(root->left);

}

node* floor(node* root,int data)
{
	if (root == NULL)
		return NULL;

	if (root->data == data)
		return root;

	if (root->data > data)
		return floor(root->left,data);

	node* t = floor(root->right, data);

	if (t != NULL)
		return t;
	else
		return root;
}

node* ceil(node* root, int data)
{
	if (root == NULL)
		return NULL;

	if (root->data == data)
		return root;

	if (root->data < data)
		return ceil(root->right, data);

	node* t = ceil(root->left, data);
 
	if (t != NULL)
		return t;
	else
		return root;
}

int count(node* root)
{
	if (root == NULL)
		return 0;

	root->count = count(root->left) + count(root->right) + 1;

	return root->count;

}

int size(node* root)
{
	if (root == NULL)
		return NULL;
	else
		return root->count;

}

int ranki(node* root, int data)
{
	if (root == NULL)
		return 0;

	if (root->data == data)
		return size(root->left);

	else if (root->data > data)
		return ranki(root->left, data);

	else return 1 + size(root->left) + ranki(root->right, data);
}

int contains(node* root, int data)
{
	if (root == NULL)
		return 0;

	return root->data == data ? 1 : (contains(root->left, data) || contains(root->right, data));
}

int range_count(node* root, int low, int high)
{
	if (contains(root, high)) return ranki(root, high) - ranki(root, low) + 1;
	else
	{
		return ranki(root, high) - ranki(root, low);
	}

}

void range_search(node* root, int low, int high)
{
	if (root == NULL)
		return;

	if (root->data >= low && root->data <= high)
	{
		range_search(root->left, low, high);
		cout << "  " << root->data << "  ";
		range_search(root->right, low, high);
	}

	if (root->data < low)
		range_search(root->right, low, high);

	if (root->data>high)
		range_search(root->left, low, high);
}



int _tmain(int argc, _TCHAR* argv[])
{
	node* root=NULL;

	root=insert_recursive(root, 11);
	root=insert_recursive(root, 4);
	root=insert_recursive(root, 12);
	root = insert_recursive(root, 8);
	root = insert_recursive(root, 9);


	display(root);

	cout << (ceil(root,10)->data);

	cout << "\n" << root->count;

	cout << "\n" << ranki(root, 15);


	cout << "\n"; range_search(root, 11, 13);


	return 0;
}

