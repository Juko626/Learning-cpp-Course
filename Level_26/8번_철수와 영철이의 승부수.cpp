#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;



string str = "01";
char path[10];
int fail_cnt = 0;
int win_cnt = 0;
string result;
void dfs(int lev) 
{
	if (lev == 3)
	{
		result = "";
		win_cnt = 0;
		fail_cnt = 0;
		for (int i = 0; i < 3; i++)
		{
			if (path[i] == '0')
			{
				win_cnt++;
			}
			else if (path[i] == '1')
			{
				fail_cnt++;
			}
			result += path[i];
		}


		if (win_cnt == 0 && fail_cnt!=0)
		{
			cout << fail_cnt << "패" << "(";
			for (int k = 0; k < result.size(); k++)
			{
				if (result[k] == '0')
				{
					cout << "승";
				}
				else if (result[k] == '1')
				{
					cout << "패";
				}
			}
			cout << ")" << '\n';
		}
		else if (win_cnt != 0 && fail_cnt == 0)
		{
			cout << win_cnt << "승" << "(";
			for (int k = 0; k < result.size(); k++)
			{
				if (result[k] == '0')
				{
					cout << "승";
				}
				else if (result[k] == '1')
				{
					cout << "패";
				}
			}
			cout << ")" << '\n';
		}

		else if (win_cnt != 0 && fail_cnt != 0)
		{
			cout << win_cnt << "승" << fail_cnt << "패" << "(";
			for (int k = 0; k < result.size(); k++)
			{
				if (result[k] == '0')
				{
					cout << "승";
				}
				else if (result[k] == '1')
				{
					cout << "패";
				}
			}
			cout << ")" << '\n';
		}
		
		
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		path[lev] = str[i];
		dfs(lev + 1);

	}

}


int main()
{



	dfs(0);
	return 0;
}