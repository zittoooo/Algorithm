from itertools import combinations
from bisect import bisect_left
d = dict()

def solution(info, query):
    answer = []
    
    for apply in info:
        apply_list = apply.split(" ")
        score = int(apply_list[-1])
        apply_list = apply_list[:-1]
        for i in range(len(apply_list)+1):
            for combi in list(combinations(apply_list, i)):
                key = "".join(combi)
                if key in d:
                    d[key].append(score)
                else:
                    d[key] = [score]
    for key in d:
        d[key].sort()
    print(d)
    
    for q in query:
        q_list = q.split(" ")
        score = int(q_list[-1])
        q_list = q_list[:-1]
        while "-" in q_list:
            q_list.remove('-')
        while "and" in q_list:
            q_list.remove('and')
        key = "".join(q_list)
        if key in d:
            value = d[key]
            # print(value)
            i = bisect_left(value, score)
            answer.append(len(value) - i)
        else:
            answer.append(0)
    
    return answer
