def solution(arr):
    answer = 0

    for i in arr:
        answer += i

    answer /= len(arr)

    return answer