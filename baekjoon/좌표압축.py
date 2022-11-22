n = int(input())
arr = list(map(int, input().split()))

tmp = {}
dic = dict()

for i in range(n):
    dic[i + 1] = arr[i]
li = dict(sorted(dic.items(), key=lambda x: x[1]))
id = 0


def check():
    if li[k] in tmp:
        return True
    return False


for k in li.keys():
    if check():
        continue
    else:
        tmp[li[k]] = id
    id += 1

for i in range(n):
    print(tmp[arr[i]], end=' ')

