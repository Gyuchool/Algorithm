def solution(cards):
    answer = 0
    visited = [0]*len(cards)
    tmp = []
    
    for i in range(len(cards)):
        cnt = 0
        x = cards[i]-1
        while not visited[x]:
            visited[x]+=1
            cnt+=1
            x=cards[x]-1
        tmp.append(cnt)
    tmp.sort(reverse=True)
    if len(tmp)>1:
        answer = tmp[0]*tmp[1]
    else:
        answer = 0
        
    return answer
