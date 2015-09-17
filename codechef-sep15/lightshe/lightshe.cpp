// lightshe.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include "math.h"
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

// Common memset settings
//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
//memset(arr, 0, sizeof arr); // to clear array of integers

typedef long long int LL;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;    // graph representation
vector< pair<int, ii> > EdgeList;   // edgeList for kruskal algorithm


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define rdarr(a,n) REP(i,n) cin >> a[i];

typedef pair<ii, int> points;
#define minVal -1000000005
#define maxVal  1000000005

points arr[100005];

int main()
{
	inp_s; cinnull;
	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);

	DRT()
	{

		points maxy1, maxy2, other, miny1,miny2,maxx,minx;

		other.first.second=maxy1.first.second = maxy2.first.second = minVal;
		
		
		maxy1.first.first = minVal;
		maxy2.first.first = maxVal;
		other.first.first = maxVal;

		miny1.first.second=miny2.first.second = maxVal;
		miny1.first.first = minVal;
		miny2.first.first = maxVal;

		minx.first.first = maxVal;
		maxx.first.first = minVal;

		int n;
		cin >> n;

		REP(i, n)
		{
			int x, y;
			cin >> x >> y;
			points pi = points(ii(x, y), i + 1);
			arr[i] = pi;

			if (x > maxx.first.first)
				maxx=pi;
			
			if (x < minx.first.first)
				minx = pi;

			if (y > maxy1.first.second)				
				maxy1 = pi;
			else if (y == maxy1.first.second && x > maxy1.first.first)
				maxy1 = pi;
			

		/*	if (maxy1 != pi)
			{
				if (y > other.first.second)
					other = pi;
				else if (y == other.first.second && x<other.first.first)
					other = pi;

			}*/

			if (y > maxy2.first.second)
					maxy2 = pi;
			else if (y == maxy2.first.second && x < maxy2.first.first)
					maxy2 = pi;
			
			
			if (y<miny1.first.second)
				miny1 = pi;
			else if (y == miny1.first.second && x > miny1.first.first)
				miny1 = pi;

			if (y<miny2.first.second)
				miny2 = pi;
			else if (y == miny2.first.second && x < miny2.first.first)
				miny2 = pi;

			
		}

		REP(i, n)
		{
			points pi = arr[i];
			int y = pi.first.second;

			if (maxy1 != pi)
				if ( y > other.first.second)
					other = pi;		
		}

		string dir1, dir2;int ind1 = 0, ind2 = 0;
		int lampno = 1;

		if (maxy1.first.first == maxx.first.first)
		{
			ind1 = maxy1.second;
			dir1 = "SW";
		}
		else if (maxy2.first.first == minx.first.first)
		{
			ind1 = maxy2.second;
			dir1 = "SE";
		}
		else if (miny1.first.first == maxx.first.first)
		{
			ind1 = miny1.second;
			dir1 = "NW";
		}
		else if (miny2.first.first == minx.first.first)
		{
			ind1 = miny2.second;
			dir1 = "NE";
		}
		else
		{
			lampno = 2;
			dir1 = "SW";
			dir2 = "SE";

			if (maxy1.first.first > other.first.first)
			{
				ind1 = maxy1.second;
				ind2 = other.second;
			}
			else
			{
				ind2 = maxy1.second;
				ind1 = other.second;
			}
		}

		cout <<lampno<< "\n";
		cout << ind1 << " " << dir1 <<"\n";

		if (lampno == 2)
			cout << ind2 << " " << dir2 << "\n";

	}

	return 0;
}

