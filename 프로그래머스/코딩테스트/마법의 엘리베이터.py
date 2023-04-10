def solution(storey):
    answer = 0
    storey = str(storey)
    co = 0
    for i in range(len(storey)-1, 0, -1):
        value = int(storey[i])
        nextV = int(storey[i-1])
        if nextV>=5:
            if value +co < 5:
                answer+=(int(storey[i]) + co)
                co=0    
            else:
                answer+=(10-(int(storey[i])+co))
                co = 1
        else:
            if value +co <= 5:
                answer+=(int(storey[i]) + co)
                co=0    
            else:
                answer+=(10-(int(storey[i])+co))
                co = 1
    if co + int(storey[0]) > 5:
        answer+=(10-(int(storey[0])+co))
        co = 1
    else:
        answer+=co + int(storey[0])
        co = 0
    if co:
        answer+=1
    return answer
