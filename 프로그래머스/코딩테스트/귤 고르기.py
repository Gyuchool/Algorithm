from collections import defaultdict


def solution(k, tangerine):
    dic = defaultdict(int)
    for g in tangerine:
        dic[g] += 1
    di = sorted(dic.items(), key=lambda x: -x[1])
    cnt = 0
    for x, v in di:
        if k> 0:
            cnt += 1
            k -= v
        else:
            return cnt
    return cnt
