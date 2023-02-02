def solution(num, total):
    answer = []
    
    # x + (x + 1) + (x + 2) + ...
    # 0 + 1 + 2 + ... = sum(range(num))
    
    first = (total - sum(range(num))) // num
    answer = [first + i for i in range(num)]
        
    return answer
