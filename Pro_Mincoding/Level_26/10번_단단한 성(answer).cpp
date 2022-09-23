#include<iostream>
using namespace std;
int main() {
	int map[4][4] = {
		0,0,0,0,
		0,1,1,0,
		2,2,3,0,
		1,3,3,1
	};
	bool safe = true;
	for (int j = 0; j < 4; j++) {
		for (int i = 3; i > 0; i--) {
			if (map[i][j] < map[i - 1][j])
				safe = false;
		}
	}

	if (safe)
		cout << "안전한 성";
	else
		cout << "안전하지않은성";
	return 0;
}