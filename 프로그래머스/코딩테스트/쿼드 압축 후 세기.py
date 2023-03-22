from collections import defaultdict


# 0,0 // 0,2 // 2, 0// 2,2
def dfs(arr, x, y, size, dic):
    merge = True
    standard = arr[x][y]
    for i in range(x, x + size):
        for j in range(y, y + size):
            if arr[i][j] != standard:
                merge = False
                break
        if not merge:
            break
    if merge:
        dic[arr[x][y]] += 1
        return
    dfs(arr, x, y, size // 2, dic)
    dfs(arr, x + size // 2, y, size // 2, dic)
    dfs(arr, x, y + size // 2, size // 2, dic)
    dfs(arr, x + size // 2, y + size // 2, size // 2, dic)


def solution(arr):
    answer = []
    dic = defaultdict(int)
    dfs(arr, 0, 0, len(arr), dic)
    answer.append(dic[0])
    answer.append(dic[1])
    return answer
