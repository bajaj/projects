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

long long invert_mod(long long k, long long m)
{
	if (m == 0) return (k == 1 || k == -1) ? k : 0;
	if (m < 0) m = -m;
	k %= m;
	if (k < 0) k += m;
	int neg = 1;
	long long p1 = 1, p2 = 0, k1 = k, m1 = m, q, r, temp;
	while (k1 > 0) {
		q = m1 / k1;
		r = m1 % k1;
		temp = q*p1 + p2;
		p2 = p1;
		p1 = temp;
		m1 = k1;
		k1 = r;
		neg = !neg;
	}
	return neg ? m - p2 : p2;
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
	long long denom = 1;
	for (long long i = 1; i <= k; ++i) {
		long long ti = i;
		while (ti % p == 0) {
			ti /= p;
		}
		denom = (denom * ti) % p;
	}
	res = (res * degree(denom, p - 2, p)) % p;	return res;
}

// Preconditions: 0 <= k <= min(n,p-1); p > 1 prime
long long choose_mod_two(long long n, long long k, long long p)
{
	// reduce n modulo p
	n %= p;
	// Trivial checks
	if (n < k) return 0;
	if (k == 0 || k == n) return 1;
	// Now 0 < k < n, save a bit of work if k > n/2
	if (k > n / 2) k = n - k;
	// calculate numerator and denominator modulo p
	long long num = n, den = 1;
	for (n = n - 1; k > 1; --n, --k)
	{
		num = (num * n) % p;
		den = (den * k) % p;
	}
	// Invert denominator modulo p
	den = invert_mod(den, p);
	return (num * den) % p;
}

long long choose_mod_one(long long n, long long k, long long p)
{
	// For small k, no recursion is necessary
	if (k < p) return choose_mod_two(n, k, p);
	long long q_n, r_n, q_k, r_k, choose;
	q_n = n / p;
	r_n = n % p;
	q_k = k / p;
	r_k = k % p;
	choose = choose_mod_two(r_n, r_k, p);
	// If the exponent of p in choose(n,k) isn't determined to be 0
	// before the calculation gets serious, short-cut here:
	/* if (choose == 0) return 0; */
	choose *= choose_mod_one(q_n, q_k, p);
	return choose % p;
}



long long factorial_exponent(long long n, long long p)
{
	long long ex = 0;
	do
	{
		n /= p;
		ex += n;
	} while (n > 0);
	return ex;
}

long long choose_mod(long long n, long long k, long long p)
{
	// We deal with the trivial cases first
	if (k < 0 || n < k) return 0;
	if (k == 0 || k == n) return 1;
	// Now check whether choose(n,k) is divisible by p
	//if (factorial_exponent(n,p) > factorial_exponent(k,p) + factorial_exponent(n - k,p)) return 0;
	// If it's not divisible, do the generic work
	return choose_mod_one(n, k, p);
}


LL powmod(LL x, LL e, LL p) {
	if (e == 0) return 1;
	if (e & 1) return (long long)x * powmod(x, e - 1, p) % p;
	long long rt = powmod(x, e / 2, p);
	return rt * rt % p;
}

LL binom_coeff_mod_prime(LL n, LL k, LL p) {
	long long res = 1;
	while (n || k) {
		LL N = n % p, K = k % p;
		for (LL i = N - K + 1; i <= N; ++i)
			res = res * i % p;
		for (LL i = 1; i <= K; ++i)
			res = res * powmod(i, p - 2, p) % p;
		n /= p;
		k /= p;
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
		
		//ans = combinations(total + n, n, mod)-1;

		ans = (choose_mod(total + n, n, mod) - 1)%mod;

	//	ans = binom_coeff_mod_prime(total + n, n, mod) - 1;

		cout << ans<<"\n";
	}

	

	

	return 0;
}

