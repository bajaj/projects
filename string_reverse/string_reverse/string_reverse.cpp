// string_reverse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>

using namespace std;

bool palindrome(string str,int i)
{
	static int length=str.length();

	if(i==length/2)
		return true;

	if(str.at(i)==str.at(length-1-i))
		return palindrome(str,i+1);

	return false;

}


bool check_no(char c)
{
	if((int)c >=48 && (int)c <=57)
	return true;

	return false;

}

void printstring(string str)    // a2b3d4======aabbbdddd
{
	int length=str.length();

	for(int i=0;i<length;i++)
	{
		char c=str.at(i);

		if(i+1<length)
		{
			if(check_no(str.at(i+1)))
			{
				int times=((int)str.at(i+1)-48);

				for(int j=0;j<times;j++)
					cout<<c;
				i++;
			}
			
			else
				cout<<c;
		}
		else
			cout<<c;
				

	}


}


int string_to_int(string str)
{
	int sum=0;

	int length=str.length();

//	for(int i=str.length()-1;i>=0;i--)       // reversing stragegy
//		sum=sum*10+((int)str.at(i)-48);  //

	for(int i=0;i<length;i++)
		sum=sum*10+((int)str.at(i)-48);


	return sum;

}


void str_reverse(string& str,int i,int j)
{
	while(i<j)
	{
		char c=str[i];
		str[i]=str[j];
		str[j]=c;

		i++;
		j--;
	}

}

void wrapper_reverse(string& str)
{
	int  len=str.length();

	for(int i=0;i<len;i++)
	{
		int j=i;

		while(str[i]!=' ')
			i++;
		
		str_reverse(str,j,i-1);
	}

	str_reverse(str,0,len-1);

}



int _tmain(int argc, _TCHAR* argv[])
{

	string str="ww";

//	cout<<"  "<<palindrome(str,0);

//	cout<<(int)'a'-2;

	//cout<<endl<<(char)2<<" ";

//	char c='2';

	string x="i am ritesh bajaj ";

	wrapper_reverse(x);

	cout<<x;

//	str="ad2f3";

//	printstring(str);

//	int f=string_to_int("2345");

//	cout<<f+2;

	return 0;
}

