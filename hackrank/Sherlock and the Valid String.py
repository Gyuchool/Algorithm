from collections import Counter

from collections import defaultdict
def isValid(s):
    # Write your code here
    dic = Counter(s)
    graph = defaultdict(int)
    for k, v in dic.items():
        graph[v]+=1
    li = sorted(graph.items(), key= lambda x: -x[1])
    standard = li[0][0]
    
    values = sorted(dic.values())
    oper = False
    for i in range(len(values)):
        if standard != values[i]:
            if not oper and abs(values[i] - standard) == 1:
                oper = True
            elif not oper and values[i] == 1:
                oper = True
            else:
                return "NO"
    return "YES"
