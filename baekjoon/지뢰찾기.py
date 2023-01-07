from collections import deque

n = int(input())
arr = []
result = []
answer = [['0'] * n for _ in range(n)]

for i in range(n):
    arr.append(list(input()))
for i in range(n):
    result.append(list(input()))
list = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == '*':
            list.append([i, j])

dir = [[-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1]]
for x, y in list:
    for i in range(8):
        nx = x + dir[i][0]
        ny = y + dir[i][1]
        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue
        answer[nx][ny] = str(int(answer[nx][ny]) + 1)

open = False
for i in range(n):
    for j in range(n):
        if result[i][j] == '.':
            answer[i][j] = '.'
        if result[i][j] == 'x' and arr[i][j] == '*':
            open = True

if open:
    for x, y in list:
        answer[x][y] = '*'
for i in range(n):
    for j in range(n):
        print(answer[i][j], end='')
    print()
