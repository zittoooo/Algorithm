from itertools import permutations
import math
s = set()

def isPrime(num):
    if num == 0 or num == 1:
        return 0
    for i in range(2, int(float(math.sqrt(num) + 1))):
        if num % i == 0:
            return 0
    return 1

def solution(numbers):
    answer = 0
    num_list = list(numbers)
    
    for i in range(1, len(num_list)+1):
        for num in permutations(num_list, i):
            s.add(int("".join(list(num))))

    for num in s:        
        answer += isPrime(num)
    
    return answer
