
def solution(sequence):
    a = []
    b = []
    n = len(sequence)
    dpa = [0]*(n)
    dpb = [0]*(n)
    for i in range(n):
        if i % 2 == 0:
            a.append(-sequence[i])
            b.append(sequence[i])
        else:
            a.append(sequence[i])
            b.append(-sequence[i])
    dpa[0] = a[0]
    dpb[0] = b[0]
    for i in range(1, n):
        dpa[i] = max(a[i], dpa[i-1] +a[i])
        dpb[i] = max(b[i], dpb[i-1] + b[i])
    answer = max(max(dpa), max(dpb))
    return answer
