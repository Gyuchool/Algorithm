from collections import deque

def solution(order):
    answer = 0
    stack = deque()
    ok = 1
    for o in order:
        if o == ok:
            ok += 1
        else:
            if stack:
                if stack[-1] == o:
                    stack.pop()
                elif o == ok:
                    ok += 1
                else:
                    if ok > o:
                        break
                    for j in range(ok, o):
                        stack.append(j)
                    ok = o + 1
                    
            else:
                for j in range(ok, o):
                    stack.append(j)
                ok = o + 1
        answer += 1
    return answer
