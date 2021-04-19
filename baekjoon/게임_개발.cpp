#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[501];
int time[501];
int degree[501];
int dp[501];

int n;
queue<int> q;

void bfs() {
	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) {
			q.push(i);
			dp[i] = time[i];
		}
	}

	while (!q.empty())
	{
		int edge = q.front();
		q.pop();

		for (int i = 0; i < v[edge].size(); ++i) {
			int e = v[edge][i];
			dp[e] = max(dp[e], dp[edge] + time[e]);
			if (--degree[e] == 0) {
				q.push(e);
			}
		}
	}
}
int main() {
	int x;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> time[i];
		while (1) {
			cin >> x;

			if (x == -1) {
				break;
			}
			v[x].push_back(i);
			degree[i]++;
		}
		
	}
	
	bfs();
	for (int i = 1; i <= n; ++i) {
		cout << dp[i] << '\n';
	}
	return 0;

}
