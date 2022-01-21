answer_set = set()
mx = 0

def dfs(depth, n ,arrow, info):
    global mx
    if depth == 11 and len(arrow) == 11:
        if (sum(arrow) < n):      # 라이언이 n 발을 다 못 쏜 경우
            arrow[-1] += n - sum(arrow)
        r_score, a_score = 0, 0   # 라이언, 어피치 점수
        for i in range(11):
            if int(info[i]) >= arrow[i] and int(info[i]) != 0:  # 어피치가 점수 얻을 때
                a_score += 10 - i
            elif int(info[i]) < arrow[i]:                       # 라이언이 점수 얻을 때
                r_score += 10 - i
        

        if r_score > a_score:    # 라이언이 이길때
            if r_score - a_score >= mx:
                answer_set.add((r_score - a_score, tuple(arrow)))  # 점수차, 라이언 결과 튜플
                mx = max(mx, r_score - a_score)
        return
    
    if info[depth] + 1 <= n - sum(arrow):   # 어피치보다 1발 더 쏠 수 있을 때
        arrow.append(int(info[depth] + 1))
        dfs(depth+1, n, arrow, info)
        arrow.pop()
    
    arrow.append(0)
    dfs(depth+1, n, arrow, info)
    arrow.pop()
    

def solution(n, info):
    answer = []
    arrow = []
    
    dfs(0, n, arrow, info)
    s = list(sorted(answer_set, key = lambda x : (-x[0], -x[1][-1], -x[1][-2], -x[1][-3], -x[1][-4], -x[1][-5], -x[1][-6], -x[1][-7], -x[1][-8], -x[1][-9], -x[1][-10], -x[1][0])))
    # print(s)
    
    if len(answer_set) == 0:
        answer.append(-1)
    else:
        answer = s[0][1]
        
    return answer
