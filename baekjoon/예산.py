import sys

if __name__ == '__main__':
    t = int(sys.stdin.readline())
    arr = list(map(int, input().split()))
    m = int(sys.stdin.readline())

    arr.sort()

    start = 1
    end = arr[t - 1]
    mid = 0
    answer = 0
    while start <= end:
        mid = (start + end) // 2
        answer = mid
        sum = 0
        for i in range(t):
            if mid > arr[i]:
                sum += arr[i]
            else:
                sum += mid
        if sum > m:
            end = mid - 1
            answer = end
        else:
            start = mid + 1
    print(answer)
