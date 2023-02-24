n = int(input())
dp = [[0] * 10 for _ in range(n + 1)]
if n == 1:
    print(10)
elif n == 2:
    print(55)
else:
    for i in range(10):
        dp[1][i] = 1
    for i in range(10):
        dp[2][i] = 10 - i
    for i in range(3, n + 1):
        for j in range(10):
            sum = 0
            for k in range(j, 10):
                sum = (sum + dp[i - 1][k]) % 10007
            dp[i][j] = sum
    answer = 0
    for i in range(10):
        answer = (answer + dp[n][i]) % 10007
    print(answer)
