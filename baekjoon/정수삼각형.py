n = int(input())
arr = []
dp = [[0] * 501 for _ in range(501)]

for i in range(n):
    arr.append(list(map(int, (input().split()))))
dp[0][0] = arr[0][0]
for i in range(1, n):
    for j in range(i + 1):
        if j-1 < 0:
            dp[i][j] = dp[i-1][j] + arr[i][j]
        elif i == j:
            dp[i][j] = dp[i-1][j-1] + arr[i][j]
        else:
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j]
answer = dp[n-1][0]

for i in range(n):
    answer = max(answer, dp[n-1][i])

print(answer)

