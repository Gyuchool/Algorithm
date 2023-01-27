answer = 10000000001
def dfs(b, sum, cnt):
    global answer
    if b == sum:
        answer = min(answer, cnt)
        return
    elif b < sum:
        return
    dfs(b, sum * 2, cnt + 1)
    dfs(b, sum * 10 + 1, cnt + 1)


a, b = map(int, input().split())
dfs(b, a, 0)
if answer == 10000000001:
    print(-1)
else:
    print(answer + 1)
