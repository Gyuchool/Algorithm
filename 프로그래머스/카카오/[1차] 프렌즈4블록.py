import copy

dx = [0, 0, 1, 1]
dy = [0, 1, 0, 1]


def solution(m, n, board):
    answer = 0
    real = []
    for i in range(n):
        tmp = []
        for j in range(m-1, -1, -1):
            tmp.append(board[j][i])
        real.append(''.join(tmp))
    board = copy.deepcopy(real)

    x, y = n, m
    while True:
        visited = [[0] * y for _ in range(x)]
        finish = True

        for cx in range(n - 1):
            for cy in range(m - 1):
                candidate = False
                for i in range(4):
                    candidate = True
                    nx = cx + dx[i]
                    ny = cy + dy[i]
                    if board[nx][ny] == 'X' or board[cx][cy] != board[nx][ny]:
                        candidate = False
                        break
                if candidate:
                    finish = False
                    for i in range(4):
                        nx = cx + dx[i]
                        ny = cy + dy[i]
                        visited[nx][ny] = 1
        # mark
        new_board = []
        for cx in range(n):
            tmp = []
            cnt=0
            for cy in range(m):
                if visited[cx][cy] != 1:
                    tmp.append(board[cx][cy])
                else:
                    answer+=1
                    cnt+=1
            for i in range(cnt):
                tmp.append('X')
            new_board.append(''.join(tmp))
        if finish:
            break
        else:
            board = copy.deepcopy(new_board)

    return answer
