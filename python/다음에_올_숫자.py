def solution(common):
    answer = 0
    
    # 등차 수열
    if common[1] - common[0] == common[2] - common[1]:
        answer = common[-1] + common[1] - common[0]
    else:
        # 등비 수열
        answer = common[-1] * (common[1] // common[0])
    
    return answer
