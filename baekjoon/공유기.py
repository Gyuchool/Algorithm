import sys

n, m = (map(int, input().split()))
arr = []
for i in range(n):
    arr.append(int(sys.stdin.readline()))
arr.sort()
s = 0
e = arr[-1] - arr[0]

result = 0
while s <= e:
    install = 1
    start = arr[0]
    mid = (s + e) // 2
    for i in range(len(arr)):
        if arr[i] - start >= mid:
            install += 1
            start = arr[i]

    if install < m:
        e = mid - 1
    else:
        result = mid
        s = mid + 1
print(result)
