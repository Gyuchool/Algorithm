import copy
from collections import deque

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
visited = [[0] * m for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

answer = -1


def bfs(test, x, y, vvisited):
    q = deque()
    q.append([x, y])
    vvisited[x][y] = 1
    while q:
        popleft = q.popleft()
        cx = popleft[0]
        cy = popleft[1]
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if not vvisited[nx][ny] and test[nx][ny] != 1:
                vvisited[nx][ny] = 1
                test[nx][ny] = 2
                q.append([nx, ny])


def swarm():  # 바이러스 퍼뜨리기
    test = copy.deepcopy(arr)
    aanswer = 0
    vvisited = [[0] * m for _ in range(n)]
    for ar in list:
        bfs(test, ar[0], ar[1], vvisited)

    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if test[i][j] == 0:
                aanswer+=1
    return aanswer


def installWall(cnt):
    global answer
    if cnt == 0:  # swarm해서 검사하기
        answer = max(answer, swarm())
        return
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if not visited[i][j]:
                if arr[i][j] == 0 and cnt > 0:
                    visited[i][j] = 1
                    arr[i][j] = 1
                    installWall(cnt - 1)
                    arr[i][j] = 0
                    visited[i][j] = 0

list = []
for i in range(len(arr)):
    for j in range(len(arr[i])):
        if arr[i][j] == 2:
            list.append([i,j])
installWall(3)
print(answer)
