class Solution:
    def solution(self, m, n, startX, startY, balls):
        answer = []
        self.N, self.M, self.sy, self.sx = n, m, startY, startX

        for ball in balls:
            curr = self.Ball(ball[1], ball[0])
            answer.append(curr.get_min_distance())

        return answer

    class Ball:
        def __init__(self, y, x):
            self.y = y
            self.x = x

        def get_min_distance(self):
            res = float('inf')
            balls = []

            # 위 방향 이동
            if not (self.x == self.sx and self.y < self.sy):
                balls.append(self.Ball(self.y * -1, self.x))

            # 아래 방향 이동
            if not (self.x == self.sx and self.y > self.sy):
                balls.append(self.Ball(2 * self.N - self.y, self.x))

            # 왼쪽 방향 이동
            if not (self.y == self.sy and self.x < self.sx):
                balls.append(self.Ball(self.y, self.x * -1))

            # 오른쪽 방향 이동
            if not (self.y == self.sy and self.x > self.sx):
                balls.append(self.Ball(self.y, 2 * self.M - self.x))

            for ball in balls:
                diffY = abs(self.sy - ball.y)
                diffX = abs(self.sx - ball.x)
                d = diffY ** 2 + diffX ** 2
                res = min(res, d)

            return res
