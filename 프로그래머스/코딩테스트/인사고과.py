def solution(scores):
    answer = 0
    dic = dict()
    for i in range(len(scores)):
        dic[i] = scores[i]
    sorted_dic = dict(sorted(dic.items(), key = lambda x: (-x[1][0], x[1][1])))
    mx = -1
    my = -1

    rank_list = []
    for idx, li in sorted_dic.items():
        cx, cy = li
        mx = max(mx, cx)
        my = max(my, cy)
        if cx < mx and cy < my:
            if idx == 0:
                return -1
            continue
        else:
            rank_list.append([idx, li])
    rank_list.sort(key = lambda x: -(x[1][0] + x[1][1]))
    for i in range(len(rank_list)):
        if rank_list[i][0] == 0:
            return i+1
    return -1
