n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input())))


def allCheck(x, y, n):
    cnt1 = 0
    cnt0 = 0
    for i in range(x, x + n):
        for j in range(y, y + n):
            if arr[i][j] == 1:
                cnt1 += 1
            else:
                cnt0 += 1
    return [cnt0, cnt1]


tmp = ''


def recursive(x, y, n):
    global tmp
    result = allCheck(x, y, n)
    if not (result[0] > 0 and result[1] > 0):
        if result[0] > 0:
            return '0'
        else:
            return '1'

    tmp += '('
    recursive1 = recursive(x, y, n // 2)
    if recursive1 is None:
        tmp += ''
    else:
        tmp += recursive1
    recursive2 = recursive(x, y + n // 2, n // 2)
    if recursive2 is None:
        tmp += ''
    else:
        tmp += recursive2
    recursive3 = recursive(x + n // 2, y, n // 2)
    if recursive3 is None:
        tmp += ''
    else:
        tmp += recursive3
    recursive4 = recursive(x + n // 2, y + n // 2, n // 2)
    if recursive4 is None:
        tmp += ''
    else:
        tmp += recursive4
    tmp += ')'


s = recursive(0, 0, n)
if s is None:
    tmp+=''
else:
    tmp += s
print(tmp)
