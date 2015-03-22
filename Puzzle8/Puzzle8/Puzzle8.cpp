// Puzzle8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;


int get_count(int arr[3][3],int x,int y)
{
	int element=arr[x][y];

	if(x==2 & y==2)
		return 0;

	

	int count=0;

	int j=y+1;

	for(int i=x;i<3;i++)
	{
		for(;j<3;j++)
		{
			if(arr[i][j]==0)
				;
			else
			{
				if(element>arr[i][j])
					count++;

			}

		}
		j=0;
	}

	return count;
}

bool whether_solvable(int arr[3][3])
{
	int count=0;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			count+=get_count(arr,i,j);
	}

	if(count%2==0)
		return true;
	else 
		return false;

}

void display(int arr[3][3])
{
for(int i=0;i<3;i++)
	{
		cout<<endl;
		for(int j=0;j<3;j++)
			cout<<arr[i][j]<<"  ";
	}
cout<<endl;
}


bool goal_state(int arr[3][3])
{
	int x=1;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(x==9)
				return true;

			if(!(arr[i][j]==x))
				return false;
			x++;

		}
	}
}

void adjust(int arr[3][3],char c,int& p,int& q)
{

	if(c=='L')
	{
		if(q==0)
		{
			cout<<"Move not allowed";
			return;
		}
		arr[p][q]=arr[p][q-1];	
		arr[p][q-1]=0;
		q=q-1;
	}

	if(c=='R')
	{
		if(q==2)
		{
			cout<<"move not allowed";
			return;
		}
		arr[p][q]=arr[p][q+1];
		arr[p][q+1]=0;
		q=q+1;
	}

	if(c=='U')
	{
		if(p==0)
		{
			cout<<"Move not allowed";
			return;
		}
		arr[p][q]=arr[p-1][q];
		arr[p-1][q]=0;
		p=p-1;
	}
	if(c=='D')
	{
		if(p==2)
		{
			cout<<"Move not allowed";
			return;
		}
		arr[p][q]=arr[p+1][q];
		arr[p+1][q]=0;
		p=p+1;
	}
	

}


int _tmain(int argc, _TCHAR* argv[])
{

	int puzzle_arr[3][3]={1,2,3,0,5,6,4,7,8};

	cout<<endl<<"The state of puzzle is ";
		display(puzzle_arr);

	if (!whether_solvable(puzzle_arr))
	{
		cout<<"the configuration is not solvable";
		return 0;
	}

	int p,q;     // location of empty element

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(puzzle_arr[i][j]==0)
			{
				p=i;
				q=j;
			}

		}

	}

	while(true)
	{
		cout<<endl<<"The state of puzzle is ";
		display(puzzle_arr);

		if(goal_state(puzzle_arr))
		{
			cout<<" THE GOAL STATE IS REACHED ";
			break;
		}

		 char c;

		cout<<endl<<"Enter L for LEFT, R for RIGHT,U FOR UP,D for DOWN ";
		cin>>c;

		adjust(puzzle_arr,c,p,q);

	}


	return 0;
}

