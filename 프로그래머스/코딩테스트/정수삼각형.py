def solution(triangle):
    dp = [[0] * 501 for _ in range(501)]
    for i in range(len(triangle)):
        for j in range(len(triangle[i])):
            dp[i][j] = triangle[i][j]

    for i in range(len(triangle)-1, 0, -1):
        for j in range(1, len(triangle[i])):
            dp[i-1][j-1] += max(dp[i][j - 1], dp[i][j])
    return dp[0][0]
