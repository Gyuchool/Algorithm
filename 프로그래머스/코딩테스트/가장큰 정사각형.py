def solution(board):
    rows = len(board)
    cols = len(board[0])
    dp = [[0] * (cols + 1) for _ in range(rows + 1)] # DP 배열 초기화
    max_length = 0
    
    for i in range(1, rows+1):
        for j in range(1, cols+1):
            if board[i-1][j-1] == 1:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    
                if dp[i][j] > max_length :
                    max_length = dp[i][j]
    return max_length ** 2 # 가장 큰 정사각형의 넓이 반환
