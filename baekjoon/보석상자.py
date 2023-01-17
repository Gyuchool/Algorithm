import sys

n, m = map(int, sys.stdin.readline().split())
arr = []
for i in range(m):
    arr.append(int(sys.stdin.readline()))

arr.sort()
s = 1
e = arr[-1]
answer = 0
while s <= e:
    mid = (s + e) // 2
    sum = 0
    for a in arr:
        if a % mid == 0:
            sum += a // mid
        else:
            sum += (a // mid) + 1
    if sum <= n:
        answer = mid
        e = mid - 1
    else:
        s = mid + 1

print(answer)
