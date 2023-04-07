import copy
from collections import defaultdict

n, m, k = map(int, input().split())

# 1:[r,c], m,s,d ==> id, 좌표, 질량, 속도, 방향
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]
def move(fire_balls): # 1번행과 N번행 만... 1번 열은 N번 열만
    new_fire_balls = defaultdict(list)
    for idx, value in fire_balls.items():
        [cx, cy], m, s, d = value
        nx = (cx + s * dx[d]) % n  # 1번-N번 행 연결되어있기 때문
        ny = (cy + s * dy[d]) % n

        new_fire_balls[idx] = [[nx, ny], m, s, d]
    return new_fire_balls


fire_balls = defaultdict(list)
####1. input
idx = 1
for i in range(m):
    r, c, m, s, d = map(int, input().split())
    fire_balls[idx] = [[r, c], m, s, d]
    idx += 1
for count in range(k):
    
    new_fire_balls = move(fire_balls)
    
    #### 2개 이상 체크
    real_new_fire_balls = defaultdict(list)
    counter = defaultdict(list)
    for id, value in new_fire_balls.items():
        [cx, cy], m, s, d = value
        counter[(cx, cy)].append(id)  # 동일한 r, c인 id 저장
    for (cx, cy), ids in counter.items():
        destroy = False
        if len(ids) >= 2:  # 1:[r,c], m,s,d @ 2:[r,c], m1, s1,d1
            sum_m = 0
            sum_s = 0
            cd = new_fire_balls[ids[0]][3]
            even = []
            for id in ids:  # 같은 좌표인 ids 돌면 정보들 합
                [r, c], m, s, d = new_fire_balls[id]
                sum_m += m
                sum_s += s
                nd = d
                if cd % 2 == 1 and nd % 2 == 1:
                    even.append(False)
                elif cd%2 == 0 and nd %2 == 0:
                    even.append(True)
                else:
                    even.append(True)
                    even.append(False)
            new_m = sum_m // 5
            if new_m == 0:
                destroy = True
                continue
            else:
                new_s = sum_s // len(ids)
                if len(set(even)) == 1:  # 모두 홀 or 짝
                    for i in range(0, 7, 2):
                        real_new_fire_balls[idx] = [[cx, cy], new_m, new_s, i]
                        idx += 1
                else:
                    for i in range(1, 8, 2):
                        real_new_fire_balls[idx] = [[cx, cy], new_m, new_s, i]
                        idx += 1
            if destroy:
                continue
        else:  # 걍 저장
            real_new_fire_balls[ids[0]] = new_fire_balls[ids[0]]
    fire_balls = copy.deepcopy(real_new_fire_balls)
answer= 0
for xy, m, s, d in fire_balls.values():
    answer+=m
print(answer)
