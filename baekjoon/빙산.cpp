#include<iostream>
#include <queue>

using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int arr[301][301];
int visited[301][301];

int n, m;

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
        }
    }
}
void melt(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        int cnt = 0;
        for(int i=0;i<4;i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if(!visited[nx][ny] && arr[nx][ny]==0)
            {
                cnt++;
            }else if(!visited[nx][ny] && arr[nx][ny] != 0)
            {
                q.push({ nx, ny });
                visited[nx][ny] = 1;
            }
        }

        if(arr[cx][cy] - cnt <0)
        {
            arr[cx][cy] = 0;
        }else
        {
            arr[cx][cy] -= cnt;
        }
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
    int answer = 0;

    while(true)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && arr[i][j])
                {
                    count++;
                    melt(i, j);
                }
            }
        }
        if(count >=2 )
        {
            break;
        }
        if (count == 0) {
            answer=0;
            break;
        }
        answer++;
        init();

    }
    cout << answer;

}
