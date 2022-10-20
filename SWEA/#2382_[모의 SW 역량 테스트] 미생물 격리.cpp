#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;



int direct_Y[5] = { 0,-1,1,0,0 };
int direct_X[5] = { 0,0,0,-1,1 };
int final_result = 0;


int result;
typedef struct {
	int y;
	int x;
	int cnt;
	int dir;
}cell;

cell real_map[100][100];
cell used_map[100][100];
void used_map_init(int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			used_map[i][j].cnt = 0;
			used_map[i][j].x = 0;
			used_map[i][j].y = 0;
			used_map[i][j].dir=0;
		}
	}
}

bool compare( cell a1, cell b1)
{
	if (a1.cnt > b1.cnt) return true;
	if (a1.cnt < b1.cnt) return false;
	if (a1.cnt == b1.cnt) return false;
	return false;
}	

//queue<cell> v2;
vector<cell> v1;
int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		
		int N;
		int M;
		int K;
		cin >> N;
		cin >> M;
		cin >> K;
		v1.clear();
		for (int i = 0; i < K; i++)
		{
			int idx_y;
			int idx_x;
			int cnt_miseng;
			int direction;
			cin >> idx_y;
			cin >> idx_x;
			cin >> cnt_miseng;
			cin >> direction;
			v1.push_back({ idx_y, idx_x, cnt_miseng, direction });
		}
		
		//1~M 초


		for (int i = 0; i < M; i++)
		{
			sort(v1.begin(), v1.end(), compare);

			int daa = 0;
			// v1에 있는 걸 하나씩 옮겨야함
			//used_map 초기화
			for (int j = 0; j < v1.size(); j++)
			{
				//1 1 7 1 
				//used_map_init(N);


				//방향이 1 == 상 일 때
				if (v1[j].dir == 1)
				{
					//겹쳐진다는 다면??
					if ((used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]]).cnt != 0)
					{
						
					
						if (used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].cnt < v1[j].cnt)
						{
							used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].cnt += v1[j].cnt;
							used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].dir = 1;
							//used_map[v1[j].y][v1[j].x].dir = 0;
							//used_map[v1[j].y][v1[j].x].cnt = 0;
						}
						else
						{
							used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].cnt += v1[j].cnt;
							used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].dir = used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].dir;

						}
						real_map[v1[j].y][v1[j].x] = { v1[j].y, v1[j].x, 0, 0 };
						continue;
						//여기에 겹쳐지는 함수 실행해야함
					}
					if (v1[j].y + direct_Y[1] <= 0 || v1[j].y + direct_Y[1] >= N - 1 || v1[j].x + direct_X[1] <= 0 || v1[j].x + direct_X[1] >= N - 1)
					{
						used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].cnt = v1[j].cnt / 2;
						
						used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].dir = 2;
						continue;
					}
					used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].cnt = v1[j].cnt;
					used_map[v1[j].y + direct_Y[1]][v1[j].x + direct_X[1]].dir = 1;


				}
				//방향이 2 == 하 일 때
				else if (v1[j].dir == 2)
				{
					//겹쳐진다는 다면??
					if ((used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]]).cnt != 0)
					{
						if (used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].cnt < v1[j].cnt)
						{
							used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].cnt += v1[j].cnt;
							used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].dir = 2;
							//used_map[v1[j].y][v1[j].x].dir = 0;
							//used_map[v1[j].y][v1[j].x].cnt = 0;
						}
						else
						{
							used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].cnt += v1[j].cnt;
							used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].dir = used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].dir;

						}
						//real_map[v1[j].y][v1[j].x] = { v1[j].y, v1[j].x, 0, 0 };
						continue;
						//여기에 겹쳐지는 함수 실행해야함
					}
					if (v1[j].y + direct_Y[2] <= 0 || v1[j].y + direct_Y[2] >= N - 1 || v1[j].x + direct_X[2] <= 0 || v1[j].x + direct_X[2] >= N - 1)
					{
						used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].cnt = v1[j].cnt / 2;
						used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].dir = 1;
						continue;
					}
					used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].cnt = v1[j].cnt;
					used_map[v1[j].y + direct_Y[2]][v1[j].x + direct_X[2]].dir = 2;


				}
				//방향이 3 == 좌 일 때
				else if (v1[j].dir == 3)
				{
					//겹쳐진다는 다면??
					if ((used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]]).cnt != 0)
					{
						if (used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].cnt < v1[j].cnt)
						{
							used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].cnt += v1[j].cnt;
							used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].dir = 3;
							//used_map[v1[j].y][v1[j].x].dir = 0;
							//used_map[v1[j].y][v1[j].x].cnt = 0;
						}
						else
						{
							used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].cnt += v1[j].cnt;
							used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].dir = used_map[v1[j].y+direct_Y[3]][v1[j].x+direct_X[3]].dir;

						}
						real_map[v1[j].y][v1[j].x] = { v1[j].y, v1[j].x, 0, 0 };
						continue;
						//여기에 겹쳐지는 함수 실행해야함
					}
					if (v1[j].y + direct_Y[3] <= 0 || v1[j].y + direct_Y[3] >= N - 1 || v1[j].x + direct_X[3] <= 0 || v1[j].x + direct_X[3] >= N - 1)
					{
						used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].cnt = v1[j].cnt / 2;
						used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].dir = 4;
						continue;
					}

					used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].cnt = v1[j].cnt;
					used_map[v1[j].y + direct_Y[3]][v1[j].x + direct_X[3]].dir = 3;


				}
				//방향이 4 == 우 일 떄
				else if (v1[j].dir == 4)
				{
					//겹쳐진다는 다면??
					if ((used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]]).cnt != 0)
					{
						if (used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].cnt < v1[j].cnt)
						{
							used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].cnt += v1[j].cnt;
							used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].dir = 4;
							//used_map[v1[j].y][v1[j].x].dir = 0;
							//used_map[v1[j].y][v1[j].x].cnt = 0;
						}
						else
						{
							used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].cnt += v1[j].cnt;
							used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].dir = used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].dir;

						} 
						//real_map[v1[j].y][v1[j].x] = { v1[j].y, v1[j].x, 0, 0 };
						continue;
						//여기에 겹쳐지는 함수 실행해야함
					}
					if (v1[j].y + direct_Y[4] <= 0 || v1[j].y + direct_Y[4] >= N - 1 || v1[j].x + direct_X[4] <= 0 || v1[j].x + direct_X[4] >= N - 1)
					{
						used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].cnt = v1[j].cnt / 2;
						used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].dir = 3;
						continue;
					}
					used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].cnt = v1[j].cnt;
					used_map[v1[j].y + direct_Y[4]][v1[j].x + direct_X[4]].dir = 4;


				}
				
				

			


			}
			v1.clear();
			for (int k = 0; k < N; k++)
			{
				for (int h = 0; h < N; h++)
				{
					if (used_map[k][h].cnt != 0)
					{
						v1.push_back({ k,h,used_map[k][h].cnt,used_map[k][h].dir });
					}
				}
			}

			int da = 1;
			for (int k = 0; k < v1.size(); k++)
			{
				result += v1[k].cnt;
			}
			final_result= result;
			result = 0;
			used_map_init(N);
			int de = 0;
		}
		
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (real_map[i][j].cnt == 0) continue;
				result += real_map[i][j].cnt;
			}
		}*/

		cout << '#' << tc+1 << ' ' << final_result << '\n';
	}


}