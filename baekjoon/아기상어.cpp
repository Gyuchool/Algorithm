#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int babySize = 2;
int babyUp = 0;
int babyX;
int babyY;
int answer;

int dx[] = { -1, 0,1, 0 };
int dy[] = { 0,-1, 0, 1 };

int n;
int arr[21][21];
int visited[21][21];
int cpy[21][21];


queue<pair<int, int>> q;
vector< pair<pair<int, int>, int>> feed;

bool compare(pair<pair<int, int>, int> i, pair<pair<int, int>, int> j) {
	if (i.second == j.second) {
		if (i.first.first == j.first.first) {
			return i.first.second < j.first.second;
		}
		return i.first.first < j.first.first;
	}
	return i.second < j.second;
}


void init() {
	q = queue<pair<int, int>>(); // q초기화
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			cpy[i][j] = 0;
		}
	}
}


bool canEat() {
	init();
	feed.clear();  //이놈때문에..기준이 바뀌므로 클리어하고 다시 찾아준다.
	q.push({ babyX, babyY });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		visited[cx][cy] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] > babySize)continue;
			if (!visited[nx][ny] && arr[nx][ny] != 0 && arr[nx][ny] < babySize) {
				visited[nx][ny] = 1;
				cpy[nx][ny] = cpy[cx][cy] + 1;
				q.push({ nx,ny });
				feed.push_back({ { nx, ny }, cpy[nx][ny]});
				
			}
			else if (!visited[nx][ny] && arr[nx][ny] <= babySize) {
				visited[nx][ny] = 1;
				cpy[nx][ny] = cpy[cx][cy] + 1;
				q.push({ nx, ny });
			}
		}

	}
	sort(feed.begin(), feed.end(), compare);
	if (feed.empty()) {
		return false;
	}

	return true;

}


void move() {

	init();

	q.push({ babyX, babyY });
	arr[babyX][babyY] = 0;

	while (!q.empty()) {

		int cx = q.front().first;
		int cy = q.front().second;

		visited[cx][cy] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] > babySize)continue;
			if (feed.empty())return;
			if (!visited[nx][ny] && nx == feed[0].first.first && ny == feed[0].first.second) {
				feed.erase(feed.begin());
				arr[nx][ny] = 0;

				babyUp++;
				babyX = nx;
				babyY = ny;
				cpy[nx][ny] = cpy[cx][cy] + 1;
				answer += cpy[cx][cy] + 1;
				if (babyUp == babySize) {
					babySize++;
					babyUp = 0;
				}
				if (canEat()) {
					move();
				}
				else {
					return;
				}

			}
			else if (!visited[nx][ny] && arr[nx][ny] <= babySize) {
				visited[nx][ny] = 1;
				cpy[nx][ny] = cpy[cx][cy] + 1;
				q.push({ nx, ny });
			}

		}
	}



}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				babyX = i;
				babyY = j;
				
			}
		}
	}
	if (canEat()) {
		move();
	}
	cout << answer;
}
