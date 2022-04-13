#include <iostream>
#include <vector>

using namespace std;

int n, m;
int x, y;
vector<int> v[101];
int visited[101];
int ans;

void dfs(int current, int end, int cnt) {
	visited[current] = 1;

	if (current == end) {
		ans = cnt;
	}
	for (int i = 0; i < v[current].size(); i++) {
		int next = v[current][i];
		if (!visited[next]) {
			dfs(next, end, cnt + 1);
		}
	}
}
int main() {
	cin >> n;
	cin >> x >> y;
	cin >> m;

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(x, y, 0);
	if (ans != 0) {
		cout << ans;
	}
	else {
		cout << -1 << endl;
	}
}
