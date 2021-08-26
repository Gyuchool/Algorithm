#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };


int dfs(int x, int y) {

	if (dp[x][y])
		return dp[x][y];
	dp[x][y] = 1;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;

		if (arr[nx][ny] > arr[x][y]) {
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}
	}

	return dp[x][y];
}
int main() {

	cin >> n;
	int ma = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ma = max(ma, dfs(i, j));
		}
	}
	cout << ma;
}
