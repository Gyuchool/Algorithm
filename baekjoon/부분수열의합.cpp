#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int arr[21];
int answer = 0;
int sum;

void go(int cnt) {
    if (sum == s) {
        answer++;
    }

    for (int i = cnt; i < n; ++i) {
        sum += arr[i];
        go(i + 1);
        sum -= arr[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> s;
    bool zero = false;
    if (s == 0) {
        zero = true;
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    go(0);

    if (zero) {
        answer--;
    }
    cout << answer;
}
