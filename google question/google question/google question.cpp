// google question.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;



void f(char *x)
{
	++x;

//	*x='a';

	cout<<x;
}

void fi(int* p)
{

	*p=2;

}

char* cool()
{
	char *p="efef";

	return p;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char *p="hello";




	char *s=cool();


	*s='e';

	return 0;
}

