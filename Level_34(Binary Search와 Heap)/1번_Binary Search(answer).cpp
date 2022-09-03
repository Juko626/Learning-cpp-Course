#include<iostream>
using namespace std;

int vect[10] = { 4, 4, 5, 7, 8, 10, 20, 22, 23, 24 };
int tar;



char bs(int start, int end)
{
	while (1)
	{
		int mid = (start + end) / 2;
		if (start > end) return 'X';
		if (vect[mid] == tar) return 'O';
		if (start == end) return 'X';

		if (vect[mid] < tar) start = mid + 1;
		else end = mid - 1;
	}
	return 0;
}

int main()
{
	cin >> tar;
	cout << bs(0, 9);
	return 0;
}
