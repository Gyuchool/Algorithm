def solution(n, left, right):
    answer = []
 
    for v in range(left, right + 1):
        cx = v//n
        cy = v%n
        answer.append(max(cx, cy) + 1)
    
    return answer
