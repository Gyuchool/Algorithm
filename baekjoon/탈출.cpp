#include <iostream>
#include <queue>
using namespace std;

int n, t, g;
int visited[100000];
int value(int x) {
	int tmp = 1;
	x *= 2;
	if (x >= 99999) {
		return -1;
	}
	int val = x;
	while (1) {
		if (!x)break;
		x /= 10;
		tmp *= 10;
	}
	tmp /= 10;
	tmp = val - tmp;
	
	return tmp;
}
int bfs(int x, int cnt) {
	queue<pair<int, int>> q;
	q.push({ x,cnt });
	visited[x] = 1;
	
	while (!q.empty()) {
		int cx = q.front().first;
		int ccnt = q.front().second;
		q.pop();

		if (ccnt > t) {
			break;
		}
		if (cx == g) {
			return ccnt;
		}

		int nx = cx + 1;
		if (nx <= 99999 && !visited[nx]) {
			visited[nx] = 1;
			q.push({ nx, ccnt + 1 });
		}

		int nx2 = value(cx);
		if (nx2 == -1) {
			continue;
		}
		if (nx2 <= 99999 && !visited[nx2]) {
			visited[nx2] = 1;
			q.push({ nx2, ccnt + 1 });
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> t >> g;

	int res = bfs(n,0);
	if (res != -1) {
		cout << res << endl;
	}
	else {
		cout << "ANG" << endl;
	}
}
