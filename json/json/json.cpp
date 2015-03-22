// json.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#include "string"
#include "bitset"

using namespace std;

void printspace(int n)
{
	while (n != 0)
	{
		cout << " ";
		n--;
	}
}

void incr(int& n)
{
	n += 3;
}

void dcr(int& n)
{
	n -= 3;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str;

	getline(cin, str);

	int len = str.length();

	cout << "\n" << " string is  " << str << "\n";

	int space = 0;
	
	bool keyval;
	keyval = true;

	for (int i = 0; i < len;)
	{
		char c = str[i];

		if (c == '{')
		{
			printspace(space);
			cout << c << "\n";

			if (c != ',')
				incr(space);

		}
		else if (c == '[')
		{
			cout << c << "\n";
			space+=2;

			keyval = !keyval;

		}
		else if(c == ',')
		{
			cout << c << "\n";
		}

		else if (c == '}')
		{
			dcr(space);
			cout << "\n";
			printspace(space);
			cout << c;
		}
		else if(c == ']')
		{
			space-=2;
			cout << "\n";
			printspace(space);
			cout << c;
		}
		else if (c == ':')
		{
			cout << c;
		}
		else if (c == '\"')
		{
			// print till next "

			if (keyval)
			{
				printspace(space);
			}
			keyval = !keyval;

			cout << str[i++];

			while (str[i] != '\"')
			{
				if (str[i] == '\\')
				{
					cout << str[i++];
					cout << str[i++];
				}
				else
				{
					cout << str[i++];
				}
			}
			cout << str[i];

		}
		else if (c == ' ')
			;
		else
		{
			cout << c;
		}
		i++;
	}








	/*for (int i = 0; i < len;)
	{
	char c = str[i];

	if (c == '{' || c=='[' || c==',' )
	{
	cout << c << "\n";
	}

	else if (c == '}' || c == ']')
	{
	cout << "\n" << c;
	}
	else if (c==':')
	{
	cout << c;
	}
	else if (c == '\"')
	{
	// print till next "
	cout << str[i++];

	while (str[i] != '\"')
	{
	if (str[i] == '\\')
	{
	cout << str[i++];
	cout << str[i++];
	}
	else
	{
	cout << str[i++];
	}
	}
	cout << str[i];

	}
	else if (c == ' ')
	;
	else
	{
	cout << c;
	}
	i++;
	}

	*/


	return 0;
}

