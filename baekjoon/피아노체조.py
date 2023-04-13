import sys
input = sys.stdin.readline
n = int(input())
arr= list(map(int, input().split()))
dp = [0] * 100001
for i in range(1, len(arr)):
    if arr[i-1] > arr[i]:
        dp[i] = dp[i-1]+1
    else:
        dp[i] = dp[i-1]
m = int(input())
for _ in range(m):
    l,r = map(int, input().split())
    print(dp[r-1]-dp[l-1])


