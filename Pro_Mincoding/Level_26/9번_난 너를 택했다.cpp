#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int main()
{
	string str;
	cin >> str;


	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cout << str[arr[i]];
	}
	return 0;
}