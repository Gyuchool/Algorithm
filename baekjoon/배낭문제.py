n,k=map(int, input().split())
dp = [[0]*100011 for _ in range(101)]
w_list = [0]*101
v_list = [0]*101
for i in range(n):
    w_list[i], v_list[i] = map(int, input().split())

def bag(size, w):
    if size == n:
        return 0
    if dp[size][w]:
        return dp[size][w]

    In = 0
    if w_list[size] + w <=k:
        In = v_list[size] + bag(size +1, w_list[size] + w)
    NotIn = bag(size + 1, w)
    dp[size][w] = max(In, NotIn)
    return dp[size][w]

print(bag(0, 0))
