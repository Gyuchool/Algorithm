n = int(input())
dp = [[0] * 11 for _ in range(101)]
# dp i,j => i개 수, 시작이 j일 때

if n == 1:
    print(9)
else:
    for i in range(10):
        dp[1][i] = 1
    for i in range(2, n + 1):
        dp[i][0] = dp[i - 1][1]
        for j in range(1, 10):
            if j == 9:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000
    answer= 0
    for i in range(1, 10):
        answer = (answer + dp[n][i])%1000000000
    print(answer)
