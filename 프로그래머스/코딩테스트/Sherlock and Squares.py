def squares(a, b):
    tmp = a**(1/2)
    answer = 0 
    if tmp == int(tmp):
        answer+=1
    ra = int(tmp)
    rb = int(b**(1/2))
    return rb - ra + answer
    
