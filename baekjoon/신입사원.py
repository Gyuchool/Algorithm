# (1,4) (2,3) (3,2) (4,1) (5,5) - 4
# (1,4) (2,5) (3,6) (4,2) (5,7) (6,1) (7,3) - 3
import sys

if __name__ == '__main__':
    t = int(sys.stdin.readline())

    for i in range(t):
        list = []
        n = int(sys.stdin.readline())
        for j in range(n):
            a, b = map(int, sys.stdin.readline().split())
            list.append([a, b])
        list.sort()
        answer = 1
        m = list[0][1]

        for j in range(1, len(list)):
            if m > list[j][1]:
                answer += 1
            m = min(m, list[j][1])
        print(answer)
