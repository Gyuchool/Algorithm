from collections import deque

n, k = map(int, input().split())
arr = list(map(int, input().split()))
start = 0
count = 0  # 내구도가 0인 벨트 개수
onRobot = -1


def rotation(arr):
    new_arr = []
    new_arr.append(arr[len(arr) - 1])
    for i in range(len(arr) - 1):
        new_arr.append(arr[i])
    if robot_index:
        if robot_index[0] == n - 1:
            robot_index.popleft()
        for i in range(len(robot_index)):
            robot_index[i] += 1
        if robot_index[0] == n - 1:
            robot_index.popleft()
    return new_arr


robot_index = deque()
answer = 1
while True:
    arr = rotation(arr) # 1 phase
    if robot_index: # 2
        for i in range(len(robot_index)):
            if arr[robot_index[i] + 1] > 0 and not robot_index[i] + 1 in robot_index:  # 앞으로 로봇 한칸 이동
                robot_index[i] += 1
                arr[robot_index[i]] -= 1
                if arr[robot_index[i]] == 0:
                    count += 1
        if robot_index[0] == n-1:
            robot_index.popleft()


    if arr[start] > 0: # 3
        robot_index.append(start)
        arr[start] -= 1
        if arr[start] == 0:
            count += 1
    if count >= k: # 4
        break
    answer += 1
print(answer)
