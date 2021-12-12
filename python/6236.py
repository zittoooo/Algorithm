import sys
input = sys.stdin.readline

n, m = map(int, input().split())
budgets = [int(input()) for _ in range(n)]
start = min(budgets)
end = sum(budgets)

while start <= end:
    mid = (start + end) // 2  # 인출할 금액
    now = mid  # 현재 가진 돈
    draw = 1   # 인출 횟수
    
    for budget in budgets:
        if now < budget:  # 가진 돈이 부족하면 돈 인출
            draw += 1
            now = mid
        now -= budget
    if draw > m or mid < max(budgets):  # 인출 횟수가 m번 보다 많거나 인출 금액이 적음
        start = mid + 1
    else:    # 인출 횟수가 m번보다 적거나 같음
        end = mid - 1
        k = mid
print(k)
