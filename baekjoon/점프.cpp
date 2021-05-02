#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[101][101];
long long dp[101][101];

long long dfs(int x, int y) {

	if (x == n - 1 && y == n - 1) {
		return 1;
	}
	else if (dp[x][y] == -1) {
	
		dp[x][y] = 0;
		if (x >= 0 && y >= 0 && x + arr[x][y] < n && y < n) {
			dp[x][y] += dfs(x + arr[x][y], y);
		}
		if (x >= 0 && y >= 0 && y + arr[x][y] < n && x < n) {
			dp[x][y] += dfs(x, y + arr[x][y]);
		}
	}

	return dp[x][y];
}
int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0);

}
