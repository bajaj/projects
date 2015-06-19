// fenwick tree.cpp : Defines the entry point for the console application.
//
//http://static.aminer.org/pdf/PDF/001/073/976/a_new_data_structure_for_cumulative_frequency_tables.pdf

#include "stdafx.h"
#include "iostream"
#include "algorithm"
using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

typedef long long int LL;


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define rdarr(a,n) REP(i,n) cin >> a[i];


#define LSB(x) ( x & -x)
#define logSize 10

LL tree[(1 << logSize) + 1];
int n = (1 << logSize);

void update(int index, LL value)
{
	while (index <= n)
	{
		tree[index] += value;
		index += LSB(index);
	}
}

LL get(int index)       // get an cumulative frequency
{
	LL sum = 0;

	while (index > 0)
	{
		sum += tree[index];
		index -= LSB(index);
	}
	return sum;
}

int getIndividualfreq(int index)
{
	int val = tree[index];
	int parent = index - LSB(index); 
	
	index = index - 1;            // predecessor

	while (index != parent)
	{
		val -= tree[index];
		index = index - LSB(index);
	}
	return val;
}

int getIndex(int cumFreq)
{
	int idx = 0,tidx, mask = n;

	while (mask && idx<n)
	{
		tidx = idx + mask;

		if (cumFreq >= tree[tidx])
		{
			idx = tidx;
			cumFreq -= tree[tidx];
		}
		mask >>= 1;;
	}
	return idx;
}

pair<int, int> pi[1001],a[1001];

//int a[1001], b[1001];

int index[10001];

int main()
{

	inp_s; cinnull;

	#pragma warning (disable : 4996)
	//freopen("input.txt", "r", stdin);

	freopen("A-large-practice.in", "r", stdin);

	freopen("output.out", "w", stdout);

	/*FOR(i,1,100)
		update(i, i);

	
	cout << get(3);

	cout << "\n" << getIndex(get(24));

	cout << "\n" << getIndividualfreq(3*/
	int caseId = 1;

	DRT()
	{
		
		LL ans = 0;

		cin >> n;

		REP(i, n)
		{
			cin >> pi[i].first;
			cin >> pi[i].second;
			
			tree[i + 1] = 0;

		}

	sort(pi, pi + n);

		REP(i, n)
		{
			a[i].first= pi[i].second;
			a[i].second = i + 1;
		}

		sort(a, a + n);

		REP(i, n)
		{
			index[a[i].first] = i + 1;
		}

		REP(i, n)
		{
			a[i].second = index[pi[i].second];
		}

		FORD(i, n - 1, 0)
		{
			
			ans += get(a[i].second);
			update(a[i].second,1);
		}

		cout << "Case #" << caseId << ":" << " " << ans << "\n";
		caseId++;
	}



	return 0;
}

