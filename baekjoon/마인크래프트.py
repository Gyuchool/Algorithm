# 최소 시간
n, m, b = map(int, input().split())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
answer = 999999999
value = 0

for height in range(257):
    over = 0
    under = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] > height:  # 깍기
                over += arr[i][j] - height
            else:  # 채우기(need inventory)
                under += height - arr[i][j]
    if under <= over + b:
        if answer >= (2 * over) + under:
            answer = (2 * over) + under
            value = height
print(answer, value)
