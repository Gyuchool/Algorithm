def solution(distance, scope, times):
    answer = distance

    for i in range(len(scope)):
        s = min(scope[i])
        e = max(scope[i])
        ts = times[i][0]
        te = times[i][1]
        time = ts + te
        for j in range(s, e + 1):
            if ts < j % time or j%time == 0:
                continue
            else:
                answer = min(answer, j)
    return answer
