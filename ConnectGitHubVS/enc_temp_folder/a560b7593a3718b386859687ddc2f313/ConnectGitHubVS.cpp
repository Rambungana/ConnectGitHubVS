// ConnectGitHubVS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
//#include <iostream>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> rearrange(vector<int> elements) {
	vector<int> res;


	int remainder[100000];
	int i = 1, step = 0;

	size_t simpan = 0;
	int t = 0;

	int j, k, temp, arr[100000];
	int temp_element[100000];
	int temp_elements;
	int temp_iter[100000];

	//read data element 
	vector<int>::iterator iter;

	for (iter = elements.begin(); iter != elements.end(); iter++)

	{
		arr[step] = 0;
		res.push_back(*iter);

		remainder[step] = 0;


		temp_element[step] = elements[step];


		while (temp_element[step] != 0)
		{

			remainder[step] = temp_element[step] % 2;



			temp_element[step] /= 2;

			//count remainder

			if (remainder[step] == 1)
			{
				arr[step] = arr[step] + remainder[step];

			}
			i *= 10;


		}

		t = t + 1;

		step++;
		res.pop_back();

	}


	res.reserve(t);

	for (j = 0; j < t; j++)
	{
		for (k = j + 1; k < t; k++)
		{
			if (arr[j] > arr[k])
			{
				// if (elements[j]>elements[k])
				// {

				temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;

				temp_elements = elements[j];
				elements[j] = elements[k];
				elements[k] = temp_elements;
				//}

			}
			if (arr[j] == arr[k])
			{
				if (elements[j] > elements[k])
				{
					temp = arr[j];
					arr[j] = arr[k];
					arr[k] = temp;

					temp_elements = elements[j];
					elements[j] = elements[k];
					elements[k] = temp_elements;
				}

			}

		}//for k

	}//for j




	for (j = 0; j < t; j++)
	{

		res.push_back(elements[j]);


	}


	return res;
}

//int main()
//{
 //   std::cout << "Hello World!\n"; 


//}
int main() {
	/* Read input from STDIN. Print output to STDOUT */
	unsigned int n;
	cin >> n;

	vector<int> elements;
	elements.reserve(n);

	for (unsigned int i = 0; i < n; ++i) {
		int element;
		cin >> element;
		elements.push_back(element);
	}
	// call rearrange function
	vector<int> sorted_elements = rearrange(elements);

	//for (unsigned int i = 0; i < n; ++i) {
		//cout << sorted_elements[i] << endl;
	//}
	std::cout << "Hello World!\n";

	return 0;
}


