// codechef2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"

#include "string"

#include "fstream"

#include <math.h>

using namespace std;



inline void write()
{

	ofstream my_o("in.txt");

	my_o << 2;

	my_o << "\n";

	for (int i = 0; i < 10000; i++)
		my_o << "lr";
	my_o << "\n";
		my_o << "rlrrlrrlrlrlllrlr";
}

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream my("in.txt");
	int t;

	my >> t;

	write();

	
	int toggle = 0;

	unsigned long int* arr = new unsigned long int[t];
	
	for (int i = 0; i < t; i++)
	{
		string s;
		my >> s;
		cout << s.length();

		short toggle = 1;
		unsigned long int even_index = 0,odd_index=0;
		

		for (unsigned long int j = 0; (j < s.length() && j<100000); j++)
		{
			if (toggle)  // even
			{
				if (s[j] == 'l')
					even_index = odd_index * 2 + 1;
				if (s[j] == 'r')
					even_index = odd_index * 2 + 2;
					

			}
			else           // odd
			{
				if (s[j] == 'l')
					odd_index = even_index * 2 - 1;
				if (s[j] == 'r')
					odd_index = even_index * 2;

			}
		
			if (toggle == 1)
				toggle = 0;
			else
				toggle = 1;
		}

		if (toggle == 1)
			toggle = 0;
		else
			toggle = 1;


		if (toggle)
			arr[i] = (2 * even_index);// % (unsigned long int)(pow(10, 9) + 7);
		else
			arr[i] = (2 * (odd_index)+1);// % (unsigned long int)(pow(10, 9) + 7);

	

	}
	ofstream myfile("out.txt");
	for (int i = 0; i < t; i++)
	{
		myfile << arr[i]<<"\n";
	}

	return 0;
}

