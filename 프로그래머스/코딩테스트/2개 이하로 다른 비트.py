def solution(numbers):
    answer = []
    for num in numbers:
        s = bin(num)
        if s[-1] == '1' and s[-2] == '1':
            s = '0' + s[2:]
            for i in range(len(s) - 1, -1, -1):
                if s[i] == '0':
                    k = list(s)
                    k[i] = '1'
                    k[i + 1] = '0'
                    s = ''.join(k)
                    break
            int1 = int(s, 2)
            answer.append(int1)
        else:
            answer.append(num + 1)

    return answer
