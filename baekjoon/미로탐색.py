from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def bfs(x, y, visited, mp):
    q = deque()
    q.append((x, y))
    visited[x][y] = 1

    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if not visited[nx][ny] and arr[nx][ny] == 1:
                mp[nx][ny] = mp[cx][cy] + 1
                visited[nx][ny] = 1
                q.append((nx, ny))


if __name__ == '__main__':
    n, m = map(int, (input().split()))
    arr = [list(map(int, input())) for _ in range(n)]
    visited = [[0] * m for _ in range(n)]
    mp = [[0] * m for _ in range(n)]
    bfs(0, 0, visited, mp)
    print(mp[n - 1][m - 1] + 1)
