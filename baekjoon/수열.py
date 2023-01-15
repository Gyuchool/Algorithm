n, k = map(int, input().split())
arr = list(map(int, input().split()))

sum=0
for i in range(k):
    sum+=arr[i]

s = 0
e = k
answers=[]
answers.append(sum)
while e<n:
    sum = sum - arr[s] + arr[e]
    answers.append(sum)
    s+=1
    e+=1
print(max(answers))
