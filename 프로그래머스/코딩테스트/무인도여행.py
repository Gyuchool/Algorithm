from collections import deque
visited = [[0]*100 for _ in range(100)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def bfs(x, y, maps):
    q =deque()
    result = int(maps[x][y])
    q.append([x,y])
    visited[x][y]= 1
    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx<0 or ny<0 or nx>=len(maps) or ny>=len(maps[0]):
                continue
            if not visited[nx][ny] and maps[nx][ny] != "X":
                visited[nx][ny]=1
                result+=int(maps[nx][ny])
                q.append([nx, ny])
    return result
                
def solution(maps):
    answer = []
    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if not visited[i][j] and maps[i][j] != "X":
                answer.append(bfs(i, j, maps))
    if answer:
        answer.sort()
        return answer
    return [-1]
