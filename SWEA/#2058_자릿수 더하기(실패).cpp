#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int sum_num = 0;
	while (N / 10 > 0)
	{
		sum_num += N % 10;
		N /= 10;
	}
	

	cout << sum_num;
	return 0;
}