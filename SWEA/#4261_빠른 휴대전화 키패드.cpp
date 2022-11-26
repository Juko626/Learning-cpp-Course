#include<iostream>
#include<string>
#include<vector>
using namespace std;



string num, str;
string temp[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
int N;



bool check()
{
	for (int i = 0; i < num.size(); i++)
	{
		if (temp[num[i] - '0'].find(str[i]) == -1)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> num >> N;
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> str;
			if (check())
			{
				count++;
			}

		}
		cout << "#" << test_case << " " << count << '\n';

	}

	return 0;
}