n,k =map(int, input().split())
arr = list(map(int, input().split()))
answer=9999999
cnt=0
lions=[]
for i in range(len(arr)):
    if arr[i] == 1:
        lions.append(i)
for i in range(len(lions)-k+1):
    answer = min(answer, lions[i+k-1] - lions[i]+1)
if answer == 9999999:
    print(-1)
else:
    print(answer)
