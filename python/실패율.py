import bisect
d = dict()

def solution(N, stages):
    answer = []
    stages.sort().  # 이진 탐색을 위한 정렬

    for i in range(1, N+1):
        fail_num = bisect.bisect_left(stages, i+1) - bisect.bisect_right(stages, i-1)  # 실패한 사람 수
        number = len(stages) - bisect.bisect_right(stages, i-1)   # 총 도전한 사람 수
        if fail_num == 0:
            d[i] = 0
        else:
            fail =  fail_num / number
            d[i] = fail
        
        
    dic = sorted(d.items(), key=lambda x : (-x[1]))  # 실패율 내림차순 정렬, 리스트 자료형으로 리턴된다
    for item in dic:
        answer.append(item[0])
    return answer
