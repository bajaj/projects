// virtual_function.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class base
{

public:

	virtual	void disp()=0   // pure virtual function
	{
		cout<<endl<<"this is base class";
	}

};

class dera:public base
{

public:
	void disp()
	{
		base::disp();

		cout<<endl<<"this is derived class A";

	}

};

class derb:public base
{

public:

	void disp()
	{
		cout<<endl<<"this is derved class B";
	}

};



int _tmain(int argc, _TCHAR* argv[])
{

derb db;
dera da;

	//base b;
	

	base *b[3];
	
	int arr[2];


	b[0]=&db;

	b[0]->disp();

	b[1]=&da;
b[1]->disp();

	return 0;
}

