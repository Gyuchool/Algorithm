n = int(input())
arr = list(map(int, input().split()))
op = list(map(int, input().split()))

maximum=-1000000011
minimum=1000000011


def dfs(arr, plus, minus, multi, divide, sum, index):
    global maximum
    global minimum
    if plus == 0 and minus == 0 and multi == 0 and divide == 0:
        maximum = max(maximum, sum)
        minimum = min(minimum, sum)
        return

    if plus:
        dfs(arr, plus - 1, minus, multi, divide, sum + arr[index], index + 1)
    if minus:
        dfs(arr, plus, minus - 1, multi, divide, sum - arr[index], index + 1)
    if multi:
        dfs(arr, plus, minus, multi - 1, divide, sum * arr[index], index + 1)
    if divide:
        if sum < 0:
            dfs(arr, plus, minus, multi, divide - 1, -(-sum//arr[index]), index + 1)
        else:
            dfs(arr, plus, minus, multi, divide - 1, sum // arr[index], index + 1)
dfs(arr, op[0], op[1], op[2], op[3], arr[0], 1)
print(maximum)
print(minimum)
