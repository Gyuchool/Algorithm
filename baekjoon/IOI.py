from collections import deque

n = int(input())
m = int(input())
s = input()

pattern = [0] * 1000001

answer = 0
i = 0
cnt = 0
while i < m:
    if s[i] == 'I':
        if i + 2 < m and s[i + 1] == 'O' and s[i + 2] == 'I':
            cnt += 1
            i += 2
            if cnt == n:
                answer+=1
                cnt-=1
        else:
            cnt = 0
            i += 1
    else:
        cnt = 0
        i += 1
print(answer)
