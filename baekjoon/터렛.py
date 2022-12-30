n = int(input())
for i in range(n):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    distance = ((x2-x1)**2 + (y2-y1)**2)**(1/2)
    if x1==x2 and y1==y2:
        if r1==r2:
            print(-1)
        elif r1 != r2:
            print(0)
    else:
        if r1 + r2 == distance:
            print(1)
        elif distance > r1 + r2:
            print(0)
        else:
            if abs(r1-r2) == distance:
                print(1)
            elif abs(r1-r2) > distance:
                print(0)
            else:
                print(2)
