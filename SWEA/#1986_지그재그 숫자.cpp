/*
N이 5일 경우 1 - 2 + 3 -4 +5 = 3


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		cin >> N;
		int sum_number = 1;
		if (N == 1)
		{
			cout << '#' << tc << ' ' << 1 << '\n';

		}
		else if (N != 1)
		{


			for (int i = 2; i <= N; i++)
			{
				if (i % 2 == 0)
				{
					sum_number -= i;
				}
				else if (i % 2 == 1)
				{
					sum_number += i;
				}
			}

			cout << '#' << tc << ' ' << sum_number << '\n';
		}
	}


	return 0;
}