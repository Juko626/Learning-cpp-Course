#include<iostream>
using namespace std;

int a[3][3];
int b[3][3];

void input()
{
	int x, y;

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			cin >> a[y][x];
		}
	}

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			cin >> b[y][x];
		}
	}
}

void spin()
{
	int x, y;
	int result[3][3] = { 0 };
	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			result[2 - x][y] = a[y][x];
		}
	}

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			a[y][x] = result[y][x];
		}
	}
}

int isCompare()
{
	int x, y;
	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			if (a[y][x] != b[y][x]) return 0;
		}
	}
	return 1;
}

int main() {
	
	input();

	for (int i = 0; i < 4; i++) {
		if (isCompare() == 1) {
			cout << i;
			break;
		}
		spin();
	}

	return 0;
}