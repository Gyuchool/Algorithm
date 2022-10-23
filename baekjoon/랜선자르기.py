if __name__ == '__main__':
    list = []
    x, y = map(int, input().split())
    for i in range(x):
        list.append(int(input()))
    list = sorted(list)

    first = 1
    last = list[-1]
    answer = 0
    while first <= last:
        mid = first + (last - first) // 2
        sum = 0
        for ar in list:
            sum += (ar // mid)
        if sum < y:
            last = mid - 1
        else:
            first = mid + 1
            answer = max(answer, mid)

    print(answer)
