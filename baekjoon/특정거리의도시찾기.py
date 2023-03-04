from collections import defaultdict
from collections import deque
import sys

graph = defaultdict(list)
visited = [0]*1000001
n, m, k, x = map(int, sys.stdin.readline().split())
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
answers= []

def bfs(start):
    q =deque()
    q.append([start, 0])
    visited[start] = 1
    while q:
        cx, distance = q.popleft()
        if distance == k:
           answers.append(cx)
        for nx in graph[cx]:
            if not visited[nx]:
                visited[nx] = 1
                q.append([nx, distance + 1])
bfs(x)
if answers:
    answers.sort()
    for answer in answers:
        print(answer)
else:
    print(-1)
