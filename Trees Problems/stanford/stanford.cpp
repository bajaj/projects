// stanford.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#define nptr node*

using namespace std;



int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

struct node
{
	int data;
	node *left, *right;

	node(int x) :left(NULL), right(NULL)
	{
		data = x;
	}

};



node* insert(node* root, int data)
{
	if (root == NULL)           // return a single node
		return new node(data);
	else
	{     // recurse down the tree

		if (data <= root->data)
			root->left = insert(root->left, data);
		else
			root->right = insert(root->right, data);

		return root;  // return the unchanged node pointer
	}
}

node* build123(node* root)
{
	root = insert(root,4);
	root = insert(root, 2);
	root = insert(root, 5);
	return root;
}

int size(node* root)
{
	if (!root)
		return 0;
	else
		return 1 + size(root->left) + size(root->right);
}

int maxDepth(node* root)
{
	if (!root)
		return 0;
	else
		return 1 + max(maxDepth(root->left), maxDepth(root->right));

}

int minValue(nptr root)
{
	if (!root->left)
		return root->data;
	else
		return minValue(root->left);
}

int maxValue(nptr root)
{
	if (!root->right)
		return root->data;
	else
		return maxValue(root->right);

}


void printTree(nptr root)
{
	if (!root)
		return;
	
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);

}

void printPostTree(nptr root)
{
	if (root==NULL)
		return;

	printPostTree(root->left);
	printPostTree(root->right);
	cout << root->data << " ";

}

bool hasPathSum(nptr root, int sum)
{
	if (!root)
		return (sum == 0);

	return hasPathSum(root->left, sum - root->data) || hasPathSum(root->right, sum - root->data);

}

void printArry(int len, int arr[])
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << "->";
	cout << "\n";

}

void printPaths(node* root, int len, int path[])
{
	if (!root)		
		return;

	path[len++] = root->data;

	if (!root->left && !root->right)  // it is  leaf node
		printArry(len, path);         // print it
	else
	{
		printPaths(root->left, len, path);
		printPaths(root->right, len, path);
	}
}

void mirror(node* root)
{
	if (!root)
		return;

	node* temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirror(root->left);
	mirror(root->right);

}

void doubleTree(node* root)
{
	if (!root)
		return;

	doubleTree(root->left);
	doubleTree(root->right);

	node* temp = root->left;
	root->left = new node(root->data);
	root->left->left = temp;
}

int sameTree(nptr a, nptr b)
{
	if (!a && !b)
		return true;
	else if (a == NULL || b == NULL)
		return false;

	if (a->data == b->data)
		return sameTree(a->left, b->left) && sameTree(a->right, b->right);
	else
		return false;	

}

int countTree(int numKeys)
{
	if (numKeys <= 1)
		return 1;

	int sum = 0, left, right, root;

	for (root = 1; root <= numKeys; root++)
	{
		left = countTree(root - 1);   // 
		right = countTree(numKeys - root);

		sum += left*right;
	}

	return sum;
}

bool isBst1(node* root,int min,int max)
{
	if (!root)
		return true;
	
	if (root->data<min || root->data>max) return false;

	return isBst1(root->left, min, root->data) && isBst1(root->right, root->data + 1, max);
	
}

node* getHead(node* root)
{
	node* temp = NULL;
	while (root->left != temp)
		root = root->left;
	
	return root;
}

node* getTail(node* root)
{
	node* temp = NULL;
	while (root->right != temp)
		root=root->right;

	return root;
}

void join(node* a, node* b)
{
	a->right = b;
	b->left = a;
}


node* logic(node* root)
{

	if (root->left != NULL)
	{
		node* leftList = logic(root->left);
		node* tail = getTail(leftList);
		join(tail, root);
	}
	
	if (root->right != NULL)
	{
		node* rightList = logic(root->right);
		node* head = getHead(rightList);
		join(root, head);
	}
	
	return root;

}

nptr append(nptr a, nptr b)
{
	nptr aLast;
	nptr bLast;

	if (a == NULL)
		return b;
	if (b == NULL)
		return a;

	aLast = a->left;
	bLast = b->left;
	
	join(aLast, b);
	join(bLast, a);
	
	return a;

}

nptr treeToList(nptr root)
{
	nptr aList;
	nptr bList;

	if (root == NULL)return NULL;

	aList = treeToList(root->left);
	bList = treeToList(root->right);

	root->left = root;
	root->right = root;

	aList=append(aList, root);
	aList = append(aList, bList);

	return aList;
}



node* treetoList(node* root)
{
	root = logic(root);
	node* head = getHead(root);
	node* tail = getTail(root);

	head->left = tail;
	tail->right = head;
	return head;
}

void printList(node* head)
{
	node* temp=head;

	cout << "\n circular list is ";


	while (temp->right != head)
	{
		cout << temp->data << "->";
		temp = temp->right;
	}
	cout << temp->data;

}



int _tmain(int argc, _TCHAR* argv[])
{
	node* root=NULL;

	root=build123(root);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 5);
	root = insert(root,99);

	//printPostTree(root);
	cout << "\n";

//	cout << hasPathSum(root, 9) << " " << hasPathSum(root, 5) << " " << hasPathSum(root, 3) << " ";

	//int path[100];

	//printPaths(root, 0, path);

	//mirror(root);

//	doubleTree(root);

	//printTree(root);

	node* b = NULL;

	b = build123(b);
	//b = insert(b, 1);
//	b = insert(b, 3);

//	cout << "\n" << "is same tree " << sameTree(root, b);

//	cout << "\n" << countTree(4);

//	b->left->left = new node(1);
//	b->right->right = new node(6);
//	b->left->right = new node(3);

	//cout << "\n is bst " << isBst1(b, -1, 10000)<<"\n";

	//printTree(root);
	
//	node* head = treetoList(root);

	node* head = treeToList(root);
	printList(head);

	return 0;
}



