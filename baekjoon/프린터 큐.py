from collections import deque

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    q= deque()
    values = list(map(int, input().split()))
    for i in range(n):
        q.append([i,values[i]])
    cnt = 1
    values.sort(reverse=True)
    valuesIndex = 0
    while q:
        id, value = q.popleft()
        if values[valuesIndex] == value:
            if id == m:
                print(cnt)
                break
            valuesIndex+=1
            cnt+=1
        else:
            q.append([id, value])
