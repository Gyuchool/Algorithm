n, m, a, b = map(int, input().split())
arr = [[0] * m for _ in range(n)]
dp = [[0] * 101 for _ in range(101)]

items = []
items.append([0, m - 1])
items.append([n - 1, 0])
# [n-1][0] -> [0][m-1]
for _ in range(a):
    x, y = map(int, input().split())
    items.append([n - x, y-1])
for _ in range(b):
    x, y = map(int, input().split())
    arr[n-x][y-1] = 2
items.sort(key=lambda x: (-x[0], x[1]))

if arr[n-1][0] !=2:
    dp[n-1][0] = 1
def go(cx, cy, nx, ny):
    for i in range(cx, nx-1, -1):
        if arr[i][cy] != 2:
            dp[i][cy] = dp[cx][cy]
        else:
            break
    for j in range(cy, ny + 1):
        if arr[cx][j] != 2:
            dp[cx][j] = dp[cx][cy]
        else:
            break
    for i in range(cx-1, nx-1, -1):
        for j in range(cy+1, ny+1):
            if arr[i][j] != 2:
                dp[i][j] = dp[i][j-1] + dp[i+1][j]

answer = 1
for i in range(1, len(items)):
    if items[i-1][1] > items[i][1]:
        answer = 0
        break
    go(items[i - 1][0], items[i - 1][1], items[i][0], items[i][1])
print(dp[0][m-1])
