// bit_manipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

 int x=32;

 int count=0;

 for(int i=0;i<32;i++)
 {

	 if((x>>i) & 0x00000001)
		 count++;

 }


 cout<<count;

	return 0;
}

