#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int arr[101][101];
int cpy[101][101];
int visited[101][101];
int n, m;

void bfs(int x, int y) {
	visited[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int cx = nx + dx[i];
			int cy = ny + dy[i];

			if (cx < 0 || cy < 0 || cx >= n || cy >= m)
				continue;

			if (!visited[cx][cy] && cpy[cx][cy] == 0) {
				cpy[cx][cy] = cpy[nx][ny] + 1;
				visited[cx][cy] = 1;
				q.push(make_pair(cx, cy));
			}
		}
	}

	
}

void bfs2(int x, int y, int& check) {
	check = 0;
	visited[x][y] = 1;
	queue<pair<int, int>> q2;
	q2.push(make_pair(x, y));

	while (!q2.empty()) {
		int nx = q2.front().first;
		int ny = q2.front().second;
		q2.pop();

		for (int i = 0; i < 4; ++i) {
			int cx = nx + dx[i];
			int cy = ny + dy[i];

			if (cx < 0 || cy < 0 || cx >= n || cy >= m)
				continue;
			if (!visited[cx][cy] && arr[cx][cy] == 2) {
				arr[cx][cy] = arr[nx][ny] + 1;
				visited[cx][cy] = 1;
				check = 1;
				q2.push(make_pair(cx, cy));

			}
			else if (!visited[cx][cy] && arr[cx][cy] == 0) {
				arr[cx][cy] = arr[nx][ny] + 1;
				visited[cx][cy] = 1;
				q2.push(make_pair(cx, cy));
			}
		}
	}
	
	
}

int main() {
	int T;
	int check = 0;
	cin >> n >> m >> T;//세로 가로 시간

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			cpy[i][j] = arr[i][j];
		}
	}
	//검 안갖고 최단거리
	bfs(0, 0);
	if (cpy[n - 1][m - 1] == 0) {//방법 없음
		v.push_back(10000000);
	}
	else
		v.push_back(cpy[n - 1][m - 1]);



	//검 갖고 최단거리
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = 0;
		}
	}

	int soward_x;
	int soward_y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
		
			if (arr[i][j] == 2) {
				soward_x = j;
				soward_y = i;
				break;
			}
		}
	}
	int result = 0;
	bfs2(0, 0, check);
	
	if (check==1) {
		result = (n - 1 - soward_y) + (m - 1 - soward_x);
		result = arr[soward_y][soward_x] + result;
	}
	else {
		result = 1000000;
	}
	
	v.push_back(result);

	sort(v.begin(), v.end());
	
	if(v[0] >T || v[0]==1000000){
		cout << "Fail";
	}
	else if (v[0] <= T) {
		cout << v[0];
	}
	
	
}
