op = dict()
list = ['+', '-', '*']
chosen = []
visited = [0] * 3
answers=[]
answer= -1

def recurs(cnt, expression):
    global answer
    if cnt == 0:
        op[0] = chosen[0]
        op[1] = chosen[1]
        op[2] = chosen[2]
        for id in range(3):
            startIndex = 0
            while True:
                if startIndex >= len(expression):
                    break
                findIndex = expression.find(op[id], startIndex)
                if findIndex == -1:
                    break
                if findIndex>0 and expression[findIndex - 1] == '(':
                    startIndex = findIndex + 1
                    continue
                scIndex = -1
                fcIndex = -1
                for i in range(findIndex - 1, -1, -1):
                    if expression[i] in list:
                        if i-1 >=0 and expression[i-1] == '(':
                            continue
                        scIndex = i
                        break
                for i in range(findIndex + 1, len(expression)):
                    if expression[i] in list:
                        if expression[i] in list:
                            if i - 1 >= 0 and expression[i - 1] == '(':
                                continue
                        fcIndex = i
                        break
                if fcIndex == -1 and scIndex == -1:
                    sum = eval(expression)
                    answer = max(abs(int(sum)), answer)
                    return
                elif fcIndex == -1:
                    sum = eval(expression[scIndex + 1:])
                    if sum < 0:
                        sum = '('+str(sum)+')'
                    else:
                        sum = str(sum)
                    expression = expression[:scIndex + 1] + sum
                elif scIndex == -1:
                    sum = eval(expression[:fcIndex])
                    if sum < 0:
                        sum = '('+str(sum)+')'
                    else:
                        sum = str(sum)
                    expression = str(sum) + expression[fcIndex:]
                else:
                    sum = eval(expression[scIndex + 1:fcIndex])
                    if sum < 0:
                        sum = '('+str(sum)+')'
                    else:
                        sum = str(sum)
                    expression = expression[:scIndex + 1] + str(sum) + expression[fcIndex:]
                startIndex = 0
        return

    for i in range(3):
        if not visited[i]:
            chosen.append(list[i])
            visited[i] = 1
            recurs(cnt - 1, expression)
            visited[i] = 0
            chosen.pop()


def solution(expression):
    recurs(3, expression)
    return answer


