#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[101][101];
int visited[101][101];
int cpy[101][101];
int level = 0; // 물높이
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;

			if (!visited[nx][ny] && cpy[nx][ny] != 1) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}
int main() {
	cin >> n;
	int answer = -1;
	int top = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			top = max(top, arr[i][j]);
		}
	}
	for (int k = 1; k <= top; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr[i][j] < k) {
					cpy[i][j] = 1;
				}
				visited[i][j] = 0;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!visited[i][j] && cpy[i][j] != 1) { // 물에 안잠겼다면
					bfs(i, j);
					cnt++;
				}
			}
		}
		answer = max(answer, cnt);
		
	}
	cout << answer;
}
