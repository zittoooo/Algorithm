import sys
import math
n = int(input())
computers = []
total = 0
end = 0
for i in range(n):
    computers.append(list(map(int, sys.stdin.readline().split())))
    mx = max(computers[i])
    total += sum(computers[i])
    end = max(end, mx)
start = 0

end = math.ceil(end / 2)
ans = 0

while start <= end:
    mid = (start + end) // 2
    run = 0
    for computer in computers:
        run += sum(min(com, mid) for com in computer)
        
    if run >= math.ceil(total / 2):
        ans = mid
        end  = mid -1
    else:
        start = mid + 1

print(ans)
              
