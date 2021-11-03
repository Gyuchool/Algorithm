#include <vector>
#include <algorithm>
#include <queue>
#include<iostream>
using namespace std;

int visited[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int n, m;

queue<pair<int, int>> q;

void bfs(vector<vector<int> > maps, int x, int y) {
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (!visited[nx][ny] && maps[nx][ny] == 1) {
			
				if (visited[nx][ny] > visited[cx][cy] + 1) {
					visited[nx][ny] = visited[cx][cy] + 1
					q.push({ nx, ny });
				}
			}
		}
	}
}
int solution(vector<vector<int> > maps)
{
	n = maps.size();
	m = maps[0].size();

	bfs(maps, 0, 0);
	int answer = 0;

	answer = visited[n - 1][m - 1];
	if (answer == 0) {
		answer = -1;
	}

    return answer;
}
