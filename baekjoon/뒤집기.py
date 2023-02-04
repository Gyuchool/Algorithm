s= input()
dict = {'0':0, '1':0}
for i in range(1, len(s)):
    if s[i-1] != s[i]:
        dict[s[i-1]]+=1

dict[s[-1]]+=1
list = sorted(dict.items(), key=lambda x: x[1])
print(list[0][1])
