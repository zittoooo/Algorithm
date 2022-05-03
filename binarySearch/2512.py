n = int(input())
jibang = list(map(int, input().split()))
m = int(input())
res = 0

start = 0
end = max(jibang)

while start <= end:
    mid = (start + end) // 2
    total = 0
    
    for buget in jibang:
        if buget <= mid:
            total += buget
        else:
            total += mid
    if total <= m:
        res = mid
        start = mid + 1
    else:
        end = mid - 1
        
print(res)
