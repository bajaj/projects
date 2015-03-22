// codechef1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "iostream"



#include <map>

using namespace std;



//unsigned long int cal(unsigned long int n,unsigned long int arr[50000])
unsigned long int cal(unsigned long int n,map<unsigned long int, unsigned long int>& arr)
{
	//static const unsigned long int x = 49991;
	

	if (n <= 11)
		return n;

	//if (arr[n % x] != 0)
	if (arr.find(n) != arr.end())
		return arr[n];

	unsigned long int half = n / 2, thi = n / 3;
	unsigned long int qua = half / 2;

	if (half + thi + qua <= n)
		return n;
	
	
	arr[half] = cal(half, arr);
	arr[thi] = cal(thi, arr);
	arr[qua] = cal(qua, arr);;


	return arr[half]+arr[thi]+arr[qua];

}

int _tmain(int argc, _TCHAR* argv[])
{

	map<unsigned long int, unsigned long int> arr2;

	arr2.clear();

	//r (int i = 0; i < 10; i++)
//
		unsigned long int n=1,sum = 0;

	//while (n>0
while (!cin.eof())
	{
		cin >> n;
		if (cin.eof())
			break;
	//	unsigned long int arr[50000] = { 0 };
		//arr2.clear();
		sum = cal(n, arr2);

		if (sum < n) sum = n;

		//if (n>0)
		cout << sum << "\n";
	}
	


	return 0;
}

