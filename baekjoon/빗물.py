h, w = map(int, input().split())
arr = list(map(int, input().split()))

result = 0
for hh in range(1, h+1):
    tmp = -1
    for i in range(w):
        if hh <= arr[i]:
            if tmp != -1:
                result += (i - tmp - 1)
            tmp = i
print(result)
