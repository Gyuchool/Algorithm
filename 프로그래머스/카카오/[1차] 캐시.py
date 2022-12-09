import operator


def solution(cacheSize, cities):
    answer = 0
    mp = dict()
    if cacheSize == 0:
        return len(cities)*5
    for id in range(0, len(cities)):
        city = "".join(cities[id]).lower()
        if city in mp:  # 캐시에 저장되어있을때
            mp[city] = id
            answer += 1
        else:
            if len(mp) < cacheSize:
                mp[city] = id
            else:
                s = min(mp.items(), key=operator.itemgetter(1))
                del mp[s[0]]
                mp[city] = id
            answer += 5
    return answer
