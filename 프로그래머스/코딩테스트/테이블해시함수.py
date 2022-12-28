def solution(data, col, row_begin, row_end):
    answer = 0
    hash = []
    data = sorted(data, key=lambda x: (x[col-1], -x[0]))
    for i in range(row_begin, row_end+1):
        sum = 0
        for ar in data[i-1]:
            sum+= ar%i
        hash.append(sum)
    answer = hash[0]
    for i in range(1, len(hash)):
        answer = answer ^ hash[i]
    return answer
