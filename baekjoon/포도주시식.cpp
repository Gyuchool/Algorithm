#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(max(arr[0] + arr[1], arr[1] + arr[2]), arr[0] + arr[2]);
	for (int i = 3; i < n; ++i) {
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], max(dp[i - 1], arr[i] + dp[i - 2]));
	}
	cout << dp[n - 1];

}
