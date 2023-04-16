n, x = map(int, input().split())

dp = [1] * 51
dall = [1] * 51
dp[1] = 3
dall[1] = 5
dp[2] = 7
dall[2] = 13
for i in range(1, n):
    dall[i] = 1 + dall[i-1] + 1 + dall[i-1] + 1
    dp[i] = dp[i-1] + 1 + dp[i-1]

def recur(n, x):
    if n == 0:
        if x == 1:
            return 1
        return 0
    if x <= 1:
        return 0
    elif x <= dall[n - 1] + 1:  # 가운데 P전
        return recur(n - 1, x-1)
    elif x == 1 + dall[n - 1] + 1:  # 딱 가운데
        return 1 + dp[n - 1]
    elif 1 + dall[n - 1] + 1 < x <= dall[n - 1] * 2 + 2:
        return recur(n - 1, x - (dall[n - 1] + 2)) + dp[n - 1] + 1
    elif x >= 3 + dp[n - 1] * 2:
        return 2*dp[n-1]+1 

print(recur(n, x))
