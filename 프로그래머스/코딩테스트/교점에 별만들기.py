from collections import deque


def solution(line):
    max_x = -1
    max_y = -1
    min_x = 100000
    min_y = 100000

    answer = []
    q = deque()
    for i in range(len(line)):
        a = line[i][0]
        b = line[i][1]
        e = line[i][2]
        for j in range(i + 1, len(line)):
            c = line[j][0]
            d = line[j][1]
            f = line[j][2]
            if a * d - b * c == 0:
                continue
            x = (b * f - e * d) / (a * d - b * c)
            y = (e * c - a * f) / (a * d - b * c)

            if x.is_integer() and y.is_integer():
                x, y = int(x), int(y)
                q.append([x, y])
    min_x, max_x, min_y, max_y = min(q)[0], max(q)[0], min(q, key=lambda x: x[1])[1], max(q, key=lambda x: x[1])[1]
    arr = [['.'] * (max_x - min_x + 1) for _ in range(max_y - min_y + 1)]
    while q:
        cx, cy = q.popleft()
        arr[abs(max_y - cy)][abs(cx - min_x)] = '*'
    for i in range(len(arr)):
        answer.append(''.join(arr[i]))

    return answer
