// XOR_TRIE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "vector"
#include "algorithm"

#define inp_s ios_base::sync_with_stdio(false);
#define cinnull cin.tie(NULL);
#define MAX 0x7fffffff;



using namespace std;

struct node
{
	node* link[2];
	int val;

	node()
	{
		link[0] = NULL;
		link[1] = NULL;
		val = MAX;
	}

	~node()
	{
		delete[] link;
	}

};

inline void d2b(int no, bool *binarr)
{
	for (int i = 0; i < 32; i++)
	{
		binarr[i] = no & (1 << i) ? 1 : 0;
	}
}


class trie
{
	node* root;

public:
	trie(node* x=NULL)
	{
		if (x == NULL)
			root = new node();
		else
			root = x;

	}

	void add(int no, bool* arr, int d, node* ptr)
	{
		if (d < 0)
			return;
		
		if (ptr->link[arr[d]] == NULL)
			ptr->link[arr[d]] = new node();

		if (d == 0)
		{
			ptr->link[arr[d]]->val = no;
			return;
		}
		add(no, arr, d - 1, ptr->link[arr[d]]);
	}

	int getit(int no, bool* arr, int d, node *ptr)
	{
		if (d+1 < 0 || ptr==NULL)
			return -1;

		if (d + 1 == 0)
			return ptr->val;

		if (ptr->link[arr[d]] == NULL)
			return -1;

		return getit(no, arr, d - 1, ptr->link[arr[d]]);
	}

	void insert(int no)
	{
		bool binarr[32];
		d2b(no, binarr);
		add(no, binarr, 31, root);
	}

	int get(int no)
	{
		bool binarr[32];
		d2b(no, binarr);
		return getit(no, binarr, 31, root);
	}

	// returns an integer with max xor 

	int maxit(bool *binarr, int d, node* ptr) 
	{
		if (ptr == NULL || d < 0)
			return -1;

		if (d == 0)
		{
			if (ptr->link[!binarr[d]] != NULL)
				return ptr->link[!binarr[d]]->val;

			else
				return ptr->link[binarr[d]]->val;

		}

		if (ptr->link[!binarr[d]] != NULL)
			return maxit(binarr, d - 1, ptr->link[!binarr[d]]);
		else
			return maxit(binarr, d - 1, ptr->link[binarr[d]]);

	}

	int getmax(int no)
	{
		bool binarr[32];
		d2b(no, binarr);

		return maxit(binarr, 31, root);
	}


};

struct nodec{
	int count[2];  //count[0]  left count & count[1] is the right count
	int val;
	nodec* link[2];
	nodec()
	{
		count[0] = 0;
		count[1] = 0;
		val = 0;
		link[0] = NULL;
		link[1] = NULL;
	}

};

class triec 
{
	nodec* root;

	long long getcount(bool* binarrp,bool* binarrq,int d,int count,nodec* ptr);
	void addit(int no,bool* binarr,int d,nodec* ptr);

public:
	triec(nodec* x=NULL)
	{
		x ? root = x : root = new nodec();
	}

	long long count(int p, int k)
	{
		bool binarrp[32], binarrk[32];

		d2b(p, binarrp);
		d2b(k, binarrk);

		return getcount(binarrp, binarrk, 31, 0, root);
	}

	void add(int no)
	{
		bool binarr[32];
		d2b(no, binarr);
		addit(no,binarr, 31, root);
	}

};

void triec::addit(int no,bool* binarr, int d, nodec* ptr)
{
	if (d < 0)
		return;	

	if(ptr->link[binarr[d]] == NULL)
	{
		ptr->link[binarr[d]] = new nodec;
	}

	ptr->count[binarr[d]] += 1;

	if (d == 0)
	{
		ptr->link[binarr[d]]->val = no;
		return;
	}

	addit(no, binarr, d - 1, ptr->link[binarr[d]]);
}

long long triec::getcount(bool* p, bool* q, int d, int count, nodec* ptr)
{
	if (d < 0)
	{
		return count;
	}

	if (p[d] == 1 && q[d] == 1)
	{
		if (ptr->count[0] > 0)
			return getcount(p, q, d - 1, ptr->count[1] + count, ptr->link[0]); // going left "0 link" adding the right count
		else
			return count+ptr->count[1];
	}

	if (p[d] == 0 && q[d] == 1)
	{
		if (ptr->count[1] > 0)
			return getcount(p, q, d - 1, ptr->count[0] + count, ptr->link[1]); // going right "1 link" adding the left count
		else
			return count + ptr->count[0];
	}

	if (p[d] == 1 && q[d] == 0)
	{	
		if (ptr->count[1] > 0)
			return getcount(p, q, d - 1, count, ptr->link[1]); // going right "1 link" NOT adding the left count
		else
			return count;
	}

	if (p[d] == 0 && q[d] == 0)
	{
		if (ptr->count[0] > 0)
			return getcount(p, q, d - 1,count, ptr->link[0]); // going left "0 link" NOT adding the right count
		else
			return count;
	}

}

struct nodex{     
	int count[2];  //count[0]  left count & count[1] is the right count
	int val;
	nodex* link[2];
	vector<int> v;
	nodex()
	{
		count[0] = 0;
		count[1] = 0;
		val = -1;
		link[0] = NULL;
		link[1] = NULL;
	}

};

class triex
{
	nodex* root;
	int index;  // for storing in the vector of each node == v.size()
	vector<int> v;

	void addit(int no, bool* binarr, int d, nodex* ptr);

	int getmaxit(bool* binarr, int d, nodex* ptr,int l,int r);

	bool checkrange(int l, int r, vector<int>& v)
	{
		vector<int>::iterator low, up;
		
		low = lower_bound(v.begin(), v.end(),l);
	//	up = lower_bound(v.begin(), v.end(), r);

		int lowp = low - v.begin();
	//	int upp = up - v.begin();

		if (lowp==v.size())   // redundant
			return false;

		if (v[lowp] >= l && v[lowp] <= r)
			return true;
		else
			return false;
	}


	void deleteno(bool* binarr, int d,int ind, nodex* ptr);

	void deletenor(bool* binarr, int d, int ind, nodex* ptr);

	int getlessthanx(bool* binarr, int d, int l, int r, int x, nodex* ptr);

	int getlesscount(int l, int r, vector<int>& v);  //no of index in v which lies in the range l,r

	int getkelement(int l, int r, int k, nodex* ptr);

public:

	triex(nodex* x=NULL)
	{
		x ? root = x : root = new nodex;
		index = 0;

	}


	void add(int no)
	{
		bool binarr[32];
		d2b(no, binarr);

	addit(no, binarr, 31, root);
	v.push_back(no);
	index++;
	}

	int getmax(int x,int l,int r) // On the interval L..R find a number y, to maximize (x xor y).
	{
		bool binarr[32];
		d2b(x, binarr);

		return getmaxit(binarr, 31, root,l,r);
	}
	void deletek(int k)  //Delete last k numbers in the array
	{
		int x;
		bool binarr[32];
		while (k--)
		{
			int x = v[--index];
			
			d2b(x, binarr);
			deletenor(binarr, 31, index, root);   // index=v.size

			v.pop_back();
		//	index--;
		}

	}

	int query3(int l, int r, int x) //On the interval L..R, count the number of integers less than or equal to x.
	{
		bool binarr[32];
		d2b(x, binarr);
		return 	getlessthanx(binarr,31,l,r,x,root);
	}

	int query4(int l, int r, int k)
	{
		return getkelement(l, r, k, root);
	}

};

int triex::getkelement(int l, int r, int k, nodex* ptr)
{
	int temp = k;
	
	for (int i = 31; i >= 0; i--)
	{
		int lcount = 0;

		
		if (ptr->link[0]!=NULL)
		lcount = getlesscount(l, r, ptr->link[0]->v);

		if (lcount < temp)
		{
			ptr = ptr->link[1];
			temp -= lcount;
		}
		else
		{
			ptr = ptr->link[0];
		}

	}
		
	return ptr->val;
}

void triex::deleteno(bool* binarr, int d,int ind, nodex* ptr)
{
	for (int i = d; i >= 0; i--)
	{
		ptr->v.erase(remove(ptr->v.begin(), ptr->v.end(), ind), ptr->v.end());
		ptr->count[binarr[i]] -= 1;
		ptr = ptr->link[binarr[i]];
	}
	ptr->val = -1;
}

void triex::deletenor(bool* binarr, int d, int ind, nodex* ptr)
{

	if (d < 0 || ptr == NULL)
		return;

	//ptr->v.erase(remove(ptr->v.begin(), ptr->v.end(), ind), ptr->v.end());
	ptr->v.pop_back();
	ptr->count[binarr[d]] -= 1;

	if (d == 0)
	{
		ptr->link[binarr[d]]->v.pop_back();

		if (ptr->link[binarr[d]]->v.size() == 0)
		{
			delete ptr->link[binarr[d]];
			ptr->link[binarr[d]] = NULL;
		}

		return;
	}

	deletenor(binarr, d - 1, ind, ptr->link[binarr[d]]);

	if (ptr->link[binarr[d]]->v.size() == 0)
	{
		delete ptr->link[binarr[d]];
		ptr->link[binarr[d]] = NULL;
	}

}

void triex::addit(int no, bool* binarr, int d, nodex* ptr)
{
	if (d < 0)
		return;

	if (ptr->link[binarr[d]] == NULL)
		ptr->link[binarr[d]] = new nodex;

	ptr->count[binarr[d]] += 1;
	ptr->v.push_back(index);

	if (d == 0)
	{
		ptr->link[binarr[d]]->val = no;
		ptr->link[binarr[d]]->v.push_back(index);
		return;
	}

	addit(no, binarr, d - 1, ptr->link[binarr[d]]);
}

int triex::getmaxit(bool* binarr, int d, nodex* ptr,int l,int r)
{
	if (ptr == NULL || d < 0)
		return -1;

	if (d == 0)
	{
		if (ptr->link[!binarr[d]] != NULL)
			return ptr->link[!binarr[d]]->val;
		else
			return ptr->link[binarr[d]]->val;
	}

	if (ptr->link[!binarr[d]] != NULL && checkrange(l, r, ptr->link[!binarr[d]]->v))
	{
		return getmaxit(binarr, d - 1, ptr->link[!binarr[d]], l, r);
	}
	else
		return getmaxit(binarr, d - 1, ptr->link[binarr[d]], l, r);

}

int triex::getlesscount(int l, int r, vector<int>& v)
{
	vector<int>::iterator low, up;

	low = lower_bound(v.begin(), v.end(), l);
	up = lower_bound(v.begin(), v.end(), r);

	int lowp = low - v.begin();
	int upp = up - v.begin();

	//if (lowp >= l && lowp <= r)
	if (lowp != v.size() && v[lowp]>=l && v[lowp]<=r)
	{
		if (upp!=v.size() && v[upp] == r)
			return upp - lowp + 1;
		else
			return upp - lowp;
	}
	else
		return 0;

}

int triex::getlessthanx(bool* binarr, int d, int l, int r, int x, nodex* ptr) //On the interval L..R, count the number of integers less than or equal to x.
{
	int ans = 0;

	for (int i = d; i >= 0; i--)
	{
		if (ptr == NULL)
			break;

		if (binarr[i] == 1)
		{
			if (ptr->link[0] != NULL && i<=20)
			ans += getlesscount(l, r,ptr->link[0]->v);  
			
			ptr=ptr->link[1];
		}
		else
		{
			ptr = ptr->link[0];
		}

	}
	if (ptr!=NULL)// && ptr->v[0]>=l && ptr->v[0]<=r && ptr->val == x) 
	{
		//ans += 1;
		ans += getlesscount(l, r, ptr->v);   // for duplicates  ptr->val==x is obvious
	}

	return ans;
}

int maxi(int a, int b)
{
	return a > b ? a : b;

}

int main()
{	
	inp_s; cinnull;

	triex t;
	int L, R, x, k, M, query;

	cin >> M;

	while (M--)
	{
		cin >> query;

		switch (query)
		{
		case 0:
			cin >> x;
			t.add(x);
			break;

		case 1:
			cin >> L >> R >> x;
			cout << t.getmax(x, L-1, R-1)<<"\n";
			break;

		case 2:
			cin >> k;
			t.deletek(k);
			break;
		
		case 3:
			cin >> L >> R >> x;
			cout << t.query3(L - 1, R - 1, x)<<"\n";
			break;
		
		case 4:
			cin >> L >> R >> k;
			cout << t.query4(L - 1, R - 1, k) << "\n";
			break;

		default:
		//	cout << "wrong input " << "\n";
			break;
		}


	}

	/*int ti;

	cin >> ti;

	while (ti--)
	{
		int x,k,pre = 0, n;

		long long ans = 0;

		cin >> n >> k;

		triec t;
		t.add(0);
	
		while (n--)
		{
			cin >> x;
			pre ^= x;

			ans += (long long)t.count(pre, k);
			t.add(pre);
		}

		cout << ans << "\n";
	}

	
	*/


	/*
		int arr[] = { 10, 20, 30, 40 };
	vector<int> v(arr,arr+4);


	vector<int>::iterator low, up;

	int c; cin >> c;

	low = lower_bound(v.begin(), v.end(), c);
	up = upper_bound(v.begin(), v.end(), c);

	cout << " lower b position " << (low - v.begin());
	cout << "\n upper at position" << (up - v.begin());
	*/




	/* cout << "enter the total no \n";
	cin >> n;

	int temp = n;

	int x;

	cout << "enter the numbers \n";

	while (n--)
	{
		cin >> x;
		t.insert(x);
	}
	
	cout << " enter nos to get max \n";

	int max=-1, a, b,y;

	while (temp--)
	{
		cin >> x;

		//cout << t.get(x) << "\n";
		y = t.getmax(x);

		if (max > x^y)
		{
			max = x^y;
			a = x;
			b = y;
		}
		
		cout << "max " << max << "  " << a << "  " << b;

	}
	*/


	return 0;
}

