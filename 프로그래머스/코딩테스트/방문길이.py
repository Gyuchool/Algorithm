visited = [[0] * 11 for i in range(11)]
check = []


def solution(dirs):
    dic = {'U': [-1, 0], 'D': [1, 0], 'R': [0, 1], 'L': [0, -1]}

    answer = 0
    x = 5
    y = 5
    for ch in dirs:
        ch_ = dic[ch]
        nx = x + ch_[0]
        ny = y + ch_[1]

        if nx < 0 or ny < 0 or nx > 10 or ny > 10:
            continue
        if (x, y, nx, ny) in check:
            x = nx
            y = ny
            continue

        check.append((x, y, nx, ny))
        check.append((nx, ny, x, y))

        answer += 1
        x = nx
        y = ny
    return answer
