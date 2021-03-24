#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int time[1001];
int dp[100001];
int degree[100001];
vector<int> v[100001];

int a, b, c;

void clear() {
	for (int i = 1; i <= n; ++i) {
		dp[i] = 0;
		time[i] = 0;
		degree[i] = 0;
		fill(v[i].begin(), v[i].end(), 0);
	}
}
void bfs() {
	queue<int> q;

	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) {
			q.push(i);
			dp[i] = time[i];
		}

	}
	while (!q.empty()) {

		int edge = q.front();
		q.pop();

		for (int i = 0; i < v[edge].size(); ++i) {
			int nedge = v[edge][i];
			dp[nedge] = max(dp[nedge], dp[edge] + time[nedge]);

			if (--degree[nedge] == 0) {
				q.push(nedge);
			}

		}
	}
}
int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; ++x) {

		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> time[i];
		}
		for (int i = 1; i <= k; ++i) {
			cin >> a >> b;
			v[a].push_back(b);
			degree[b]++;
		}

		bfs();
		cin >> c;
		cout << dp[c]<<'\n';
		clear();
	}


}
