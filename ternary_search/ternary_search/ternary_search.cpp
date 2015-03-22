// ternary_search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;


struct node
{
	int val;
	char c;
	node *left, *mid, *right;

	node()
	{
		mid = NULL;
		left = NULL;
		right = NULL;
		val = 0;
	}

};


class ternary
{
private:
	node* root;	

	node* put(node* root, string key, int val, int d,int len);

	node* get(node* root, string key, int d, int len);

	void allkey(node* root, string s);

	int longprefix(node* root, string key, int d, int len, int x);

public:

	ternary()
	{
		root = NULL;
	}

	void put(string key, int val)
	{
		int len = key.length();
		root = put(root, key, val, 0,len);

	}

	int get(string key)
	{
		node *temp = get(root, key, 0, key.length());

		if (temp == NULL)
		{
			cout << "NO value ";
			return 0;
		}
		else
			return temp->val;

	}

	void allkey()
	{
		allkey(root, "");
	}

	void allprefix(string str)
	{
		node* temp = get(root, str,0, str.length());

		//cout << temp->c;

		allkey(temp->mid,str);

	}

	string longprefix(string key)
	{
		int len = longprefix(root, key, 0, key.length(), 0);

		return key.substr(0, len);
	}

};


int ternary::longprefix(node* root, string key, int d, int len, int x)
{
	if (root == NULL)
		return x;

	char c = key[d];

	if (c > root->c)
		return longprefix(root->right, key, d, len, x);
	
	else if (c < root->c)
		return longprefix(root->left, key, d, len, x);

	else if (d<len-1)
	{
		if (root->val != 0)
			x = d + 1;

		return longprefix(root->mid, key, d + 1, len, x);
	}
	else
	{
		if (root->val != 0)
			return x=d+1;
		else
			return x;
	}


}


void ternary::allkey(node* root,string s)
{
	if (root == NULL)
		return;

	if (root->val != 0)
	{
		cout << s + root->c << "  ";
	}


	allkey(root->left, s);
	allkey(root->mid, s + root->c);
	allkey(root->right, s);


}


node* ternary::put(node *root, string key, int val, int d, int len)
{
	char c = key[d];
	if (root == NULL)
	{
		root = new node();
		root->c = c;
	}

	if (c > root->c)
	{
		root->right = put(root->right, key, val, d, len);
	}
	else if (c < root->c)
	{
		root->left = put(root->left, key, val, d, len);
	}
	else if (d<len-1)
	{
		root->mid = put(root->mid, key, val, d + 1, len);
	}
	else
	{
		root->val = val;
	}

	return root;

}

node* ternary::get(node* root, string key, int d, int len)
{
	if (root == NULL)
		return NULL;

	char c = key[d];

	if (c < root->c)
	{
		return get(root->left, key, d, len);
	}
	else if (c > root->c)
	{
		return get(root->right, key, d, len);
	}
	else if (d < len - 1)
		return get(root->mid, key, d + 1, len);
	else
		return root;

}




int _tmain(int argc, _TCHAR* argv[])
{
	ternary t;

	t.put("she", 4);
	t.put("shells", 16);
	t.put("sells", 61);
	t.put("by", 64);
	t.put("shore", 36);
	t.put("the", 62);

//	cout << t.get("shee");

//	t.allkey();

	cout << "\n";

//	t.allprefix("s");

	cout << t.longprefix("b");


	return 0;
}

