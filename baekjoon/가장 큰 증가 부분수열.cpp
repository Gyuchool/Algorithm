#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        int now = i;
        dp[now] = arr[now];
        for (int j = 0; j < i; j++) {
            if (arr[now] > arr[j]) {
                dp[now] = max(dp[now], dp[j] + arr[now]);
            }
        }
    }

    sort(dp, dp + n, greater<>());
    cout << dp[0];
}
