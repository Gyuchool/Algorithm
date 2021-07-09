#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dx[16];
int dy[16];

int go(int x, int y) {

	for (int i = 0; i < y; ++i) {
		if (dx[i] == x || dy[i] == y || abs(x - dx[i]) == abs(y - dy[i]))
			return 0;
	}
	if (y == n - 1) {
		return 1;
	}
	dx[y] = x;
	dy[y] = y;	
	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		cnt += go(i, y + 1);
	}
	return cnt;
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int result = 0;

	for (int i = 0; i < n; ++i) {
		result += go(i, 0);
	}
	cout << result;

	return 0;
}
