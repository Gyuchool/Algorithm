n, m = map(int, input().split())

arr = []
rains = []

for _ in range(n):
    arr.append(list(map(int, input().split())))
rains.append([n - 2, 0])
rains.append([n - 2, 1])
rains.append([n-1, 0])
rains.append([n-1, 1])

visited = [[0] * n for _ in range(n)]

def move(rains, d, s):
    s %= n
    if d == 1:  # left
        for i in range(len(rains)):
            cx, cy = rains[i]
            ny = cy - s
            if ny < 0:
                ny += n
            rains[i] = cx, ny
    elif d == 2:  # left up
        for i in range(len(rains)):
            cx, cy = rains[i]
            ny = cy - s
            if ny < 0:
                ny += n
            nx = cx - s
            if nx < 0:
                nx += n
            rains[i] = nx, ny
    elif d == 3:  # up
        for i in range(len(rains)):
            cx, cy = rains[i]
            nx = cx - s
            if nx < 0:
                nx += n
            rains[i] = nx, cy
    elif d == 4:  # right up
        for i in range(len(rains)):
            cx, cy = rains[i]
            nx = cx - s
            if nx < 0:
                nx += n
            ny = cy + s
            if ny>=n:
                ny-=n
            rains[i] = nx, ny
    elif d == 5:  # right
        for i in range(len(rains)):
            cx, cy = rains[i]
            ny = cy + s
            if ny >= n:
                ny -= n
            rains[i] = cx, ny
    elif d == 6:  # right down
        for i in range(len(rains)):
            cx, cy = rains[i]
            nx = cx + s
            if nx >= n:
                nx -= n
            ny = cy + s
            if ny >= n:
                ny -= n
            rains[i] = nx, ny
    elif d == 7:  # down
        for i in range(len(rains)):
            cx, cy = rains[i]
            nx = cx + s
            if nx >= n:
                nx -= n
            rains[i] = nx, cy
    elif d == 8:
        for i in range(len(rains)):  # left down
            cx, cy = rains[i]
            nx = cx + s
            if nx >= n:
                nx -= n
            ny = cy - s
            if ny < 0:
                ny += n
            rains[i] = nx, ny
def step2():
    for x, y in rains:
        arr[x][y] += 1


dx = [-1, 1, -1, 1]
dy = [-1, -1, 1, 1]


def step3(x, y):
    count = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue
        if arr[nx][ny] > 0:
            count += 1
    return count

for i in range(m):
    d, s = map(int, input().split())
    move(rains, d, s)
    step2()
    for x, y in rains:
        arr[x][y] += step3(x, y)
    while rains:
        x, y = rains.pop()
        visited[x][y] = 1
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and arr[i][j] >= 2:
                rains.append([i, j])
                arr[i][j] -= 2
            visited[i][j] = 0

answer = 0
for i in range(n):
    for j in range(n):
        answer += arr[i][j]
print(answer)
