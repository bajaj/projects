// LCS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <string>

#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)
using namespace std;

void swap(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

int max(int a, int b)
{
	return a > b ? a : b;

}

void str_rev(string &str)
{
	int len = str.length();

	int j = len - 1;
	int i = 0;

	while (i < j)
	{
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++; j--;
	}

}

int ctr[1001][1001];
int _tmain(int argc, _TCHAR* argv[])
{
	inp_s; cinnull;
	char a[1001], b[1001], lcs[1001];
	int lcs_pos[1001][2];
	
	int t;

	cin >> t;

	int cas = 1;

	while (cas!=t)
	{
		int x, y;


		cin >> x >> a+1 >> y >> b+1;

		int len1 = x, len2 = y;

		/*int **ctr;

		if (len1 > len2); else { swap(len1, len2); swap(a, b); }

		ctr = new int*[len1+1];

		for (int i = 0; i <= len1;i++)
		ctr[i] = new int[len2+1];
		*/

		ctr[0][0] = 0;
		ctr[1][0] = 0;
		ctr[0][1] = 0;

		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (a[i] == b[j])
				{
					ctr[i][j] = ctr[i - 1][j - 1] + 1;
				}
				else
				{
					ctr[i][j] = max(ctr[i - 1][j], ctr[i][j - 1]);

				}

			}

		}

		int* arr = new int[len2 + 1]();

		int tempi = 0;
		for (int i = 1; i <= len1; i++)
		{
			tempi = arr[0];
			for (int j = 1; j <= len2; j++)
			{
				int xx = arr[j];

				if (a[i] == b[j])
				{
					arr[j] = tempi + 1;
				}
				else
				{
					arr[j] = max(arr[j - 1], arr[j]);
				}

				tempi = arr[j];
			}
		}


		if (ctr[len1][len2] == arr[len2])
		{
			cout << " both are equal match found ";

		}

		cout << "case " << cas<<" ";
		
		int lcs_len = ctr[len1][len2];

		int temp = lcs_len;

		if (lcs_len > 1)
		{
			cout << "Y"<<"\n";

			cout << ctr[len1][len2] << "\n";

			int i = len1; int j = len2;

			

			while (i != 0 && j != 0)
			{
				if (a[i] == b[j])
				{
					lcs[lcs_len]= a[i];
					lcs_pos[lcs_len][0] = i;
					lcs_pos[lcs_len][1] = j;

					i--; j--;
					lcs_len--;
				}
				else
				{
					if (ctr[i - 1][j] > ctr[i][j - 1])
					{
						i--;
					}
					else
					{
						j--;
					}

				}
				
			}
			lcs_len = temp;
			int x = 1;
			while (x<=lcs_len)
			{
				cout << lcs[x] << " " << lcs_pos[x][0] << " " << lcs_pos[x][1] << " ";
				cout << "\n";
				x++;
			}


		}
		else
		{
			cout << "N" << "\n";;
		}

		
		
		cas++;
	}

	return 0;
}

