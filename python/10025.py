n, k = map(int, input().split())
board = [0] * (1000002)

end = 0
for _ in range(n):
    g, x = map(int, input().split())
    board[x] = g       # board[x] 자리 얼음 g 그램
    end = max(end, x)  # 마지막 얼음이 들어있는 자리

window = 2*k + 1  # 움직일 수 있는 크기
ice = sum(board[:window])
ans = ice

for i in range(window, 1000001):  # 슬라이딩 윈도우 
    ice += board[i]
    ice -= board[i-window]
    ans = max(ans, ice)
print(ans)
