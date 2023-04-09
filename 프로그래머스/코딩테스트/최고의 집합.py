def solution(n, s):
    answer = []
    tmp = s//n
    other = tmp
    if s%n>0:
        other = tmp+1
    if s<n:
        return [-1]
    
    
    y = s-(n*tmp)
    x = n-y
    answer+=[tmp]*x
    answer+=[other]*y
    answer.sort()
    return answer
