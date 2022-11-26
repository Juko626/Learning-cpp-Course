#include <iostream>
#include <vector>

using namespace std;



vector<int> v;
vector<int> sumv;
int main()
{
	int N;
	cin >> N;
	int K;
	cin >> K;
	int sum_num = 0;
	int max_num = -1000;
	v.push_back(0);
	sumv.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		sum_num += v[i];
		sumv.push_back(sum_num);
	}

	for (int i = K; i <= N; i++)
	{
		if (max_num < sumv[i] - sumv[i - K])
		{
			max_num = sumv[i] - sumv[i - K];
		}
	}

	cout << max_num;


}