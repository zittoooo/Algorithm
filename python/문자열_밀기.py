def solution(A, B):
    answer = 0
    
    if A == B:
        return answer
    
    for i in range(len(A) - 1):
        answer += 1
        A = A[-1] + A[:-1]
        if A == B:
            return answer 
    
    return -1
  
  
  ### deque 사용
  
from collections import deque

def solution(A, B):
    answer = 0
    
    a, b = deque(A), deque(B)
    for answer in range(0, len(A)):
        if a == b:
            return answer
        a.rotate(1)
    
    return -1
