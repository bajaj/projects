// increment_operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int x=0;

	x++;

	int *p=NULL;

	cout<<(*p);

	++x;

	x=x+1;

	return 0;
}

