def snail(tmp, n, number, cx, cy):
    if n < 1 or tmp[cx][cy]:
        return
    for x in range(cx, cx + n): # vertical
        tmp[x][cy] = number
        number+=1
    for y in range(cy+1, cy + n): #horizon
        tmp[cx+n-1][y] = number
        number+=1
    lastX=cx+n-1
    lastY=cy+n-1
    for dia in range(1, n-1): #diagonal
        tmp[lastX-dia][lastY-dia] = number
        number+=1
    snail(tmp, n-3, number, cx+2, cy+1)    

def solution(n):
    answer = [] # ㄴ shape
    tmp = [[0]*(1001) for _ in range(1001)]
    snail(tmp, n, 1, 0, 0)
    for i in range(n):
        for j in range(n):
            if tmp[i][j]:
                answer.append(tmp[i][j])
    return answer
    
