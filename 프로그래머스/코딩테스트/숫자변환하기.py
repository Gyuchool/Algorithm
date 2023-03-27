from collections import deque

visited = [0]*3000001

def bfs(x, y, n, cnt):
    q = deque()
    q.append([x, cnt])
    visited[x] = 1
    while q:
        cx, ccnt = q.popleft()
        if cx == y:
            return ccnt
        if cx + n < 3000001 and not visited[cx + n]:
            visited[cx + n] = 1
            q.append([cx + n, ccnt+1])
        if cx*2 < 3000001 and not visited[cx*2]:
            visited[cx*2] = 1
            q.append([cx*2, ccnt+1])
        if cx*3 < 3000001 and not visited[cx*3]:
            visited[cx*3] = 1
            q.append([cx*3, ccnt+1])
    return -1    
        
            
def solution(x, y, n):
    answer = 0
    return bfs(x, y, n, 0)    
