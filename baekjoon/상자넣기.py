if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    dp = [1] * n

    for i in range(1, n):
        if arr[i - 1] > arr[i]:
            m = 0
            for j in range(i - 1, -1, -1):
                if arr[i] > arr[j]:
                    m = max(dp[j], m)
            dp[i] = m + 1
        else:
            m = 0
            for j in range(i - 1, -1, -1):
                if arr[j] < arr[i]:
                    m = max(dp[j], m)
            dp[i] = m + 1
    print(max(dp), end='')
