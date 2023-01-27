from collections import deque
visited = [[0]*101 for _ in range(101)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def bfs(maps):
    q = deque()
    q.append([0,0])
    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx<0 or ny < 0  or nx >=len(maps) or ny >=len(maps[0]):
                continue
            if not visited[nx][ny] and maps[nx][ny] == 1:
                visited[nx][ny] = 1
                maps[nx][ny] = maps[cx][cy] + 1
                q.append([nx, ny])
                
def solution(maps):
    answer = 0
    bfs(maps)
    if maps[-1][-1] == 1:
        answer = -1
    else:
        answer = (maps[-1][-1])
        
    return answer
