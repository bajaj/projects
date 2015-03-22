// longestpalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>

#include <iostream>

using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{

	
	int max=0;
	int index_start=0;
	int index_end=0;


	string str;

	cout<<"enter the string  ";cin>>str;

	int len=str.length();

	for(int i=0;i<len;i++)
	{
		
		int s=i;
		int e=len-1;

		int start=s;
		int end=e;

		int done=true;
		
		while(done)
		{

		//	if(start==end)                to eliminate odd length
 	//			break;

		//		if( start>end)            //    for even length even length
 			
			if(start==end || start>end)
			{
				if(max<(e-s))
				{

					max=e-s;
					index_start=s;
					index_end=e;
				}

				done=false;
			}
			else if(str[start]==str[end])
			{
				start++;
				end--;
			}	
			else
			{
				start=s;
				end=--e;
			}
		


		}


	}

	if(max>0)
	{

		cout<<endl<<"max palindrome string is ";

		cout<<endl;

		for(int i=index_start;i<=index_end;i++)
			cout<<str[i];

	}

	//cout<<max;

	return 0;
}

