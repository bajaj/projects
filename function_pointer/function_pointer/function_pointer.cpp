// function_pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>

using namespace std;



void f1(int*, int);
void f2(int*, int);


void (*p[2])(int*, int);


void foo(char *);


int a=10;

int fun();





int* fun3()
{
int *a =(int*) malloc(sizeof(int));
*a = 10;
return a;
}

int swapOddEvenBits(int x) {
    return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
}


inline int left(int i)
{

	return (i<<1)+1;

}

inline int right(int i)
{

return (i<<1)+2;
}


inline void swap(int& x,int& y)
{
	int temp=x;

	x=y;
	y=temp;


}

void min_heapify(int **arr,int i,int heapsize)
{

	int l=left(i);
	int r=right(i);

	int min=i;

	if(l<heapsize && arr[l][0]<arr[i][0])
		min=l;
	
	if(r<heapsize && arr[r][0]<arr[min][0])
		min=r;


	if(min!=i)
	{
		swap(arr[i][0],arr[min][0]);
		swap(arr[i][1],arr[min][1]);
		min_heapify(arr,min,heapsize);
	}


}


void build_minheap(int **arr,int len)
{

	for(int i=len/2;i>=0;i--)
		min_heapify(arr,i,len);

}

class abc
{

public:

	virtual void cool()
	{

		cout<<"hi how are you";

	}

	virtual void ababab()
	{
		int sbfj;

		cout<<" not dervied";

	}

};

class xyz:public abc
{


public:

	void cool()
	{

		cout<<"class xyz";

	}

	void notvirt()
	{

		cout<<"this is not virtual";

	}

	


};



class asas
{


public:


virtual void nswfi()=0
{
	cout<<"wfnwnof";

}

};


class ab:public asas
{

public:

	ab()
	{
		asas::nswfi();


	}

	void nswfi()
	{


	}

};



class des
{

	~des()
	{
		cout<<"cool";
	}


public:

	void done(des *ptr)
	{
		delete ptr;
	}

};



int wmain(int argc)
{


	des *pt=new des;

	pt->done(pt);

	int xx=0xCCBBCCDD;

	signed int y=0;

	y=y+(xx<<24);

	y=y+((xx & 0x0000ff00)<<8);

	y=y+((xx & 0x00ff0000)>>8);

	y=y+((xx & 0xff000000)>>24);



	cout<<(0xff000000 >> 24);

	cout<<" hex is ";

	cout<<hex<<y;

	cout<<endl;







//	delete pt;


	ab a;

	

	


	cout<<endl;

	int n=23;

	cout<<n++<<n++;

	cout<<n;

	abc *ptr2;

	xyz ad;

	ptr2=&ad;

	ptr2->ababab();
	

	int *ptr=new int;

	ptr++;

	*ptr=13;

	cout<<ptr[4];

	cout<<endl;



	struct MyStruct
	{ 
 


   short hg;
  char c;
	};

	union MyUnion
	{
	
		double a;
		
	};

		cout<<sizeof(MyStruct);
//	cout<<sizeof(MyUnion);

	int *x=new int[4];

	cout<<x[3];

	return 0;
}


void wmain2(int argc)
{
	int arr[]={8,9,10,11,12,16,20,31,42,3};

	int low=0;
	int high=9;

	int mid=(low+high)/2;

	int index;

	while(true)
	{
		int mid=(low+high)/2;

		if(arr[low]<=arr[high])
		{
			index=low;
			break;
			
		}
		
		if(arr[mid]<arr[high])
			high=mid;
		else
			low=mid+1;



	}


	cout<<arr[index];


}




void k_array_merge(int argc)
{
	int arr[3][4]={{1,3,5,8},{2,6,9,10},{12,13,14,15}};

	int index[3]={0,0,0};

	int k=3,n=4;

	int **heap=new int*[k];

	for(int i=0;i<k;i++)
	{
		heap[i]=new int[n];
	}


	int min;
	int ind;

	for(int j=0;j<k;j++)
	{

		heap[j][0]=arr[j][0];
		heap[j][1]=j;

	}

	
	build_minheap(heap,k);

	for(int j=0;j<k;j++)
	{
		cout<<"  "<<heap[j][0]<<"   "<<heap[j][1];
		cout<<endl;
	}



	int heapsize=k;


	for(int i=0;i<k*n;i++)
	{
				cout<<heap[0][0]<<"  ";

			int indd=heap[0][1];

			index[indd]++;

			if(index[indd]<n)
			{
				heap[0][0]=arr[indd][index[indd]];
				min_heapify(heap,0,heapsize);

			}
			else
			{
				swap(heap[0][0],heap[heapsize-1][0]);
				swap(heap[0][1],heap[heapsize-1][1]);
				heapsize--;
				min_heapify(heap,0,heapsize);
			}
		
	}


}
	//cout<<swapOddEvenBits(14);
int x()
{		

	cout<<endl;

	

	cout<<endl;

return 0;



 
	//int a[10][20][30] = {0};

  	

	//main();



	
	string s1="abcdeafghtw";

	string s2="af";


	int len_s2=s2.length();

	for(int i=0;i<len_s2;i++)
	{

		char x=s2[i];

		int ind=s1.find(x);

		while(ind<s1.size())
		{
			s1.erase(ind,1);
			ind=s1.find(x);
		}



	}

	










	
    return 0;


//	*p=23;

//	cout<<s;


//	cool();

	

	//char *qwqw=aad;





	//   char *ptr = fun2();

//return 1;
}
void fun(int i)
{
    if(i!=4)
        _tmain(++i);
}
 const char *fun2()
{
    return "Hello";
}

 void foo(char *a)
{


while(*a)
{
*a += 1;
a++;
}
 }

 int fun()
{
static int a = 1;
printf("%d ",a);
a++;
return 0;
}

