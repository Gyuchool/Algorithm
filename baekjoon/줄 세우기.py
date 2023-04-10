from collections import defaultdict
from collections import deque

graph = defaultdict(list)

N, M = map(int, input().split())
degree = [0] * (N + 1)
answer = [0] * (N + 1)

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)  # a가 먼저할 것
    degree[b] += 1

result = []

def sort():
    q = deque()
    for i in range(1, 1 + N):
        if degree[i] == 0:
            q.append(i)
            result.append(i)
    while q:
        cNode = q.popleft()
        for nNode in graph[cNode]:
            degree[nNode] -= 1
            if degree[nNode] == 0:
                result.append(nNode)
                q.append(nNode)

sort()

for i in range(1, N + 1):
    if not i in result:
        result.append(i)
for res in result:
    print(res, end=' ')
