s = input()
p = input()
answer = 0
start = 0
end = 1
while end <= len(p):
    if p[start:end] in s:
        end+=1
    else:
        answer+=1
        start=end-1
        end=start+1
print(answer+1)
