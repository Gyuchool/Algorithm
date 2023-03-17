import itertools

n,m = map(int, input().split())
arr = []
chickens = []
homes = []

for i in range(n):
    arr.append(list(map(int, input().split())))
for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            chickens.append([i,j])
        elif arr[i][j] == 1:
            homes.append([i,j])

combinations = itertools.combinations(chickens, m)

def search(chicken, arr, homes):
    result = 0
    for hx, hy in homes:
        tmp = 100000000
        for cx, cy in chicken:
            tmp = min(tmp, abs(hx-cx) + abs(hy-cy))
        result+=tmp
    return result
answer = 100000000

for comb in combinations:
    answer = min(answer, search(comb, arr, homes))
print(answer)
