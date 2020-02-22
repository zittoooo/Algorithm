def solution(x):
    sum = 0
    input = x

    while True:
        sum += x % 10
        x //= 10
        if x == 0:
            break
    if input % sum != 0:
        return False

    else:
        return True