// cool.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

struct node
{
	unsigned long key;
	int data;
	node *left;
	node *right;

	node(unsigned long key2,int data2)
	{
		key = key2;
		data = data2;
	}

};


node* contains(node* root, int hi)
{
	if (root == NULL)
		return NULL;

	if (root->key == hi)
		return root;
	else if (root->key<hi)
		return contains(root->right, hi);

	return contains(root->left, hi);

}

node* insertr(node *root, int key)
{

	if (root == NULL)
		return new node(key,1);

	else
	{
		

		if (root->key<key)

		{
			root->right = insertr(root->right, key);

		}
		else
			root->left = insertr(root->left, key);

	}

	return root;
}




int main() {
	
	node *root;

	unsigned long n, m,age;

	cin>>n>> m;

	for (int i = 0; i < n; i++)
	{
		cin >> age;

		node* temp;
		if (temp=contains(root, age))
		{
			temp->data = temp->data + 1;
		}
		else
		{
			root=insertr(root, age);
		}

	}



	return 0;
}

/*
#include "stdafx.h"

#include <iostream>
using namespace std;
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <map>
#include <iterator>


int _tmain(int argc, _TCHAR* argv[])
{

	map<unsigned long int, int> ma;

	unsigned long int n, m,age;

	map<unsigned long int,int>::iterator it;

	cin >> n >> m;

	for (int i = 0; i<n; i++)
	{
		cin >> age;
		ma[age] = 1;
	}


	it = max_element(ma.begin(), ma.end);



	//   cout << "Hello World!" << endl;
	return 0;
}








*/