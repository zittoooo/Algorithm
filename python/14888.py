import sys
from itertools import permutations

n = int(sys.stdin.readline().rstrip())
num = list(map(int, sys.stdin.readline().split()))  # 숫자
op = list(map(int, sys.stdin.readline().split()))  # +, -, x, % 연산자 


oplist = ['+', '-', 'x', '%']
lst = []
for i in range(4):
    if op[i] >=1 :  # i 번째 연산자를 사용하면
        for j in range(op[i]):
            lst.append(oplist[i])  # 해당 연산자 개수만큼 lst 리스트에 추가

mx = int(-1e9)
mn = int(1e9)
for comb in list(permutations(lst, len(lst))):
    res = num[0]
    for i in range(len(comb)):
        if comb[i] == '+':
            res += num[i+1]
        elif comb[i] == '-':
            res -= num[i+1]
        elif comb[i] == 'x':
            res *= num[i+1]
        else:
            if res < 0:
                res = abs(res) // num[i+1]
                res *= -1
            else:
                res = res // num[i+1]
    mx = max(mx, res)
    mn = min(mn, res)

print(mx, mn, end="\n")
