from collections import deque

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def bfs(x, y):
    q = deque()
    q.append([x, y])
    visited[x][y] = 1
    while q:
        popleft = q.popleft()
        cx = popleft[0]
        cy = popleft[1]
        del_count = 0
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if not visited[nx][ny] and arr[nx][ny] == 0 and arr[cx][cy] > 0:
                arr[cx][cy] -= 1
            if arr[nx][ny] != 0 and not visited[nx][ny]:
                visited[nx][ny] = 1
                q.append([nx, ny])

answer = 0
while True:
    cnt = 0
    visited = [[0] * m for _ in range(n)]
    finish = True
    for i in range(n):
        for j in range(m):
            if arr[i][j] != 0 and not visited[i][j]:
                finish = False
                bfs(i, j)
                cnt += 1
                if cnt > 1:
                    break
    if finish:
        print(0)
        break
    if cnt > 1:
        print(answer)
        break
    elif cnt == 0:
        print(0)
    answer += 1

