#include <iostream>
using namespace std;

#define MODE 1000000000;
long long dp[101][10];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int k = 0;

	for (int i = 1; i < 10; ++i) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		for (k = 0; k < 10; ++k) {
			if (k == 0) {
				dp[i][k] = dp[i - 1][k + 1];
			}
			else if (k == 9) {
				dp[i][k] = dp[i - 1][k - 1];
			}
			else
				dp[i][k] = (dp[i - 1][k - 1] + dp[i - 1][k + 1])%MODE;
		}
	}
	long long answer = 0;
	for (int i = 0; i < 10; ++i) {
		answer = (answer + dp[n][i]) % MODE;
	}
	cout << answer;
}
