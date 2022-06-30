def across(stones, k, mid):
    skip = 0 # 못 건너는 개수
    for stone in stones:
        if stone - mid < 0:
            skip += 1
        else:
            skip = 0

        if skip >= k:
            return False
    return True

def solution(stones, k):
    answer = 0
    mn = 1
    mx = max(stones)
    
    while mn <= mx:
        mid = (mn + mx) // 2
        if across(stones, k, mid):
            mn = mid + 1
            answer = max(answer, mid)
        else:
            mx = mid - 1 
    return answer
