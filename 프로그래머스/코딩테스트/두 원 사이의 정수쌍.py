import math

def solution(r1, r2):
    answer = 0
    for cy in range(1, r2+1):
        e1 = (r2**2-cy**2)**(0.5)
        s = math.floor(e1)
        value=0
        if cy < r1:
            e2=(r1**2-cy**2)**(0.5)
            s2 = math.floor(e2)
            if e2 == s2:
                value+=1
        else:
            s2 = 0
        value += (s-s2)
        answer += 4*value # 4개 사분면 전체 증가
    answer+=(r2-r1+1)*4 # 수직선 위 좌표
    return answer
