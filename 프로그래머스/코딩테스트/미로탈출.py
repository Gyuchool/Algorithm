from collections import deque


dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
def goTo(dest,maps, x, y):
    visited = [[0]*101 for _ in range(101)]

    q= deque()
    q.append([x, y, 0])
    visited[x][y] = 1
    
    while q:
        cx, cy, dist = q.popleft()
        if maps[cx][cy] == dest:
            return dist
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= len(maps) or ny >= len(maps[nx]):
                continue
            if not visited[nx][ny] and maps[nx][ny] != 'X':
                visited[nx][ny] = 1
                q.append([nx,ny, dist + 1])
    return -1
                
    
def solution(maps):
    answer = 0
    sx, sy = -1, -1
    lx, ly = -1, -1
    ex, ey = -1, -1
    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if maps[i][j] == 'S':
                sx, sy = i, j
            elif maps[i][j] == 'L':
                lx, ly = i, j
    tol = goTo('L', maps, sx, sy)
    toe = goTo('E', maps, lx, ly)
    if tol == -1 or toe == -1:
        return -1
    return tol + toe
