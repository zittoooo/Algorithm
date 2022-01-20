import math
info = []
d = dict()
def solution(fees, records):
    answer = []
    
    for record in records:
        time, num, state = record.split(" ")
        if num in d:
            d[num].append([time, state])
        else:
            d[num] = [[time, state]]
    sd = dict(sorted(d.items()))
    
    for key, value in sd.items():
        if len(value) % 2 == 1:              # 입차만 있고 출차가 없을 때
            value.append(['23:59', 'OUT'])
        minute = 0     # 총 주차 시간 저장 변수
        ans = 0        # 총 요구 저장 변수
        
        for i in range(0, len(value), 2):
            in_h, in_m = map(int, value[i][0].split(':'))
            out_h, out_m = map(int, value[i+1][0].split(':'))
            
            if in_m > out_m:
                out_h -= 1
                minute += (out_m + 60 - in_m)
            else:
                minute += (out_m - in_m)
            minute += ((out_h - in_h) * 60)

        if minute <= fees[0]:   # 기본 시간 이하
            ans += fees[1]
        else:
            ans += fees[1] + math.ceil((minute-fees[0]) / fees[2]) * fees[3]
        
        answer.append(ans)
    return answer
