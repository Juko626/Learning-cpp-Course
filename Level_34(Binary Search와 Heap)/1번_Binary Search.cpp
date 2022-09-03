#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> v={4,4,5,7,8,10,20,22,23,24};
int main()
{
	int end_idx = v.size();
	int srt_idx = 0;
	
	

	int target;
	cin >> target;

	for (int i = 0; i < v.size(); i++)
	{
		int mid_idx = (end_idx + srt_idx)/2;
		if (v[mid_idx] == target)
		{
			cout << 'O';
			return 0;
		}
		else if (v[mid_idx] < target)
		{
			srt_idx = mid_idx;

		}
		else if (v[mid_idx] > target)
		{
			end_idx = mid_idx;
		}
	}
	cout << 'X';
	
}