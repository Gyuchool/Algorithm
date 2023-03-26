from collections import deque

n, k = map(int, input().split())
visited = [0] * 100001

def bfs(n, k, cnt):
    q = deque()
    q.append([n, cnt])
    while q:
        cn, ccnt = q.popleft()
        if cn<0 or cn>100000:
            continue

        if visited[cn]:
            continue
        visited[cn] = 1
        if cn == k:
            return ccnt
        q.append([cn - 1, ccnt + 1])
        q.append([cn + 1, ccnt + 1])
        q.append([cn * 2, ccnt + 1])


print(bfs(n, k, 0))
