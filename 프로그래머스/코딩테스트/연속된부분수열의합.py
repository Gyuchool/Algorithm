def solution(sequence, k):
    answer = []
    i=0
    j=0
    sum = sequence[i]
    while i<=j and (i<len(sequence) or j<len(sequence)):
        if sum < k:
            j+=1
            if j>=len(sequence):
                break
            sum+=sequence[j]
        elif sum > k:
            sum-=sequence[i]
            i+=1
        else:
            answer.append([i, j, j-i])
            sum-=sequence[i]
            i+=1
    answer.sort(key=lambda x: (x[2], x[0], x[1]))
    return [answer[0][0], answer[0][1]]
