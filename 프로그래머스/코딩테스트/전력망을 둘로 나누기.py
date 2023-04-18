from collections import defaultdict
from collections import deque

graph = defaultdict(list)

def bfs(x, visited):
    q = deque()
    q.append(x)
    cnt = 0
    while q:
        cx = q.popleft()
        for node in graph[cx]:
            if not visited[node]:
                cnt+=1
                visited[node] = 1
                q.append(node)
    return cnt
                
def solution(n, wires):
    answer = n+1
    for wire in wires:
        s, e = wire
        graph[s].append(e)
        graph[e].append(s)
    for wire in wires:
        visited =[0] * (n+1)
        s, e = wire
        visited[s] = 1
        visited[e] = 1
        cnt1 = bfs(s, visited[:])
        cnt2 = bfs(e, visited[:])
        answer = min(answer, abs(cnt1 - cnt2))
        
    return answer
