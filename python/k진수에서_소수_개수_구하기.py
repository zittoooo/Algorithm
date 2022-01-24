import math

def isPrime(num):            # 소수 판별
    if num == 1 or num == 0:
        return 0
    end = int(float(math.sqrt(num))) + 1
    for i in range(2, end):
        if num % i == 0:
            return 0
    return 1
    
def solution(n, k):
    answer = 0
    
    rev_base = ''
    while n > 0:
        n, mod = divmod(n, k)   # 몫, 나머지
        rev_base += str(mod)        
    n_k = rev_base[::-1]  # k 진수로 변환한 결과

    candidates = list(n_k.split("0"))
    while "" in candidates:
        candidates.remove("")
    
    for candidate in candidates:
        answer += isPrime(int(candidate))
        
    return answer
