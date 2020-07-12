#include <iostream>
#include <queue>
using namespace std;

int dx[] ={-1, 0, 1, 0};
int dy[] ={0, -1, 0, 1};
int arr[101][101];
int cpy[101][101];
int visit[101][101];
int n,m;

int bfs(int x, int y){
	queue<pair<int, int>> q;

	q.push(make_pair(x,y));
	visit[x][y] = true;

	while(!q.empty()){
		int ax = q.front().first;
		int ay = q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			int nx = ax + dx[i];
			int ny = ay + dy[i];

			if(nx < 0 || nx > n || ny < 0 || ny > m)
				continue;

			if(arr[nx][ny]==1 && !visit[nx][ny]){
				cpy[nx][ny]=cpy[ax][ay] + 1;
				
				q.push(make_pair(nx, ny));
				visit[nx][ny] = true;
			}
			if(nx == n && ny == m){
				return cpy[nx][ny];
			}
		}
	}
	return 0;
}

int main(){
	cin >> n >> m;

	for(int i=1; i<= n; ++i){
		for(int j=1; j<=m; ++j){
			scanf("%1d", &arr[i][j]);
			cpy[i][j] = arr[i][j];
		}
	}

	cout << bfs(1, 1) << endl;
	return 0;
}
