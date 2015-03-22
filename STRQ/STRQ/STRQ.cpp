// STRQ->cpp : Defines the entry point for the console application->

#include "stdafx.h"
#include <iostream>

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>



using namespace std;


#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)


//#include <bits/stdc++.h>

typedef long long int LL;


#define DRT() int test_case; cin>>test_case;while(test_case--)

#define cscanf(x) scanf("%d", &x)


int getcount(map<char, vector<int> > &m, char c, int l, int r, int flag)
{
	vector<int>::iterator low, up;

	low = lower_bound(m[c].begin(), m[c].end(), l);

	up = lower_bound(m[c].begin(), m[c].end(), r);

	int lowp = low - m[c].begin();
	int upp = up - m[c].begin();

	if (low == m[c].end())
		return 0;

	if (up == m[c].end())
		return m[c].size() - lowp;



	if (*low >= l && *low <= r)
	{
		if (*up == r)
		{
			if (flag == 0)
				return upp - lowp;
			else
				return upp - lowp + 1;
		}
		else if (*up > r)
			return upp - lowp;

	}
	else
		return 0;


}

char ch[4] = { 'c', 'h', 'e', 'f' };




struct node
{
	unordered_map<char, LL> charc;
	unordered_map<string, LL> strc;

	node()
	{
		charc['c'] = 0; charc['h'] = 0; charc['e'] = 0; charc['f'] = 0;

		strc["ch"] = 0; strc["ce"] = 0; strc["cf"] = 0;
		strc["ec"] = 0; strc["eh"] = 0; strc["ef"] = 0;
		strc["hc"] = 0; strc["he"] = 0; strc["hf"] = 0;
		strc["fc"] = 0; strc["fe"] = 0; strc["fh"] = 0;
	}
};



int main()
{
	inp_s; cinnull;

	string p;
	cin >> p;

	//	map<char, vector<int> > m;

	LL q;

	LL size = p.length();

	/*	for (int i = 0; i < size; i++)
	{
	m[p[i]].push_back(i+1);
	}
	*/

	node* arr = new node[size];

	//int *arr=new int[30 * 1000001];

	//arr[30000000] = 1;



	arr[0].charc[p[0]] = 1;

	string stis[4] = { "c", "h", "e", "f" };


	unordered_map<char, string> sti;

	sti['c'] = "c";
	sti['h'] = "h";
	sti['e'] = "e";
	sti['f'] = "f";

	//cout << p[0];

	for (LL i = 1; i < size; i++)
	{
		arr[i].charc = arr[i - 1].charc;

		arr[i].charc[p[i]] += 1;

		arr[i].strc = arr[i - 1].strc;

		string stic = sti[p[i]];

		for (int j = 0; j < 4; j++)
		{
			if (ch[j] == p[i]);
			else
			{
				arr[i].strc[stis[j] + stic] += arr[i - 1].charc[ch[j]];
			}

		}

	}


	cin >> q;

	while (q--)
	{
		char s, e; LL l, r;
		cin >> s >> e >> l >> r;

		l--; r--;

		LL ans = 0;

		string se = sti[s] + sti[e]; //string(1, s) + string(1, e);

		if (l == 0)
		{
			ans = arr[r].strc[se];
		}
		else
		{
			ans = arr[r].strc[se];

			//ans = ans - arr[l - 1].charc[s] * arr[r].charc[e];

			ans = ans - arr[l].strc[se] - (arr[l - 1].charc[s] * (arr[r].charc[e] - arr[l].charc[e]));
		}

		//	cout << getcount(m, s, l, r, 0)*getcount(m,e,l,r,1);
		if (ans > 0)
			cout << ans << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}