from collections import deque

n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
visited = [[0] * m for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def bfs(x, y):
    q = deque()
    q.append([x, y])
    visited[x][y] = 1
    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx >= n:
                nx = 0
            if ny >= m:
                ny = 0
            if nx < 0:
                nx = n-1
            if ny < 0:
                ny = m-1
            if not visited[nx][ny] and arr[nx][ny] == 0:
                visited[nx][ny] = 1
                q.append([nx, ny])


answer = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 0 and visited[i][j] == 0:
            bfs(i, j)
            answer += 1

print(answer)
