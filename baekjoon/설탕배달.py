n = int(input())
answer = -1
if n % 5 == 0:
    answer = n // 5
else:
    x = n // 5
    while x >= 0:
        t = n - 5 * x
        if t % 3 == 0:
            answer = x + t // 3
            break
        x-=1
print(answer)
