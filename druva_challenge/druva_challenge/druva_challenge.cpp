// druva_challenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
#include <utility>

using namespace std;


bool pairCompare(const std::pair<long long int, unsigned int>& firstElem, const std::pair<long long int, unsigned int>& secondElem) {
	return firstElem.first < secondElem.first;

}

int main() {

	unsigned int n, m;

	long long int arr[100000], x,temp;

	vector<pair<long long int, unsigned int> > vect(100000);

	cin >> n;

	for (unsigned int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[i] = temp;

		vect[i].first = temp;
		vect[i].second = i;
	}

	sort(vect.begin(), vect.begin() + n, pairCompare);


	cin >> m;

	vector<pair<long long int, unsigned int> >::iterator low;

	while (m--)
	{
		cin >> x;

		low = lower_bound(vect.begin(), vect.begin() + n, make_pair(x,2), pairCompare);

		if (low != vect.begin() + n)
		{

			for (unsigned int i = low - vect.begin(); i < n; i++)
			{

				if (vect[i].first != x)
				{
					vect[i].first -= 1;

					arr[vect[i].second] -= 1;
				}
			}


		}


	}


	for (unsigned int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}

	
	return 0;
}