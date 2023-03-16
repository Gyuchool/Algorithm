import itertools


def tosrring(res):
    tmp =''
    for s in res:
        tmp+=str(s)
    return tmp


def check(rs, cs):
    for ch in rs:
        if not ch in cs:
            return False
    return True


def solution(relation):
    answer = 0
    size = len(relation)  # 6
    rows = len(relation[0])  # 4
    datas = []
    for i in range(rows):
        tmp = []
        for j in range(size):
            tmp.append(relation[j][i])
        datas.append(tmp)
    result = []
    n = len(datas)
    indexs = []
    for i in range(n):
        indexs.append(i)
    for i in range(1, n + 1):
        c = list(itertools.combinations(indexs, i))
        for comb in c:
            by = False

            for res in result:
                rs = tosrring(res)
                cs = tosrring(comb)
                if check(rs, cs):
                    by = True
                    break
                if by:
                    break
            if by:
                continue

            if len(comb) == 1:
                for j in comb:  # 한개일때 각 비교
                    if len(datas[j]) == len(set(datas[j])):
                        result.append([j])
                        answer += 1
            else:
                newList = []
                for j in range(len(datas[0])):
                    tmp = ''
                    for idx in comb:
                        tmp = tmp + ';' +datas[idx][j]
                    newList.append(tmp)

                if len(newList) == len(set(newList)):
                    result.append(comb)
                    answer += 1
    return answer
