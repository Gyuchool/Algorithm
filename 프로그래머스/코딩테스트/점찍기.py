def solution(k, d):
    answer = 0
    for a in range(0, d+1, k):
        b = (d**2 - (a)**2)**(1/2)
        if b <= d:
            answer+=b//k + 1
    return answer
