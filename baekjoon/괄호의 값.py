from collections import deque

s = input()

stack = deque()
tmp = ''
answer = -1
if len(s) == 1:
    answer = 0

if s[0] == ')' or s[0] == ']':
    answer = 0
else:
    if s[0] == '(':
        tmp += '2*('
    else:
        tmp += '3*('
    stack.append(s[0])
    for i in range(1, len(s)):
        if s[i] == '(':
            if s[i - 1] == ']' or s[i - 1] == ')':
                tmp += '+'
            tmp += '2*('
            stack.append(s[i])

        elif s[i] == '[':
            if s[i - 1] == ']' or s[i - 1] == ')':
                tmp += '+'
            tmp += '3*('
            stack.append(s[i])
        elif s[i] == ')':
            if not stack or '[' == stack[-1]:
                answer = 0
                break
            elif '(' == stack[-1]:
                stack.pop()
                if tmp[-1] == ')':
                    tmp += '*'
                tmp += '1)'
        elif s[i] == ']':
            if not stack or '(' == stack[-1]:
                answer = 0
                break
            elif '[' == stack[-1]:
                stack.pop()
                if tmp[-1] == ')':
                    tmp += '*'
                tmp += '1)'
if stack:
    answer = 0
if answer == 0:
    print(answer)
else:
    print(eval(tmp))
