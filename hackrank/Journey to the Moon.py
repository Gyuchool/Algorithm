from collections import defaultdict
from collections import deque
import itertools
def bfs(x, graph, visited):
    q=deque()
    q.append(x)
    visited[x] = 1
    answer = 1
    while q:
        cx = q.popleft()
        for nx in graph[cx]:
            if not visited[nx]:
                visited[nx] = 1
                answer+=1
                q.append(nx)
    return answer
    
def journeyToMoon(n, astronaut):
    # Write your code here
    visited = [0]*n
    graph = defaultdict(list)
    result=0
    answer= []
    for x, y in astronaut:
        graph[x].append(y)
        graph[y].append(x)
    for i in range(n):
        if not visited[i]:
            cnt = bfs(i, graph, visited)
            answer.append(cnt)
    total_pairs = 0
    cumulative_sum = 0

    for count in answer:
        total_pairs += cumulative_sum * count
        cumulative_sum += count

    return total_pairs

    # comb = itertools.combinations(answer, 2)
    # for c in comb:
    #     x, y = c
    #     result += x*y
    # return result
