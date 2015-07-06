// 469.cpp : Defines the entry point for the console application.
//

//#include <bits/stdc++.h>
#include "stdafx.h"

#include <iostream>
#include <cstdio>
#include <cstring>
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

// vector<vii> AdjList;    // graph representation


#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define rdarr(a,n) REP(i,n) cin >> a[i];

#define cscanf(x) scanf("%d", &x)
#define cprintf(x) printf(" %d \n", x)

int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

#define VISITED 1
#define UNVISITED -1

vector<vii> Ad;
vector<vii>& AdjList = Ad;

// in main    AdjList.assign(V,vii())

char grid[100][100];
int R, C;

int dr[] = {1,1,0,-1,-1,-1,0,1};              // for the grid
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };   // S, SE,E,NE,N,NW,W,SW

int floodFill(int r, int c, char c1, char c2)
{
	if (r < 0 || r >= R || c < 0 || c >= C)
		return 0;

	if (grid[r][c] != 'W')
		return 0;

	int ans = 1;

	// no need to recolor the vertex
	grid[r][c] = c2;

	for (int i = 0; i < 8; i++)
		ans+= floodFill(r + dr[i], c + dc[i],c1,c2);

	return ans;
}

void dotToChar(int r, int c, char c1, char c2)
{
	REP(i,r)
		REP(j, c)
	{
		if (grid[i][j] == c1)
			grid[i][j] = c2;
	}

}


int main()
{
	//inp_s; cinnull;

	#pragma warning (disable : 4996)
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int testCase = 0;
	cin >> testCase;

	string str;
	getline(cin, str);
	getline(cin, str);
	char inp[1000];

	while (testCase--)
	{
		int no = 0;
		//getline(cin, str);

	//	cin >> str;

		while (gets(inp) && strlen(inp) > 0)
		{

			if (inp[0] == 'L' || inp[0] == 'W') 
			{
				//grid[no++] = str;

				strcpy(grid[no++], inp);

			//	getline(cin, str);
			//	getline(cin, str);
			//	cout << inp;
			}
			else
			{
				R = no;
				C = strlen(grid[0]);

				int r, c;// = str[0] - '0';
				//int c = str[2] - '0';

			//	cin >> r >> c;
				int i = 0;
				string temp;
				for (i = 0; inp[i] != ' '; i++)
					temp += inp[i];
				
				r = stoi(temp);
				string f;
				for (int j = i + 1; inp[j] != ' '; j++)
					f += inp[j];
				
				c = stoi(f);
				
				//cout << r << c;

				dotToChar(100, 100, '.', 'W');
				int ans = floodFill(r - 1, c - 1, 'W', '.');

				cout << ans << endl;
			}

		}

		if (testCase != 0)
		cout << "\n";
	}
	return 0;
}

