#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[301][301];
int dp[301][301];
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int k;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = m - (x + y);
		if (arr[x][y] < 0) {
			arr[x][y] = 0;
		}
		dp[x][y] = arr[x][y];

	}
	
	for (int i = 1; i < 300; ++i) {
		for (int j = 1; j < 300; ++j) {
			
			dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
			k = max(dp[i][j], k);
		}
	}
	cout << k;

}
