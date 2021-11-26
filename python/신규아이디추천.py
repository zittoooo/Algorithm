def solution(new_id):
    answer = ''
    tmp = new_id.lower()
    
    for i in tmp:
        if i.isdigit() or i.isalpha() or i in '-_.' :
            answer += i

    while '..' in answer:
        answer = answer.replace('..', '.')
        
    answer = answer[1:] if answer[0] == '.' and len(answer) > 1 else answer
    answer = answer[:-1] if answer[-1] == '.' else answer

    if len(answer) == 0:
        answer = answer + 'a'

    answer = answer[:15] if len(answer) >= 16 else answer
    answer = answer[:-1] if answer[-1] == '.' else answer
    
    while len(answer) < 3:
        answer += answer[-1]
    return answer