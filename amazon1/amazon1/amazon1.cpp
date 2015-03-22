// permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>

using namespace std;

void permuate(string rest, string sofar)
{

	if (rest == "")
		cout << "  " << sofar;                      // commmenting for previous value

	else
	{
		int len = rest.length();

		for (int i = 0; i<len; i++)
		{

			string next = sofar;

			if (sofar.find(rest[i]) == std::string::npos)
			{
				next = sofar + rest.at(i);
			}

			string remain = rest.substr(0, i) + rest.substr(i + 1);          // r.subtr(0,i)


			permuate(remain, next);


		}



	}



}

void wapper(string str)
{

	permuate(str, "");

}


void subset(int arr[], int low1, int end1, int low2, int end2)
{

	if (low2>end2)
	{
		for (int i = low1; i<end1; i++)
			cout << "  " << arr[i];

		cout << endl;
	}

	else
	{
		subset(arr, low1, end1 + 1, low2 + 1, end2);

		subset(arr, low1, end1, low2 + 1, end2);


	}

}


void subset_wrapper(int arr[], int len)
{

	subset(arr, 0, 0, 0, len - 1);

}



void sub_set(int arr[], int len)
{
	int subset = (1 << len);

	for (int i = 0; i<subset; i++)
	{

		int bitmask = i;

		int pos = len - 1;

		cout << "{ ";

		while (bitmask>0)
		{

			if (bitmask & 1)
				cout << arr[pos] << " ,";

			bitmask = bitmask >> 1;
			pos--;
		}

		cout << "   }";
		cout << endl;
	}


}



class test
{
	static int x;
	int* ptr;
};


char *str = "hello\0world\0";


#define Sqr(b) b*b;

int _tmain(int argc, _TCHAR* argv[])
{




		int arr[]={1,2,3,4};


		subset_wrapper(arr,3);

	//sub_set(arr,4);


	int x = -1;

	char *p = "wwfrwfr";


	//	cout<<p;


	//cout<<~(x);

	wapper("ABC");

	//string str="abc";


	//	cout<<str.substr(2,-5);


	return 0;
}

