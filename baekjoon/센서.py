n=int(input())
k=int(input())
arr = list(map(int, input().split()))
gook = sorted(set(arr))

new_arr = []
for i in range(1, len(gook)):
    new_arr.append(gook[i]-gook[i-1])
new_arr.sort(reverse=True)
print(sum(new_arr[k-1:]))
