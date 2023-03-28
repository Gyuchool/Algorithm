from collections import defaultdict

n,m,x,y,k = map(int, input().split())
dic = dict()
dic[1] = 0
dic[2] = 0
dic[3] = 0
dic[4] = 0
dic[5] = 0
dic[6] = 0

dir = 4
top = 1
maps = []
for _ in range(n):
    maps.append(list(map(int, input().split())))
orders = list(map(int, input().split()))


def isOut(nx, ny):
    if nx<0 or ny<0 or nx>=n or ny>=m:
        return True
    return False


def apply():
    if maps[x][y] == 0:
        maps[x][y] = dic[6]
    else:
        dic[6] = maps[x][y]
        maps[x][y] = 0
    print(dic[1])


for order in orders:
    if order == 1: #east
        if isOut(x, y+1):
            continue
        dic[1], dic[2], dic[3], dic[4], dic[5], dic[6] = dic[4], dic[2], dic[1], dic[6], dic[5], dic[3]
        x = x
        y = y + 1
        apply()
    elif order == 2:# west
        if isOut(x, y-1):
            continue
        dic[1], dic[2], dic[3], dic[4], dic[5], dic[6] = dic[3], dic[2], dic[6], dic[1], dic[5], dic[4]
        x = x
        y = y - 1
        apply()


    elif order == 3: #north
        if isOut(x-1, y):
            continue
        dic[1], dic[2], dic[3], dic[4], dic[5], dic[6] = dic[5], dic[1], dic[3], dic[4], dic[6], dic[2]
        x= x-1
        y= y
        apply()
    else:
        if isOut(x+1, y): #south
            continue
        dic[1], dic[2], dic[3], dic[4], dic[5], dic[6] = dic[2], dic[6], dic[3], dic[4], dic[1], dic[5]
        x= x+1
        y= y
        apply()
