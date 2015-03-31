// permutation_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;



void permute(string sofar, string rest)
{
	if (rest.empty())
	{
		cout << sofar << "\n";
		return;
	}

	for (int i = 0; i < rest.length(); i++)
	{
	
		if (rest.find(rest[i], i+1) != string::npos)   // NO DUPLICATE PERMUTATION
			continue;

		string next = sofar + rest[i];
		string remaining = rest.substr(0, i) + rest.substr(i+1);

		permute(next, remaining);
	}


}

void subset(string sofar, string rest)
{
	
	if (rest.empty())
	{
		cout << sofar << "\n";
		return;
	}

		subset(sofar+rest[0], rest.substr(1)); // add to subset, remove from rest recur
		subset(sofar, rest.substr(1));			// do not add to subset , remove from rest


}


int _tmain(int argc, _TCHAR* argv[])
{

	permute("", "AAA");

	subset("", "123");


	return 0;
}

