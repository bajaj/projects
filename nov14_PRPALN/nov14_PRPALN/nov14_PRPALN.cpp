// nov14_PRPALN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

using namespace std;

#include "string"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	string s;
	int t;


	cin >> t;


	for (int k = 0; k < t; k++)
	{

		cin >> s;

		int len = s.length();
		int i = 0, j = len - 1;// s.length() - 1;

		


		int ans = 1;
		int x = 0;

		while (i < j)
		{
			if (s[i] == s[j])
			{
				i++; j--;
			}
			else if (x == 0)
			{
				if (s[i + 1] == s[j])
				{
					i += 2; 
					j--;
					x = 1;
				}
				else if (s[j - 1] == s[i])
				{
					i++;
					j -= 2;
					x = 1;
				}
				else
				{
					ans = 0;
					break;
				}

			}
			else
			{
				ans = 0;
				break;
			}


		}

		if (len == 3)
		{
			if (s[0] == s[1] || s[1] == s[2] || s[0]==s[2])
				cout << "YES";
			else
				cout << "NO";

		}
		else
		{
			if (ans)
				cout << "YES";
			else
				cout << "NO";

			
		}
		cout << "\n";
	}





	return 0;
}

