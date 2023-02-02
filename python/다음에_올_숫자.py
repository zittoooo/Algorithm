# 1
def solution(common):
    answer = 0
    
    # 등차 수열
    if common[1] - common[0] == common[2] - common[1]:
        answer = common[-1] + common[1] - common[0]
    else:
        # 등비 수열
        answer = common[-1] * (common[1] // common[0])
    
    return answer


# 2
def solution(common):
    answer = 0
    
    a, b, c = common[:3]
    # 등차 수열
    if b - a == c - b:
        answer = common[-1] + (b - a)
    else:
        answer = common[-1] * (b // a)
    return answer
