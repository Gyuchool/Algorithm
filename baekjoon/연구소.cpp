#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[9][9];
int cpy[9][9];
int dx[] = { -1, 1,0,0 };
int dy[] = { 0,0,-1,1 };
int visited[9][9];
int cnt = 0;
queue<pair<int, int>> q;
int answer = -1;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cpy[i][j] = arr[i][j];
	
		}
	}
}
void swarm(queue<pair<int, int>> q) {

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
	
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (cpy[nx][ny] == 0) {
				cpy[nx][ny] = 2;
			
				q.push({ nx,ny });
			}
		}
	}

	int safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cpy[i][j] == 0) {
				safe++;
			}
		}
	}

	answer = max(safe, answer);
}
void wall(int cnt, queue<pair<int, int>> q) {
	if (cnt == 3) {
		init();
		swarm(q);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(cnt + 1, q);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i,j });
			}
		
		}
	}
	wall(0, q);

	cout<<answer;
}
