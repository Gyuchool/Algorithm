import copy
from collections import deque
from collections import defaultdict

n = int(input())

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def printAll(visited):
    for i in range(n):
        for j in range(n):
            print(visited[i][j], end=' ')
        print()
    print('*******************')


def grouping(x, y, id, visited, group):
    q = deque()
    q.append([x, y])
    area = 1
    standard = arr[x][y]
    arr[x][y] = id
    visited[x][y] = 1

    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            if not visited[nx][ny] and arr[nx][ny] == standard:
                area += 1
                arr[nx][ny] = id
                visited[nx][ny] = 1
                q.append([nx, ny])
    group[id] = [[x, y], standard, area]


def meeting(x, y, id, visited, touch_manager):
    touch = defaultdict(int)  # 상대 = [접촉 횟수]
    q = deque()
    q.append([x, y])
    visited[x][y] = 1
    area = 0

    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            if arr[nx][ny] != arr[cx][cy]:
                touch[arr[nx][ny]] += 1
                continue
            if not visited[nx][ny] and arr[nx][ny] == arr[cx][cy]:
                area += 1
                visited[nx][ny] = 1
                q.append([nx, ny])

    for other_id, touching in touch.items():
        touch_manager[id].append([other_id, touching])


def aClock(id, cpy):
    horizen = deque()
    vertical = deque()
    for i in range(n):
        horizen.append(cpy[id][i])
        vertical.append(cpy[i][id])
    idx = 0
    while horizen:
        cpy[idx][id] = horizen.pop()  # 가로 <- 세로
        idx += 1
    idx = 0
    while vertical:
        cpy[id][idx] = vertical.popleft()
        idx += 1
    return cpy


def rotate_90(arr, x, y, size):
    tmp = []
    for i in range(x, x + size):
        ttmp = []
        for j in range(y, y + size):
            ttmp.append(arr[i][j])
        tmp.append(ttmp)

    tmp = list(zip(*tmp[::-1]))

    for i in range(x, x + size):
        for j in range(y, y + size):
            arr[i][j] = tmp[i-x][j-y]


def tri(arr):
    group = defaultdict(list)  # id.[[s, e], 실제 값, 면적]
    touch_manager = defaultdict(list)  # 내 지역.[상대지역, 접촉 횟수]
    visited = [[0] * n for _ in range(n)]

    cpy = copy.deepcopy(arr)
    id = 1
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                grouping(i, j, id, visited, group)
                id += 1

    #### 2. 그룹 접촉면 확인
    for i in range(n):
        for j in range(n):
            visited[i][j] = 0
    for idx, values in group.items():
        [x, y], original, area = values
        meeting(x, y, idx, visited, touch_manager)

    result = defaultdict(int)
    combinations = 0
    for idx, l in touch_manager.items():
        [x, y], value, area = group[idx]
        for other_id, touching in l:
            [ox, oy], ovalue, oarea = group[other_id]
            if (idx, other_id) in result.keys() or (other_id, idx) in result.keys():
                continue
            else:
                result[(idx, other_id)] = (area + oarea) * value * ovalue * touching
    for k, v in result.items():
        combinations += v

    center = n // 2

    cpy = aClock(center, cpy)

    rotate_90(cpy, 0, 0, center)
    rotate_90(cpy, 0, center + 1, center)
    rotate_90(cpy, center + 1, 0, center)
    rotate_90(cpy, center + 1, center + 1, center)

    return combinations, cpy


################MAIN###############################
answer = 0
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
for x in range(4):
    ans, arr = tri(arr)
    answer += ans
print(answer)
