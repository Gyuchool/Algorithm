n = int(input())
arr = list(map(int, input().split()))
answer = [0] * n
id = 1
for i in range(n):
    st = arr[i]
    for j in range(n):
        if answer[j] == 0:
            st-=1
        if st == -1 and answer[j]== 0:
            answer[j] = id
            break
    id+=1
for c in answer:
    print(c, end=' ')


