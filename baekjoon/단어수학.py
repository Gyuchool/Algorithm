from collections import defaultdict

n = int(input())
dic = defaultdict(int)
for _ in range(n):
    s = input()
    for i in range(len(s)):
        dic[s[i]] += 10 ** (len(s) - 1 - i)

arr = sorted(dic.items(), key=lambda x: -x[1])
num = 9
answer = 0
for k, v in arr:
    answer += (num) * v
    num -= 1
print(answer)
