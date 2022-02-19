nsn, m = map(int, input().split())
course = list(map(int, input().split()))
start = sum(course) // m
end = sum(course)
ans = end

while start <= end:
    mid = (start + end) // 2
    if mid < max(course):
        start = mid + 1
        continue
    play_time = 0
    cnt = 0
    for i in course:
        if play_time + i > mid:
            cnt += 1
            play_time = 0
        play_time += i
        
    cnt += 1 if play_time else 0
    
    if cnt <= m:
        end = mid - 1
        ans = min(ans, mid)
    else:
        start = mid + 1
    # print(cnt, start, end, mid)

print(ans)
