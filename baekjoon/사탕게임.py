n= int(input())
arr = []
for _ in range(n):
    arr.append(list(input()))


def calculate(arr):
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            print(arr[i][j], end= ' ')
        print()
    print('****************************')


def calculateY(arr, x, y):
    # [x][]
    answer=0
    tmp = 1
    for i in range(len(arr[x])-1):
        if arr[x][i] != arr[x][i+1]:
           tmp=1
        else:
            tmp+=1
            answer = max(answer, tmp)
    # [][y]
    tmp=1
    for i in range(len(arr) - 1):
        if arr[i][y] != arr[i+1][y]:
            tmp = 1
        else:
            tmp += 1
            answer = max(answer, tmp)

    # [][y+1]
    tmp = 1
    for i in range(len(arr) - 1):
        if arr[i][y+1] != arr[i + 1][y+1]:
            tmp = 1
        else:
            tmp += 1
            answer = max(answer, tmp)
    return answer

def calculateX(arr, x, y):
    # [][y]
    answer = 0
    tmp=1
    for i in range(len(arr) - 1):
        if arr[i][y] != arr[i+1][y]:
            tmp = 1
        else:
            tmp += 1
            answer = max(answer, tmp)

    # [x][]
    tmp = 1
    for i in range(len(arr[x]) - 1):
        if arr[x][i] != arr[x][i + 1]:
            tmp = 1
        else:
            tmp += 1
            answer = max(answer, tmp)

    # [x+1][]
    tmp = 1
    for i in range(len(arr[x+1]) - 1):
        if arr[x+1][i] != arr[x+1][i + 1]:
            tmp = 1
        else:
            tmp += 1
            answer = max(answer, tmp)
    return answer

answer=-1
for i in range(n-1):
    for j in range(n):
        arr[i][j], arr[i+1][j] = arr[i+1][j], arr[i][j]
        answer = max(answer, calculateX(arr, i, j))
        arr[i][j], arr[i + 1][j] = arr[i + 1][j], arr[i][j]

for i in range(n):
    for j in range(n-1):
        arr[i][j], arr[i][j+1] = arr[i][j+1], arr[i][j]
        answer = max(answer, calculateY(arr,i , j))
        arr[i][j], arr[i][j + 1] = arr[i][j + 1], arr[i][j]

print(answer)
