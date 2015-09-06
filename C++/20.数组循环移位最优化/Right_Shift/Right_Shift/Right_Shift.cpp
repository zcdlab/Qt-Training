// Right_Shift.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
#define LENGTH(x,type) sizeof(x)/sizeof(type)

void right_shift(int* arr, int N, int K)
{

	while (K--)
	{
		int t = arr[N - 1];
		for (int i = N - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = t;
	}
	cout << arr<<endl;
}

void reverse(int *arr, int b, int e)
{
	for (; b < e; b++, e--)
	{
		int temp = arr[e];
		arr[e] = arr[b];
		arr[b] = temp;
	}
}
void rightShift(int* arr,int N, int K)
{
	K %= N;
	reverse(arr, 0, N - K - 1);
	reverse(arr, N-K, N - 1);
	reverse(arr, 0, N  - 1);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int str[] = { 'a', 'b', 'c', 'd', 1, 2, 3, 4 };
	cout << str<<endl;
	right_shift(str,LENGTH(str,int), 4);

	cout << str<<endl;
	return 0;
}

