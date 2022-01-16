stack = []

def solution(board, moves):
    answer = 0
    l = len(board)
    for move in moves:
        for i in range(l):   # i = 0 ~ 4
            if board[i][move-1] :    
                doll = board[i][move-1]
                board[i][move-1] = 0

                if not stack or stack[-1] != doll:
                    stack.append(doll)
                elif stack and stack[-1] == doll:
                    answer += 2
                    stack.pop()
                break
                
    return answer
