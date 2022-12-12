n, m = map(int, input().split())

arr = list((map(int, input().split())))

# 자르는 크기
start = max(arr)
end = sum(arr)
result = 0
while start <= end:
    mid = start + (end - start) // 2  # 블루레이 크기
    count = 1
    sum = 0
    for i in range(len(arr)):
        if sum + arr[i] > mid:
            sum = 0
            count += 1
        sum += arr[i]
    if sum > mid:
        count += 1

    if count > m:
        start = mid + 1
    else:
        result = mid
        end = mid - 1

print(result)
