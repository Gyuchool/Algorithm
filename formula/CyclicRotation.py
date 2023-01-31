# Rotate array right shift by K times
def solution(A, K):
    if not A:
        return A
    cnt = K%len(A)
    return A[len(A)-cnt:] + A[:len(A)-cnt]
