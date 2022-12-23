n = int(input())
arr = list(map(int, input().split()))
dp = [0] * 1001
list = []
list.append(arr[0])
dp[0] = 1
for i in range(1, len(arr)):
    if list[-1] < arr[i]:
        list.append(arr[i])
    else:
        for j in range(i):
            if list[j] >= arr[i]:
                list[j] = arr[i]
                break

print(len(list))
