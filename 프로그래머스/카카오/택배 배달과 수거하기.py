def solution(cap, n, deliveries, pickups):
    Dlast = 0
    Tlast = 0
    answer = 0

    for i in range(n - 1, -1, -1):
        if deliveries[i] != 0 and Dlast == 0:
            Dlast = i
        if pickups[i] != 0 and Tlast == 0:
            Tlast = i
    if Dlast == 0 and Tlast == 0:
        return 0
    last = max(Dlast, Tlast)
    while last >= 0:
        # 배달
        sum = 0
        answer += 2 * (last + 1)
        for i in range(Dlast, -1, -1):
            if cap >= sum + deliveries[i]:
                sum += deliveries[i]
                deliveries[i] = 0
                Dlast = -1
            else:
                deliveries[i] -= (cap - sum)
                Dlast = i
                break
        # 수거
        sum = 0
        for i in range(Tlast, -1, -1):
            if cap >= sum + pickups[i]:
                sum += pickups[i]
                pickups[i] = 0
                Tlast = -1
            else:
                pickups[i] -= (cap - sum)
                Tlast = i
                break
        last = max(Dlast, Tlast)

    return answer
