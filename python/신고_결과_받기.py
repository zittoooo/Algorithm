stop = dict() # 유저 - 신고자 
cnt = dict()  # 각 유저별 신고 당한 횟수
stop_list = set()

def solution(id_list, report, k):
    answer = []
    s = set(report)
    
    for repo in s:
        user, singo = repo.split(' ')
        if user in stop:
            stop[user].add(singo)
        else:
            stop[user] = set([singo])
        if singo in cnt:
            cnt[singo] += 1
        else:
            cnt[singo] = 1
            
        if cnt[singo] >= k:               # 정지된 리스트 만들기
                stop_list.add(singo)

    for user in id_list:
        if user in stop:
            answer.append(len(stop[user] & stop_list))
        else:
            answer.append(0)

    return answer
