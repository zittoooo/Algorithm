import sys
n = int(input())
meetting = []
for _ in range(n):
    s, e = map(int, sys.stdin.readline().split())
    meetting.append([s, 1])
    meetting.append([e, -1])
meetting.sort()

room = 0
meetting_cnt = 0

for _, state in meetting:
    if state == 1:
        meetting_cnt += 1
    elif state == -1:
        meetting_cnt -= 1
    room = max(room, meetting_cnt)
    
print(room)