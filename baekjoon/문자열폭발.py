s = input()
bomb = input()

size = len(bomb)
answer = list()
key = bomb[-1]
for ch in s:
    answer.append(ch)
    if ch == key:
        if ''.join(answer[-size:]) == bomb:
            for i in range(size):
                answer.pop()
if answer:
    print(''.join(answer))
else:
    print('FRULA')
