from collections import deque

def solution(plans):
    answer = []
    q=deque()
    studies = []
    for name, start, playtime in plans:
        tmp = start.split(':')
        h = int(tmp[0])
        m = int(tmp[1])
        time = 60*h+m
        play = int(playtime)
        studies.append([name, time, play])
    studies.sort(key = lambda x: (x[1], x[2]))
    for i in range(len(studies)-1):
        cname, cstart, cplay = studies[i]
        nname, nstart, nplay = studies[i+1]
        total_time = cstart+cplay
        done=True
        if total_time <=nstart: # 할거 있고 이미 끝냈다면
            answer.append(cname)
            while q:
                qname, qplay = q.pop()
                if total_time+qplay<=nstart: # 끝냈다면
                    answer.append(qname)
                    total_time+=qplay
                else:# 못끝내면 다시 q에 넣기# 못끝내면 다시 q에 넣기
                    q.append([qname, total_time+qplay-nstart])
                    break
        else:
            left = total_time-nstart
            q.append([cname, left])
    answer.append(studies[-1][0])
    while q:
        name, time = q.pop()
        answer.append(name)
            
    return answer
