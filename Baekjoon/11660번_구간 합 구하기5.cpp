#include <iostream>
#include <vector>

using namespace std;

int map[1024][1024];
int sum_map[1024][1024];
int N;
int prefix(int s_y, int s_x, int e_y, int e_x)
{
	int result_sum = 0;
	for (int i = s_y; i <= e_y; i++)
	{
		if (s_x - 1 == 0 && i - 1 == 0)
		{
			result_sum += sum_map[i - 1][e_x];
		}
		else if (s_x - 1 == 0)
		{
			result_sum += sum_map[i - 1][e_x] - sum_map[i - 2][N];
		}
		else if (s_x - 1 > 0)
		{
			result_sum += sum_map[i - 1][e_x] - sum_map[i - 1][s_x - 1];
		}

	}
	return result_sum;
}


int main()
{

	
	cin >> N;
	int M;
	cin >> M;
	int sum_num = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			sum_num += map[i][j];
			sum_map[i][j] = sum_num;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int srt_y, srt_x, end_y, end_x;
		cin >> srt_y >> srt_x >> end_y >> end_x;


		cout << prefix(srt_y, srt_x, end_y, end_x) << '\n';

	}


	return 0;
}