def solution(msg):
    answer = []
    dic = dict()
    for i in range(26):
        dic[chr(65 + i)] = i + 1

    value = 27
    s = 0
    e = 1
    while e <= len(msg):
        tmp = msg[s:e]
        if not tmp in dic:
            answer.append(dic[msg[s:e-1]])
            dic[tmp] = value
            value+=1
            s= e-1
            e=s
        e+=1
    answer.append(dic[msg[s:e-1]])

    return answer
