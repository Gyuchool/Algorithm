n = int(input())
arr = list(map(int, input().split()))
s = 0
e = n-1
min = 2000000002
a=0
b=0
while s<e:
    if abs(arr[s] + arr[e]) <= min:
        min = abs(arr[s] + arr[e])
        a = arr[s]
        b = arr[e]
    if arr[s] + arr[e] > 0:
        e-=1
    else:
        s+=1
print(a, b)
