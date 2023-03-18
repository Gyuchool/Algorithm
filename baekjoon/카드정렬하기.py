from queue import PriorityQueue

n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))
arr.sort()
answer = 0
tmp = 0
q = PriorityQueue()

for a in arr:
    q.put(a)
while True:
    a = q.get()
    if q.empty():
        break
    tmp = a + q.get()
    answer+=tmp
    q.put(tmp)
print(answer)
