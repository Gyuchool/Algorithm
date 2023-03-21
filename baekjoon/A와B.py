s = input()
t = input()

# 문자열의 뒤에 A를 추가한다.
# 문자열을 뒤집고 뒤에 B를 추가한다.
# 완탐으로하면 
answer = 0
while len(t) >= len(s):
    if t[-1] == 'A':
        t=t[:-1]
    else:
        t=t[:-1]
        t=t[::-1]
    if s==t:
        answer=1
        break
print(answer)

