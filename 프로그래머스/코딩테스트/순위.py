from collections import deque, defaultdict

def bfs(graph, x, n):
    cnt = 0
    visited = [0]*(n+1)
    q=deque()
    q.append(x)
    visited[x] = 1

    while q:
        cx = q.popleft()
        for nx in graph[cx]:
            if not visited[nx]:
                visited[nx] = 1
                q.append(nx)
                cnt+=1
    return cnt
                
    
def solution(n, results):
    answer = 0
    downs = defaultdict(list)
    ups = defaultdict(list)
    visited = [0]*(n+1)
    for result in results:
        w, l = result
        downs[w].append(l)
        ups[l].append(w)
        
    for i in range(1, n+1):
        down = bfs(downs, i, n)
        up = bfs(ups, i, n)
        if down +1 + up == n:
            answer+=1
        
    return answer
