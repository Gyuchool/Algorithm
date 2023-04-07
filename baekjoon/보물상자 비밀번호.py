import sys
from collections import deque

sys.stdin = open("input.txt", "r")

converter = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}

def cut(N, arr):
    tmp = list()
    for i in range(0, N, N // 4):
        tmp.append(arr[i:i + (N // 4)])
    return list(map(tuple, tmp))


def convertToTen(sixteen):
    idx = len(sixteen)-1
    result = 0
    for ch in sixteen:
        if not '0' <= ch <= '9':
            result += converter[ch] * (16 ** idx)
        else:
            result += int(ch) * (16 ** idx)
        idx-=1
    return result

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
arr = []
for test_case in range(1, T + 1):
    candidate = set()
    N, K = map(int, input().split())
    size = N // 4
    s = list(input())
    first = cut(N, s)
    q = deque(s)
    candidate.update(set(first))
    while True:
        q.rotate(1)
        cutting = cut(N, list(q))
        if set(cutting) == set(first):
            break
        candidate.update(set(cutting))
    real = []
    for answer in candidate:
        real.append(convertToTen(list(answer)))
    real.sort(reverse=True)
    print(f'#{test_case} {real[K - 1]}')
