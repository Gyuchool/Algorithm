#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
int visited[101][101];
int answer;
int dx[] = { -1,0,1,0 };
int dy[] = { 0, -1, 0, 1 };
//외부 빈값:2, 내부 빈값: 0. 치즈 1
vector<pair<int, int>> change;
bool flag = true;

void initVisited()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void coloring(int x, int y)
{
	queue<pair<int, int>> q;
	arr[x][y] = 2;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(nx<0||ny<0||nx>=n||ny>=m || arr[nx][ny] == 1)continue;
			if(!visited[nx][ny])
			{
				arr[nx][ny] = 2;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		int contact = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] ==0)continue;
			if(arr[nx][ny] == 2)
			{
				contact++;
				continue;
			}
			if (!visited[nx][ny] && arr[nx][ny] == 1)
			{
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
		if(contact >=2)
		{
			change.push_back({ cx, cy });
		}
	}
	for (int i = 0; i < change.size(); ++i)
	{
		arr[change[i].first][change[i].second] = 2;
	}
}
int main()
{
	cin >> n >> m;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];
		
		}
	}

	while (flag)
	{
		initVisited();
		coloring(0, 0);
		initVisited();
		flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 &&!visited[i][j])
				{
					
					bfs(i, j);
					flag = true;
				}
			}
		}
		answer++;
	}

	cout << answer - 1;


}
