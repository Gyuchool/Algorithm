n, m = map(int, input().split())
arr = list((map(int, input().split())))

# 자르는 크기
start = 0
end = max(arr)
result = 0
while start <= end:
    mid = start + (end - start) // 2
    sum = 0
    for element in arr:
        if element - mid > 0:
            sum += element - mid

    if sum >= m:
        start = mid + 1
    else:
        end = mid - 1

print(end)
