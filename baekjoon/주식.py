T = int(input())
for _ in range(T):
    answer=0
    n = int(input())
    arr = list(map(int, input().split()))
    info = []
    maximum = arr[-1]
    max_i = len(arr)-1
    for i in range(len(arr)-1, -1, -1):
        if arr[i] > maximum:
            for j in range(i+1, max_i):
                answer+=(maximum-arr[j])
            maximum= arr[i]
            max_i = i
    for i in range(max_i):
        answer+=(maximum-arr[i])
    print(answer)
