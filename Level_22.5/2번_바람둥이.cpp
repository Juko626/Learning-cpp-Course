#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include<cstring>
#include <bitset>
using namespace std;


int main()
{
	int num;
	cin >> num;

	bitset<2> bb;

	
	bitset<3> cc;



	if (num == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			bb = bitset<2>(i);
			string s = bb.to_string();
			for (int j = 0; j < 2; j++)
			{
				if (s[j] == '0')
				{
					cout << 'x';
				}
				else if (s[j] == '1')
				{
					cout << 'o';
				}
			}
			cout << '\n';
		}
	}
	else if (num == 3)
	{
		for (int i = 0; i < 8; i++)
		{
			cc = bitset<3>(i);
			string s = cc.to_string();
			for (int j = 0; j < 3; j++)
			{
				if (s[j] == '0')
				{
					cout << 'x';
				}
				else if (s[j] == '1')
				{
					cout << 'o';
				}
			}
			cout << '\n';
		}
	}

	
	return 0;

}