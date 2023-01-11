row = [0] * 11
answers= []

def dfs(x, ability, sum):
    if x == len(ability[0]):
        answers.append(sum)
        return

    for i in range(len(ability)):
        if not row[i]:
            row[i] = 1
            dfs(x + 1, ability, sum + ability[i][x])
            row[i] = 0

def solution(ability):
    dfs(0, ability, 0)
    return max(answers)
