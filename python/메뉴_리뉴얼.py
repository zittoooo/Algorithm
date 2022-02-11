from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    for length in course:
        candidates = []
        
        for order in orders:
            for li in combinations(order, length):
                res = "".join(sorted(li))
                candidates.append(res)
        sorted_candidates = Counter(candidates).most_common()
        
        for menu, cnt in sorted_candidates:
            if cnt > 1 and cnt == sorted_candidates[0][1]:
                answer.append(menu)
        answer.sort()
    return answer
