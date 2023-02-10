n = int(input())
arr = list(map(int, input().split()))
arr.sort()
s = 0
e = len(arr) - 1
if len(arr)%2 == 1:
    print(arr[(s+ e)//2])
else:
    id = (s+e)//2
    sum1 = 0
    sum2 = 0
    st1 = arr[id]
    st2 = arr[id + 1]
    for a in arr:
        sum1 += abs(st1-a)
        sum2 += abs(st2-a)
    if sum1 <= sum2:
        print(arr[id])
    else:
        print(arr[id+1])




