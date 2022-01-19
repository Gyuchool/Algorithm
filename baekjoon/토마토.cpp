//7576
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int result = 0;
int cnt = 0;
queue<pair<int, int>> q;

int n, m;
int arr[1000][1000];
int check = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int x, int y) {
	
	q.push(make_pair(x, y));
	arr[x][y] = 1;
	
	while (!q.empty()) {
		pair<int, int> current;
		current = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			int nx = current.first + dx[i];
			int ny = current.second + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
				continue;
			}
			if (arr[nx][ny]==0) {
				arr[nx][ny] = arr[current.first][current.second]+1;
				q.push(make_pair(nx, ny));
			}	
		}
	}
}

int main() {
	
	int except = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < q.size(); ++i) {
		bfs(q.front().first, q.front().second);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			
			if (result<arr[i][j]) {
				result = arr[i][j];
			}
			if (arr[i][j] == 0) {
				except = -1;
				break;
			}
		}
		if (except == -1)
			break;
	}
	if (except == -1)
		cout << except;
	else
		cout << result-1 << endl;
}
