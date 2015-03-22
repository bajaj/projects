// infix _to _postfix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>

#include <map>

#include<string>

#include <stack>

using namespace std;


map<char,int> prec;


void make_prec()
{

	prec['*']=4;
	prec['/']=3;
	prec['+']=2;
	prec['-']=1;

}



inline bool find(char p)
{

	map<char,int>::iterator iter;

	iter=prec.find(p);


	if(iter==prec.end())
	{
		//cout<<" 0 ";
		return 0;
	}
	else return 1;


}


int _tmain(int argc, _TCHAR* argv[])
{

	make_prec();

	stack<char> stk;

	string in_exp;

		cout<<"enter the infix expression  ";

		cin>>in_exp;

		cout<<endl;

		cout<<"the postfix exp is "<<endl;


	string post_fix;

	int len=in_exp.length();

	for(int i=0;i<len;i++)
	{
		if(find(in_exp[i]))
		{
			char x=in_exp[i];

			if(!stk.empty())
			{
				char top=stk.top();

				if(prec[x]>prec[top])
				{
					stk.push(x);
				}				
				else
				{
					while(!stk.empty() && prec[top]>prec[x])
					{
					post_fix+=top;
					stk.pop();
					if(!stk.empty())
					top=stk.top();
					}
				
					stk.push(x);

				}

			}
			else
				stk.push(x);


		}

		else
			post_fix+=in_exp[i];




	}

	while(!stk.empty())
	{
		post_fix+=stk.top();
	stk.pop();
	}
	cout<<post_fix;

	return 0;
}

