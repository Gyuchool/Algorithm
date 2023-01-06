x, y, w, s = map(int, input().split())

answer = 0
if x != 0 and y != 0:
    answer = min(2 * min(x, y) * w, min(x, y) * s)
    minimum = min(x, y)
    x -= minimum
    y -= minimum
# 2배인 경우
if max(x, y) % 2 == 0:
    v = max(x, y) // 2
    answer += v * min(2 * w, 2 * s)
else:
    v = max(x, y) // 2
    answer += v * min(2 * w, 2 * s)
    answer += w
print(answer)
