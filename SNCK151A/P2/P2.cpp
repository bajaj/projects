#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define mod 1000000007
typedef long long li;
using namespace std;

typedef struct data
{
	li q;
	li r;
} data;

/*class comparison		//for Priority Queue
{
public :
bool operator()(customer a,customer b)
{
int pra=0,prb=0;
pra=a.next;
prb=b.next;
if(pra<prb)
return true;
else
return false;
}
};

int comp(const void *a, const void *b)
{
data m = *((data *)a);
data n = *((data *)b);
if(m.a>n.a)
return 1;
else if(m.a<n.a)
return -1;
else if(m.a==n.a)
{
if(m.d>n.d)
return 1;
else
return -1;
}
}
int exp(int x, int y)
{
if(y==0)
return 1;
int z=0;
z=exp(x,y/2);
z=z*z;
if((y%2)==1)
z=z*x;
return z;
}*/

/*Disjoint-Set Data Structure*/
/*vector<int> L;
void Make_Set(int N,int S[])
{
L.resize(N);
int i=0;
for(i=0;i<N;i++)
{
L[S[i]]=S[i]);
}
}

void union_set(int x, int y)
{
L[x]=y;
}

int find_set(int x)		//with path compression
{
if(x==L[x])
return x;
int root;
root=find_set(L[x]);
L[x]=root;
return root;
}*/

int main()
{
	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	li T = 0, S = 0, flag = 0, N = 0, R = 0, i = 0, k = 0, j = 0, len = 0, end = 0, max = 0;
	li A[1000];
	li B[1000];
	li C[1000];
	scanf("%lld", &T);
	while (T--)
	{
		S = 0;
		R = 0;
		flag = 0;
		k = 0;
		for (i = 0; i<N; i++)
		{
			C[i] = 0;
		}
		scanf("%lld", &N);
		for (i = 0; i<N; i++)
		{
			scanf("%lld", &A[i]);
			S = S + A[i];
			if (A[i] >= N || A[i]<0)
			{
				flag = 1;
			}
		}
		if (N == 1)
		{
			//if(A[0]>=1)
			printf("-1\n");
			//else
			//	printf("\n");
			continue;
		}
		if (S != N)
			flag = 1;
		if (flag == 1)
			printf("-1\n");
		else
		{
			for (i = 0; i<N; i++)
			{
				if (A[i] == 0)
					continue;

				for (j = (i + 1) % N; j != i;)
				{
					if (A[j]>0)
					{
						B[i] = j + 1;
						C[i] = 1;
						A[j]--;
						k++;
						break;
					}
					j = (j + 1) % N;
				}
			}
			for (i = 0; i<N; i++)
			{
				if (C[i] == 1)
					continue;

				for (j = (i + 1) % N; j != i;)
				{
					if (A[j]>0)
					{
						B[i] = j + 1;
						A[j]--;
						k++;
						break;
					}
					j = (j + 1) % N;
				}
			}
			for (i = 0; i<N; i++)
			{
				printf("%d ", B[i]);
			}
			printf("\n");
		}
	}
	return 0;
}