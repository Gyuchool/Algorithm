
def solution(board):
    answer = -1
    oCount = 0
    xCount = 0
    oWin = 0
    xWin = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] =='O':
                oCount+=1
            elif board[i][j] == 'X':
                xCount+=1
    if oCount == xCount == 0:
        return 1
    if oCount > xCount + 1:
        return 0
    if oCount < xCount:
        return 0
    # oWin check 가로체크
    for i in range(3):
        win=True
        for j in range(3):
            if board[i][j] != 'O':
                win = False
                break
        if win:
            oWin += 1
            
    for j in range(3):
        win=True
        for i in range(3):
            if board[i][j] != 'O':
                win = False
                break
        if win:
            oWin += 1
            
    # xWin check 가로체크
    for i in range(3):
        win=True
        for j in range(3):
            if board[i][j] != 'X':
                win = False
                break
        if win:
            xWin += 1
            
    for j in range(3):
        win=True
        for i in range(3):
            if board[i][j] != 'X':
                win = False
                break
        if win:
            xWin += 1
            
    if board[0][0] == board[1][1] == board[2][2]:
        if board[1][1] == 'O':
            oWin+=1
        elif board[1][1] == 'X':
            xWin+=1
    elif board[0][2] == board[1][1] == board[2][0]:
        if board[1][1] == 'O':
            oWin+=1
        elif board[1][1] == 'X':
            xWin+=1
        
    if oWin == 0 and xWin == 0:
        # if oCount == xCount or oCount == xCount+1:
        return 1
    elif oWin>0 and xWin == 0:
        if oCount > xCount:
            return 1
    elif xWin >= 1 and oWin == 0:
        if oCount == xCount:
            return 1
    return 0
