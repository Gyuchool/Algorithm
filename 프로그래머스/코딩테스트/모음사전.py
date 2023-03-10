dic = {0: 'A', 1: 'E', 2:'I', 3:'O', 4:'U'}
tmp = []


def duplicatePermutation(depth, x, res):
    if depth == x:
        tmp.append(res)
        return

    for i in range(5):
        duplicatePermutation(depth + 1, x, res + dic[i])


def solution(word):
    answer = 0

    for i in range(1, 6):
        duplicatePermutation(0, i, "")
    tmp.sort()
    for i in range(len(tmp)):
        if tmp[i] == word:
            answer = i + 1
    return answer
