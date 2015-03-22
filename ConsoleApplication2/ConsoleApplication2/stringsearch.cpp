// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;


int bruteforcesearch(string pattern,string text)
{
	int n=text.length();
	int m=pattern.length();

	for(int i=0;i<=n-m;i++)
	{
		int j;
		for(j=0;j<m;j++)
			if(text.at(i+j)!=pattern.at(j))
				break;

		if(j==m)
			return i;
	}

	return n;

}

int bruteforce_no_pattern(string pattern,string text)
{
	int n=text.length();
	int m=pattern.length();

	int count=0;

	for(int i=0;i<=n-m;i++)
	{
		int j;
		for(j=0;j<m;j++)
			if(text.at(i+j)!=pattern.at(j))
				break;

		if(j==m)
		count++;
	}

	return count;

}


// for KMP

int** build_dfa(string pattern)
{
	int m=pattern.length();

	int **dfa=new int*[256];

	for(int i=0;i<256;i++)
	dfa[i]=new int[m];

	for(int i=0;i<256;i++)
		dfa[i][0]=0;

	dfa[pattern.at(0)][0]=1;

	for(int x=0,j=1;j<m;j++)
	{
		for(int c=0;c<256;c++)
			dfa[c][j]=dfa[c][x];

		dfa[pattern.at(j)][j]=j+1;

		x=dfa[pattern.at(j)][x];
	}

	return dfa;
}

// KMP search

int kmpsearch(string text,string pattern,int **dfa)
{

	int n=text.length();
	int m=pattern.length();

	int j,i;

	for(i=0,j=0;i<n && j<m;i++)
		j=dfa[text.at(i)][j];

	if(j==m)
		return i-m;
	else
		return n;


}


int no_patterns(string text,string pattern,int **dfa)
{

	int n=text.length();
	int m=pattern.length();
	int count=0;
	int j,i;

	for(i=0,j=0;i<n && j<m;i++)
		{
			j=dfa[text.at(i)][j];
			if(j==m)
			{
				j=0;
				count++;
			}
		}
	return count;

}


int _tmain(int argc, _TCHAR* argv[])
{
	string text="ritesh bajaj is comps engg engg engg";

	string pattern="eng";

	int n=bruteforcesearch(pattern,text);

	if(n==text.length())
		cout<<"no pattern match";
	else
	cout<<endl<<"pattern match at index starting from  "<<n;

	cout<<endl;

	int **dfa=build_dfa(pattern);

	n=kmpsearch(text,pattern,dfa);

	
	if(n==text.length())
		cout<<"no pattern match";
	else
	cout<<endl<<"pattern match at index starting from  "<<n;
	
	cout<<endl<<"no of patterns by KMP "<<no_patterns(text,pattern,dfa);

	cout<<endl<<"no of patterns by bruteforce is "<<bruteforce_no_pattern(pattern,text);


	return 0;
}

