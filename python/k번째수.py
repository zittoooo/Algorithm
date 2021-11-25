def solution(array, commands):
    answer = []
    for command in(commands):
        i,j,k = command
        arr = list(sorted(array[i-1:j]))
        answer.append(arr[k-1])
    return answer