import sys
from collections import deque

def solution(stones, k):
    q = deque()
    list = []

    for i in range(k):
        q.append(stones[i])
    m = max(q)
    length = len(stones)
    if k == 1:
        return min(stones)

    for i in range(k, length):
        popleft = q.popleft()
        if popleft == m:
            m = max(q)
            m = max(m, stones[i])
        q.append(stones[i])
        list.append(m)

    return min(list)
