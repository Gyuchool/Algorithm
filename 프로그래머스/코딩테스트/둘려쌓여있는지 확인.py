from collections import deque

visited = [[0] * 1001 for _ in range(1001)]
dx = [0, 0, 1, -1, -1, -1, 1, 1]
dy = [-1, 1, 0, 0, -1, 1, -1, 1]


def checkCircuit(x, y):
    check[x][y] = 1
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]


def bfs(x, y, grid):
    q = deque()
    q.append([x, y])
    visited[x][y] = 1
    while q:
        cx, cy = q.popleft()
        for i in range(8):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= len(grid) or ny >= len(grid[0]):
                continue
            if not visited[nx][ny] and grid[nx][ny] == '#':
                q.append([nx, ny])
                visited[nx][ny] = 1


def swarm(x, y, grid):
    q = deque()
    nothing = False
    tmp = []
    q.append([x, y])
    tmp.append([x,y])
    visited[x][y] = 2
    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= len(grid) or ny >= len(grid[0]):
                nothing = True
                continue
            if not visited[nx][ny] and grid[nx][ny] == '.':
                q.append([nx, ny])
                tmp.append([nx, ny])
                visited[nx][ny] = 2
    if not nothing:
        for xx, yy in tmp:
            visited[xx][yy] = 1


def solution(grid):
    answer = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if not visited[i][j] and grid[i][j] == '.':
                swarm(i, j, grid)
            if not visited[i][j] and grid[i][j] == '#':
                bfs(i,j,grid)
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if visited[i][j] == 1:
                answer+=1
    return answer
