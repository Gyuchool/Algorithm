#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001][1001];

int main() {
	string main_str, sub_str;
	
	cin >> main_str >> sub_str;
	
	main_str = "0" + main_str;
	sub_str = "0" + sub_str;
	
	int main_len = main_str.length();
	int sub_len = sub_str.length();
	
	for (int i = 1; i < main_len; ++i) {
		for (int j = 1; j < sub_len; ++j) {
			if (main_str[i] == sub_str[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[main_len - 1][sub_len - 1];
	return 0;
}
