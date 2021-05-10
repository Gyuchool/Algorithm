a,b,c=map(int, input().split())
cnt=0

li =[a,b,c]
while True:
    li.sort()
    if li[2]-li[1] > li[1]-li[0]:
        li[0]=li[2]-1
    else:
        li[2]=li[0]+1
    if li[0]==li[1] or li[1]==li[2] or li[0]==li[2]:
        break
    cnt+=1
print(cnt)


