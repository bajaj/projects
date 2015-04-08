// CSEQ.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <string>

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


#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a, int b)
{
	return a>b ? a : b;
}

#define INT_MAX 2147483647 


int min(int a, int b)
{
	return a > b ? b : a;
}

//int nmax = 10000;
//int dp[10001][10001];
LL mod = 1000003;

long long degree(long long a, long long k, long long p) {
	long long res = 1;
	long long cur = a;

	while (k) {
		if (k % 2) {
			res = (res * cur) % p;
		}
		k /= 2;
		cur = (cur * cur) % p;
	}
	return res;
}

int get_degree(long long n, long long p) { // returns the degree with which p is in n!
	int degree_num = 0;
	long long u = p;
	long long temp = n;
	while (u <= temp) {
		degree_num += temp / u;
		u *= p;
	}
	return degree_num;
}

long long combinations(int n, int k, long long p) {
	int num_degree = get_degree(n, p) - get_degree(n - k, p);
	int den_degree = get_degree(k, p);
	if (num_degree > den_degree) {
		return 0;
	}
	long long res = 1;
	for (long long i = n; i > n - k; --i) {
		long long ti = i;
		while (ti % p == 0) {
			ti /= p;
		}
		res = (res *ti) % p;
	}
	for (long long i = 1; i <= k; ++i) {
		long long ti = i;
		while (ti % p == 0) {
			ti /= p;
		}
		res = (res * degree(ti, p - 2, p)) % p;
	}
	return res;
}



int main()
{
	inp_s; cinnull;

    #pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);

	

	/*FOR(i, 0, nmax)
		dp[i][0] = 1;

	FOR(i, 1, nmax)
		dp[0][i] = 0;
		*/

	/*FOR(i, 1, nmax)
	{
		FOR(j, 1, i)
		{
			dp[i][j] = (dp[i - 1][j - 1]+ dp[i - 1][j]) % mod;
		}
	}*/

	DRT()
	{
		LL n, l, r;

		cin >> n >> l >> r;

		LL ans = 0;

		LL total = r - l + 1;

	//	ans = n*total;  // for repetition 

		//		ans = dp[(total+n)%nmax][n]-1;
		
		ans = combinations(total + n, n, mod)-1;

		

		cout << ans<<"\n";
	}

	

	

	return 0;
}

