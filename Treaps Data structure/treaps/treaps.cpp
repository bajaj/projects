// treaps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

typedef struct node{

	int val, prior, size;
	struct node *l, *r;

}node;

typedef node* pnode;

int sz(pnode t)
{
	return t ? t->size :0;
}

void updateSz(pnode t)
{
	if (t)
		t->size = sz(t->l) + 1 + sz(t->r);
}

void split(pnode t, pnode &l, pnode &r, int key)
{
	if (!t)
		l = r = NULL;
	else if (t->val <= key)
		split(t->r, t->r, r, key), l = t;
	else
		split(t->l, l, t->l, key), r = t;
	
	updateSz(t);
}

void merge(pnode &t, pnode l, pnode r)
{
	if (!l || !r)
		t = l ? l : r;
	
	if (l->prior > r->prior)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l,l,r->l), t = r;

	updateSz(t);
}

void insert(pnode& t, pnode it)
{
	if (!t)t = it;

	if (t->prior > it->prior)
		split(t, it->l, it->r, it->val), t = it;
	else
		insert(t->val <= it->val ? t->r : t->l, it);
	
	updateSz(t);
}

void erase(pnode& t, int key)
{
	if (!t)return;

	if (t->val == key)
	{
		pnode temp = t;
		merge(t, t->l, t->r); free(temp);
	}
	else
		erase(t->val <= key ? t->r : t->l, key);

	updateSz(t);
}

pnode init(int val)
{
	pnode ret = (pnode)malloc(sizeof(node));
	
	ret->val = val;
	ret->prior = rand();
	ret->size = 1;
	ret->l = ret->r = NULL;
	return ret;
}


int main()
{
	return 0;
}

