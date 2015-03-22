// xor_trie_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<cstdio>
#include<vector>
#include<algorithm>
#include "iostream"
//#define getchar_unlocked() getc(stdin)
#define total(arr)  upper_bound(arr.begin(), arr.end(), qe) - lower_bound(arr.begin(), arr.end(), qs)
using namespace std;

struct trie
{
	vector<int> v;
	trie *l, *r;

}*root;

int value, pos, qe, qs, ans;
int v[500000];
vector<int>::iterator it;

inline int inp()
{
	int x;
	cin>>x;
	return x;
	/*register int noRead = 0;
	register char p = getchar_unlocked();
	for (; p<48 || p>57; p = getchar_unlocked());
	while (p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0'); p = getchar_unlocked(); }
	return noRead;*/
}


bool present(vector<int> &v)
{
	if (v.empty())
		return false;
	it = lower_bound(v.begin(), v.end(), qs);
	if (it != v.end() && *it >= qs && *it <= qe)
		return true;
	return false;
}

trie *ins(trie *a, int mask)
{
	if (a == NULL)
	{
		a = new trie();
		a->l = a->r = NULL;
	}

	a->v.push_back(pos);

	if (mask < 2)
		return a;

	if (value & (mask >> 1))
	{
		a->r = ins(a->r, mask >> 1);
	}

	else
	{
		a->l = ins(a->l, mask >> 1);
	}
	return a;
}

void del(trie *a, int mask)
{
	a->v.pop_back();
	if (mask < 2)
		return;
	if (value & (mask >> 1))
	{
		del(a->r, mask >> 1);
	}

	else
	{
		del(a->l, mask >> 1);
	}
}

int find_xor(trie *a, int mask)
{
	if (a->v.size() == 1)
		return a->v[0];
	if (mask < 2)
		return a->v[0];

	if (value & (mask >> 1))
	{
		if (a->l && present(a->l->v))
		{
			return find_xor(a->l, mask >> 1);
		}

		else
		{
			return find_xor(a->r, mask >> 1);
		}
	}

	else
	{
		if (a->r && present(a->r->v))
		{
			return find_xor(a->r, mask >> 1);
		}

		else
		{
			return find_xor(a->l, mask >> 1);
		}

	}
}

int count_node(trie *a, int mask)
{
	if (a == NULL)
		return 0;
	if (mask < 2)
		return total(a->v);

	if (value & (mask >> 1))
	{
		return ((a->l) ? total(a->l->v) : 0) + count_node(a->r, mask >> 1);
	}

	else
		return count_node(a->l, mask >> 1);
}

int kth(trie *a, int mask)
{
	if (a->v.size() == 1)
		return a->v[0];
	if (mask < 2)
		return a->v[lower_bound(a->v.begin(), a->v.end(), qs) - a->v.begin()];
	int l = (a->l) ? total(a->l->v) : 0;
	if (l >= value)
	{
		return kth(a->l, mask >> 1);
	}

	else
	{
		value -= l;
		return kth(a->r, mask >> 1);
	}
}

void print(trie *a, int mask)
{
	for (int i = 0; i < a->v.size(); i++)
		printf("%d ", a->v[i]);
	printf("\n");
	if (mask < 2)
		return;
	if (value & (mask >> 1))
	{
		printf("right\n");
		print(a->r, mask >> 1);
	}
	else
	{
		printf("left\n");
		print(a->l, mask >> 1);
	}
}

int main()
{
	root = NULL;
	int m, t, x, i, out;
	m = inp();
	pos = 0;
	while (m--)
	{
		t = inp();
		switch (t)
		{
		case 0: value = inp();
			v[pos] = value;
			pos++;
			root = ins(root, 1 << 19);
			break;

		case 1: qs = inp();
			qe = inp();
			value = inp();
			printf("%d\n", v[find_xor(root, 1 << 19) - 1]);
			break;

		case 2: x = inp();
			while (x--)
			{
				value = v[--pos];
				del(root, 1 << 19);
			}
			break;

		case 3: qs = inp();
			qe = inp();
			value = inp();
			printf("%d\n", count_node(root, 1 << 19));
			break;

		case 4: qs = inp();
			qe = inp();
			value = inp();
			printf("%d\n", v[kth(root, 1 << 19) - 1]);
			break;
		}
	}
	return 0;
}
