#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int arr[51][51];
int visited[51][51];
queue<pair<int, int>> q;
queue<pair<int, int>> tmp;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int n, l, r;
bool flag = true;

void bfs(int x, int y)
{
	q.push({ x,y });
	tmp.push({ x, y });
	visited[x][y] = 1;
	int sum = arr[x][y];
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for(int i=0; i<4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if(l <= abs(arr[nx][ny] - arr[cx][cy]) && abs(arr[nx][ny] - arr[cx][cy]) <=r)
			{
				if(!visited[nx][ny])
				{
					flag = true;
					visited[nx][ny] = 1;
					sum += arr[nx][ny];
					q.push({ nx, ny });
					tmp.push({ nx, ny });
				}
				
			}
		}
	}
	int ans = sum / tmp.size();
	while (!tmp.empty())
	{
		arr[tmp.front().first][tmp.front().second] = ans;
		tmp.pop();
	}
}

void clear()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int result = -1;
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	while(flag)
	{
		flag = false;
		clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j]) {
					bfs(i, j);
				}
			}
		}
		result++;
	}
	cout << result;
	

}
