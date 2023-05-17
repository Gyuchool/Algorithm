def waiter(number, q):
    # Write your code here
    answer = []
    startPrime = 2
    while q:
        q-=1
        tmpA = []
        tmpB = []
        while number:
            if number[-1]%startPrime == 0:
                tmpB.append(number.pop())
            else:
                tmpA.append(number.pop())
        number = tmpA
        while tmpB:
            answer.append(tmpB.pop())
        
        startPrime = getPrime(startPrime)
    while number:
        answer.append(number.pop())
        
    return answer
