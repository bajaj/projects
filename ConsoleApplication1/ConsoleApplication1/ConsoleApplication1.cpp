// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

#include<math.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	bool palindrome(__int64 no,__int64 x,__int64 sum,__int64 po);

__int64 a,b,no=0;

double y,x;

cin>>a;
cin>>b;

  for(x=a;x<=b;x++)
{
    y=sqrt(x);

         //   cout<<endl<<y;
    if(fmod(y,1)==0)
    {  cout<<endl<<y;
        if(palindrome(y,y,0,0))
        {
            if(palindrome(x,x,0,0))
            no++;
        }
    }

}

//cout<<endl<<palindrome(36,36,0,0);
cout<<endl<<no;

	
	
	
	
	return 0;
}
bool palindrome(__int64 no,__int64 x,__int64 sum,__int64 po)
{
    if(no==0)
    {
       // cout<<endl<<sum;
        if(sum==x)
            return true;
        else
            return false;
    }
    else
    {
  //  cout<<endl<<(__int64)fmod(no,10);
       
	sum=sum*10+(__int64)fmod(no,10);

//        cout<<endl<<sum;

        return(palindrome(int(no/10),x,sum,++po));
    }

}


