// comment_remove.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include <stdio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	string str;
	int c;

	c = getchar();
	while (c!='$')
	{
		
		str += c;
		c = getchar();
	}

	cout << " str is  "<<str;


	return 0;
}

