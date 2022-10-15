import bisect

def solution(A, B):
    answer = 0
    A = sorted(A)
    b = sorted(B)
    for a in A:
        right = bisect.bisect_right(b, a)
        if right == len(b):
            continue
        else:
            b.remove(b[right])
            answer += 1
            continue
    return answer
