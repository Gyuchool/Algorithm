n = input()
idx = 1


def isOut():
    return i - 1 < 0 or i >= len(n) - 1


while n != '0':
    fail = False
    if not (n[0] == '1' and n[-1] == '2'):
        fail = True
    else:
        for i in range(len(n)):
            if n[i] == '5':
                if isOut():
                    fail= True
                    break
                if not (n[i-1] == '1' or n[i-1] =='3'):
                    fail = True
                    break
                if not (n[i+1] =='8'):
                    fail = True
                    break
            if n[i] == '6':
                if isOut():
                    if not (n[i+1] == '2' or n[i+1] == '3'):
                        fail = True
                        break
                    if not (n[i-1] == '8'):
                        fail = True
                        break
            if n[i] == '8':
                if isOut():
                    fail = True
                    break
                if not (n[i - 1] == '5' or n[i - 1] == '7'):
                    fail = True
                    break
                if not (n[i + 1] == '6' or n[i + 1] == '7'):
                    fail = True
                    break
            if n[i] == '1':
                if i != 0:
                    fail = True
                    break
                if not (n[i + 1] == '4' or n[i + 1] == '5'):
                    fail = True
                    break
            elif n[i] == '2':
                if i != len(n) - 1:
                    fail = True
                    break
                if not (n[i - 1] == '6' or n[i - 1] == '4'):
                    fail = True
                    break
            elif n[i] == '3':
                if isOut():
                    fail = True
                    break
                if not (n[i - 1] == '4' or n[i - 1] == '6'):
                    fail = True
                    break
                if not (n[i+1] == '4' or n[i+1] == '5'):
                    fail = True
                    break
            elif n[i] == '4':
                if isOut():
                    fail = True
                    break
                if not (n[i - 1] == '1' or n[i - 1] == '3'):
                    fail = True
                    break
                if not (n[i + 1] == '2' or n[i + 1] == '3'):
                    fail = True
                    break
            elif n[i] == '7':
                if isOut():
                    fail = True
                    break
                if not (n[i-1] == '8' and n[i+1] == '8'):
                    fail= True
                    break

    if fail:
        print(str(idx) + '. NOT')
    else:
        print(str(idx) + '. VALID')
    idx += 1
    n = input()
