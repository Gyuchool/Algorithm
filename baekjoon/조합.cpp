#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//90 56
string dp[101][101];

string add(string s1, string s2) {
	int carry = 0;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	while (s1.length() < s2.length()) {
		s1 += '0';
	}
	while (s1.length() > s2.length()) {
		s2 += '0';
	}

	
	string res = "";
	int m = s2.size();
	for (int i = 0; i < m; ++i) {
		int sum = s1[i] - '0' + s2[i] - '0' + carry;
		if (sum / 10) {
			carry = 1;
			sum %= 10;
			res += sum + '0';
		}
		else {
			carry = 0;
			res += sum + '0';
		}
	}
	if (carry) {
		res += '1';
	}

	reverse(res.begin(), res.end());
	return res;
	
}
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; ++i) {
		dp[i][0] = "1";
		dp[i][i] = "1";
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = add(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	cout << dp[n][m];
}
