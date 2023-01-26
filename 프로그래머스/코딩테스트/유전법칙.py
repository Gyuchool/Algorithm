def solution(queries):
    answer = []
    for query in queries:
        n = query[0]
        p = query[1]
        
        while n > 2:
            if n == 3 and (p-1)%4 == 0 and p <= 4**(n-1)-4**(n-2):
                answer.append('RR')
                break
            if n == 3 and (p-1)%4 == 3 and p > 4**(n-2):
                answer.append('rr')
                break
            p = (p-1)//4 + 1
            n-=1
        if n == 2:
            if p == 1:
                answer.append('RR')
            elif p == 4:
                answer.append('rr')
            else:
                answer.append('Rr')
        elif n == 1:
            answer.append('Rr')
                
    return answer
