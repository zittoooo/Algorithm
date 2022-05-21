import sys
import math

t = int(input())
while t:
    t -= 1
    n = int(input())
    msa = sorted(list(map(int, input().split())))
    
    start = 0
    end = n -1
    services = 0
    
    while start <= end and msa[end] > 600:
        services += 1
        end -= 1
    while msa[start] == 300 and msa[end] == 600:
        services += 1
        start += 1
        end -= 1
    
    num300 = 0
    while start <= end and msa[start] == 300:
        num300 += 1
        start += 1
    while start < end:
        if msa[start] + msa[end] <= 900:
            services += 1
            start += 1
            end -= 1
        elif num300 > 0:
            services += 1
            num300 -= 1
            end -= 1
        else:
            services += 1
            end -= 1
    if start == end:
        services += 1
        if num300 > 0:
            num300 -= 1
    services += math.ceil(num300 / 3)
    print(services)
