from collections import deque

n = int(input())
arr = [list(map(int, input())) for _ in range(n)]
visited = [[0] * 25 for _ in range(25)]
answer = []
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def bfs(x, y):
    q = deque()
    cnt = 1
    q.append([x, y])
    visited[x][y] = 1
    while q:
        popleft = q.popleft()
        cx = popleft[0]
        cy = popleft[1]
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            if not visited[nx][ny] and arr[nx][ny] == 1:
                visited[nx][ny] = 1
                cnt += 1
                q.append([nx, ny])
    answer.append(cnt)


for i in range(n):
    for j in range(n):
        if arr[i][j] == 1 and not visited[i][j]:
            bfs(i, j)

answer = sorted(answer)
print(len(answer))
for a in answer:
    print(a)
