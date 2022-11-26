#include <iostream>
#include <vector>

using namespace std;



vector<int> Nv;
vector<int> sum_Nv;
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	int N;  // 수의 개수
	cin >> N;
	int M; //구해야 하는 횟수
	cin >> M;

	int sum_N = 0;
	Nv.push_back(0);
	sum_Nv.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		int N_num;
		cin >> N_num;
		
		Nv.push_back(N_num);
		sum_N += Nv[i];

		sum_Nv.push_back(sum_N);
	}

	for (int i = 0; i < M; i++)
	{
		int srt;
		int end;
		cin >> srt >> end;
		cout << sum_Nv[end] - sum_Nv[srt - 1]<< '\n';
	}
	return 0;
}