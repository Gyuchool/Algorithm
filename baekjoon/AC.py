t = int(input())
for _ in range(t):
    p = input()
    n = int(input())
    s = input()[1:-1]
    if not s:
        arr = []
    else:
        arr = s.split(',')
    start = 0
    end = len(arr)
    reverse = False
    for ch in p:
        if ch == 'R':
            if reverse:
                reverse = False
            else:
                reverse = True
        elif ch == 'D':
            if reverse:
                end -= 1
            else:
                start += 1
    if start > end:
        print('error')
    else:
        if start == end:
            print([])
        else:
            if reverse:
                print('[', end='')
                for i in range(end - 1, start, -1):
                    print(arr[i], end=',')
                print(arr[start], end=']')
                print()
            else:
                print('[', end='')
                for i in range(start, end - 1):
                    print(arr[i], end=',')
                print(arr[end - 1], end=']')
                print()
