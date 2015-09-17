// swiggy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define MAX 1000

struct node
{
	int left,
		right,
		parent;

	node()
	{
		left = right = parent = 0;
	}

};

node* arr[MAX];
int marked[MAX];
int cnt = 0;
bool error[7] = { 0 };
int root = 0;

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = NULL;
		marked[i] = 0;

		if (i < 7)
			error[i] = 0;
	}
	cnt = 0;
	root = 0;
}

bool checkE1(int p,int c)
{
	if (!arr[p])
		return false;

	if (arr[p]->left && arr[p]->right)
		return true;

	return false;

}

bool checkE2(int p, int c)
{
	if (!arr[p]) // || !arr[c])
		return false;
	
	if (arr[p]->left == c || arr[p]->right==c)
		return true;

	return false;
}

inline void fillerror(int i,bool val)
{
	error[i] = val;
}

inline void countNodes(int p, int c)
{
	if (!arr[p])
		cnt++;
	if (!arr[c])
		cnt++;

}

void insertLogic(int p, int c)
{
	if (!arr[p])
		arr[p] = new node();
	
	if (!arr[c])
		arr[c] = new node();

	arr[c]->parent = p;

	if (!arr[p]->left)
		arr[p]->left = c;
	else
		arr[p]->right = c;

	if (!root)
		root = p;
	else
	{
		if (root == c)
			root = p;
	}

}

bool checkE5(int p, int c)
{
	if (!arr[c])
		return false;

	if (p != arr[c]->parent)
		return true;

	return false;
}


void insert(int p, int c)
{
	bool e1 = checkE1(p, c);
	bool e2 = checkE2(p, c);
	bool e5 = checkE5(p, c);
	// multiple parent

	fillerror(1, e1);
	fillerror(2, e2);
	fillerror(5, e5);

	if (!e1 && !e2 && !e5)
	{
		countNodes(p, c);
		insertLogic(p, c);
	}

}

void dfs(int i, bool& isCycle)
{
	if (!i)
		return;

	marked[i] = 1;

	if (!marked[arr[i]->left])
		dfs(arr[i]->left, isCycle);
	else
		isCycle = 1;

	if (!marked[arr[i]->right])
		dfs(arr[i]->right, isCycle);
	else
		isCycle = 1;
}

void checkE3AndE4()     // dfs
{
	bool e3 = 0;
	dfs(root, e3);
	fillerror(3, e3);

	bool e4 = 0;

	for (int i = 1; i < MAX; i++)
	{
		if (arr[i] && !marked[i])
		{
			e4 = 1;
			break;
		}
	}
	fillerror(4, e4);
}

string errMsg[] = { "x", "E1", "E2", "E3", "E4","E5"};

bool printError()
{
	for (int i = 5; i>=1; i--)
	{
		if (error[i])
		{
			cout << errMsg[i];
			return true;
		}
	}

	return false;
}

void printOutput(int root)
{
	if (!root)
	{
		return;
	}
	node* temp = arr[root];

	cout << "(" << root;

	printOutput(temp->left);
	printOutput(temp->right);
	cout << ")";
}


int _tmain(int argc, _TCHAR* argv[])
{
	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);

	int t;
	cin >> t;

	while (t--)
	{
		init();
		int notuple;
		cin >> notuple;

		for (int i = 0; i < notuple; i++)
		{
			int p, c;
			cin >> p >> c;
			insert(p, c);
		}

			checkE3AndE4();

			if (!printError())
				printOutput(root);
			
			cout << "\n";
		

	}


	return 0;
}

