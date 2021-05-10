t=int(input())
dp = [[0]*30 for i in range(30)]

def combi(n,k):
    global dp

    for i in range(n+1):
        for j in range(k+1):
            if i==j or j==0:
                dp[i][j]=1
            else:
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
    return dp[n][k]
def main():
    for i in range(t):
        k,n=map(int, input().split())
        print(combi(n,k))
main()
    
