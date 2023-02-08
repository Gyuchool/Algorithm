import math

def solution(arrayA, arrayB):
    answer = 0
    gcdA= arrayA[0]
    for a in arrayA:
        gcdA = math.gcd(gcdA, a)
    
    out=False
    for b in arrayB:
        if b%gcdA == 0:
            out = True
            break
    
    gcdB = arrayB[0]
    for b in arrayB:
        gcdB = math.gcd(gcdB, b)
        
    out2 = False
    for a in arrayA:
        if a % gcdB == 0:
            out2 = True
            break
    if out and out2:
        return 0
    elif out and not out2:
        return gcdB
    elif out2 and not out:
        return gcdA
    else:
        return max(gcdA, gcdB)
