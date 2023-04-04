
def solution(routes):
    answer = 0
    routes.sort()
    print(routes)
    s = routes[0][0]
    e = routes[0][1]
    
    for i in range(1, len(routes)):
        if routes[i][0] <= e:
            s= max(s, routes[i][0])
            e= min(e, routes[i][1])
        else:
            answer+=1
            s= routes[i][0]
            e= routes[i][1]
        
    return answer+1
