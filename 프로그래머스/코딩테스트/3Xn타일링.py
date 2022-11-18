def solution(n):
    answer = 0
    dp = [1]*5001
    dp[0] = 1
    dp[2] = 3
    
    if n%2 == 1:
        return answer
    if n == 2:
        return 3
    else:
        for i in range(4, n+1, 2):
            sum=0
            for j in range(i-4, -1, -2):
                sum+=((2*dp[j]))%1000000007
            dp[i] = ((dp[i-2]*dp[2])%1000000007 + (sum)%1000000007)%1000000007
    return dp[n]
