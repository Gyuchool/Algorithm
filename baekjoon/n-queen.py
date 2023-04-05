n = int(input())
answer = 0

dx = [0] * n

def isOut(x):
    for i in range(x):
        if dx[x] == dx[i] or abs(dx[x] - dx[i]) == abs(x - i):
            return True
    return False


def backtracking(x):
    global answer
    if x == n:
        answer += 1
        return

    for i in range(n):
        dx[x] = i
        if not isOut(x):
            backtracking(x + 1)


for i in range(n):
    dx[0] = i
    backtracking(1)

print(answer)
