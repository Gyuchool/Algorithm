answer = list()

def solution(n):
    hanoi(n, 1, 2, 3)
    return answer


def hanoi(n, fr, tmp, to):
    if n == 1:
        return answer.append([fr, to])

    hanoi(n - 1, fr, to, tmp)
    answer.append([fr, to])
    hanoi(n - 1, tmp, fr, to)
