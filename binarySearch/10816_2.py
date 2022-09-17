n = int(input())
arr = sorted(list(map(int, input().split())))

m = int(input())
nums = list(map(int, input().split()))

def upper_idx(num, n):
    st, ed = 0, n
    while st < ed:
        mid = (st + ed) // 2
        
        if arr[mid] > num:
            ed = mid
        else:
            st = mid + 1
    return st
    
def lower_idx(num, n):
    st, ed = 0, n
    while st < ed:
        mid = (st + ed) // 2
        
        if arr[mid] >= num:
            ed = mid
        else:
            st = mid + 1
    return st

for num in nums:
    print(upper_idx(num, n) - lower_idx(num, n))

####################
import bisect

n = int(input())
arr = sorted(list(map(int, input().split())))
m = int(input())
nums = list(map(int, input().split()))

for num in nums:
    # print(bisect.bisect_right(arr, num), bisect.bisect_left(arr, num))
    print(bisect.bisect_right(arr, num) - bisect.bisect_left(arr, num), end = ' ')
